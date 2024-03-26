// BY OSCAR NARANJO
// OCTOBER 14, 2022
// COP4530

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include "stack.h"

using namespace std;
using namespace cop4530;

struct Deques {

    string input;   // input taken as a string
    int precedence; // to keep track of math

    Deques() : input(""), precedence(0) {}
    Deques(string s) : input(s) 
    {
        // order the precedence based on PEMDAS
        if (input.length() == 1)
        {
            char c = input[0];
            if (c == '+' || c == '-')
                precedence = 2;
            else if (c == '*' || c == '/')
                precedence = 3;
            else if (c == '(' || c == ')')
                precedence = 1;
            else precedence = 0;
        }
        else
            precedence = 0; // just incase it fails
    }
};

//Function prototypes
void PrintError(std::string error);
void infix2postfix(std::vector<Deques> input);
void infix2infix(std::vector<Deques> input);
bool IsOperator(char c);
bool IsIdentifier(string s);
bool IsOperand(char c);
void CalculatePostfix(std::vector<Deques> exp);
std::string CalculateValues(Deques operand1, Deques operand2, Deques oper);


int main()
{
    char c; 
    std::vector<Deques> input;  
    string exp; 
    bool running = true; 

    while (running) {
        cout << "Enter in a mathematical expression (type end to exit):  ";

        while (cin.get(c) && running) {
            if (exp == "end") {
                running = false;
                break;
            }
            else {
                if (c == '\n') {
                    // push back the expression string to vector, clear
                    input.push_back(exp);
                    infix2infix(input);
                    infix2postfix(input);
                    exp = "";
                    input.clear();
                    cout << "Enter in a mathematical expression: ";
                }
                else if (c == ' ') {
                    // put expressino to vector on space
                    input.push_back(Deques(exp));
                    exp = "";
                }
                else if (c == '(' || c == ')') {
                    // push parenthesis to vector
                    string x;
                    x += c;
                    input.push_back(Deques(x));
                }
                else if (c == '\0') {
                    running = false;
                }
                else {
                    //put string together
                    exp += c;
                    
                }
            }
        }
        running = false;
    }

    return (EXIT_SUCCESS);
}

// prints an error message
void PrintError(std::string error) 
{
    cout << error << std::endl;
}

//returns whether a string is an operator
bool IsOperator(string token)
{
    return(token == "+" || token == "-" || token == "/" || token == "*");
}

// checks whether an operator is a number or letter
bool IsIdentifier(string token)
{
    for (std::string::iterator it = token.begin(); it != token.end(); ++it) {
        char c = *it;
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == '_')) {
            return false;
        }
    }
    return true;
}

// returns whether or not a string is an operand
bool IsOperand(string token) 
{
   
    if (token.length() == 1) {
        char c = token[0];
        return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c == '_'));
    }
    else {
        return true;
    }
}

// infix to post using ESDGAR DIJSKTRA'S SHUNTING YARD ALGORITHM
void infix2postfix(std::vector<Deques> input)
{
    // ESDGAR DIJSKTRA'S SHUNTING YARD ALGORITHM
    Stack<Deques> operators;
    Deques lastInput;
    std::vector<Deques> result;

    // big loop through the string
    for (std::vector<Deques>::iterator itr = input.begin(); itr != input.end(); ++itr) {
        Deques op = *itr;   //space separated string

        // print the string if it is an operand
        if (IsOperand(op.input))
        {
            cout << op.input << " ";
            if (op.input.length() > 0)
                result.push_back(op.input);
        }

        // if input is "(" push it into stack
        if (op.input == "(") {
            operators.push(op);
        }
        // if input is a token
        else if (IsOperator(op.input))
        {
            // if  input is an operator, print top of stack to output and pop until empty
            while (!operators.empty() && operators.top().input != "(" && (operators.top().precedence >= op.precedence)) {
                cout << operators.top().input << " ";
                result.push_back(operators.top().input);
                operators.pop(); // pop operands
            }
            operators.push(op); // push operands 
        }
        else if (op.input == ")")
        {
            if (IsOperator(lastInput.input))
                PrintError("Last input cannot be an operator!");
            else {
                //  print top of stack and output and pop stack until empty
                while (!operators.empty() && operators.top().input != "(") {
                    cout << operators.top().input << " "; // seperate
                    result.push_back(operators.top().input); // push bacl
                    operators.pop();  // pop equation out of stack
                }
                operators.pop(); // take other operators out
            }
        }
        lastInput = op;  // save to use later
    }

    //At end of input, if last input was an operator or ( report error
    if (IsOperator(lastInput.input) || lastInput.input == "(") {
        PrintError("Last input was operator!: " + lastInput.input);
    }
    else {
        // print the stack to top and pop until empty
        while (!operators.empty()) {
            if (operators.top().input == "(") {
                PrintError("Error");
                break;
            }
            cout << operators.top().input << " ";
            result.push_back(operators.top().input);
            operators.pop();
        }
        cout << endl;
    }
    // do the math in postfix
    CalculatePostfix(result);
}

// infix notation
void infix2infix(std::vector<Deques> exp)
{
    Stack<string> operand;
    string infix_output;
    bool variable = false;

    for (std::vector<Deques>::iterator itr = exp.begin(); itr != exp.end(); ++itr) {
        Deques input = *itr;
        infix_output += input.input + " ";  // for output expression
    }
    
    cout << "The Infix   Notation is: " << infix_output << endl;
    cout << "The PostFix Notation is: ";
}

// calculate postfix expression
void CalculatePostfix(std::vector<Deques> exp) {
    
    Stack<string> operand;
    string output;
    bool variable = false;

    // loop through input 
    for (std::vector<Deques>::iterator itr = exp.begin(); itr != exp.end(); ++itr) {
        Deques input = *itr;
        output += input.input + " ";  // for output expression

        // if the expression does not contain a numbers
        if (!variable && IsIdentifier(input.input)) {
            // if operand add to stack
            if (IsOperand(input.input)) {
                operand.push(input.input);
            }
            else if (IsOperator(input.input)) {
                // if too few operands
                if (operand.size() < 2) {
                    PrintError("Too few operands");
                }
                else {
                    // pop and calculate
                    Deques oper1 = operand.top();
                    operand.pop();
                    Deques oper2 = operand.top();
                    operand.pop();

                    string result = CalculateValues(oper2, oper1, input.input);
                    operand.push(result);
                    // push result to stack
                }
            }
        }
        else {
            variable = true;
        }
    }
    // if the expression contains only numbers
    if (!variable) 
    {
        if (operand.size() > 1) {
            PrintError("Error, missing operands or operators!");
        }
        else if (operand.size() == 1) {
            cout << "The Result is:  " << operand.top() << endl;
        }
        else 
            cout << "The Postfix evauluation: 0" << endl;
    }
    else {
        cout << "The Result is:  " << output << endl;
    }
}

// take values from a string to double
std::string CalculateValues(Deques operand1, Deques operand2, Deques oper)
{
    std::stringstream stack;
    double left = 0.0, right = 0.0;

    // strings to double
    left = atof(operand1.input.c_str());
    right = atof(operand2.input.c_str());

    //put operators in order and do the math
    if (oper.input == "*")
        left *= right;
    else if (oper.input == "/")
    {
        if (right != 0)
            left /= right;
    }
    else if (oper.input == "+")
        left += right;
    else if (oper.input == "-")
        left -= right;

   
    stack << left;
    return stack.str();
}