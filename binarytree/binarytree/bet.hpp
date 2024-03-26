//  BY OSCAR NARANJO
// NOVEMBER 2, 2022
// COP4530

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isOperand(string expression);
int checkPrecedence(string expression);

template<typename T>
BET<T>::BET()
{
    root = nullptr;
}

template<typename T>
 BET<T>::BET(const string postfix) : root{ nullptr }
{
     root = new BinaryNode;
    //Call buildFromPostfix
    buildFromPostfix(postfix);
}

// One-parameter constructor, where
// parameter "postfix" is string containing a postfix expression.The tree
// should be built based on the postfix expression.Tokens in the postfix
// expression are separated by spaces.


//Copy Constructor makes appropriate deep copy of the tree
template <typename T>
 BET<T>::BET(const BET<T>& rhs) : root{ nullptr } 
 {
    root = clone(rhs.root);
}

//Destructor cleans up all dynamic space in the tree
template <typename T>
 BET<T>::~BET<T>() 
{
        makeEmpty(root); 
}

//Assignment Operator
template <typename T>
const BET<T>& BET<T>::operator=(const BET<T>& rhs) {
  
    root = clone(rhs.root);
    return *this;
}

// Parameter "postfix" is
// string containing a postfix expression.The tree should be built based on
// the postfix expression.Tokens in the postfix expression are separated
// by spaces.If the tree contains nodes before the function is called, you
// need to first delete the existing nodes.Return true if the new tree is built
// successfully.Return false if an error is encountered.
template <typename T>
 bool BET<T>::buildFromPostfix(const string postfix) {
    
    string temp;
    string temp2;
    stack<BinaryNode*> myStack;
    stringstream s(postfix);

    int counter1 = 0;
    int counter2 = 0;

    if (postfix.empty() == true) {
        cout << "Wrong postfix expression" << endl;
        root = nullptr;
        return false;
    }

    if (empty() == false)
        makeEmpty(root);

    bool flag = false;

    while (s >> temp) {
        BinaryNode* myNode = new BinaryNode(temp, nullptr, nullptr); // create a node to hold tokenized input

        if (isOperand(temp) == true) { // take all operands in and pushs to stack
            counter1++;
            myStack.push(myNode);	// push new node to stack
        }
        else if (checkPrecedence(temp) != 0) {				// else if it is an operator (has precedence > 0)
            counter2++;
            if (counter1 == counter2) {
                cout << "Wrong postfix expression" << endl;
                root = nullptr;
                return false;
            }
            else {
                myNode->left = myStack.top();
                myStack.pop();
                myNode->right = myStack.top();
                myStack.pop();
                myStack.push(myNode);
            }
        }
    }

    if (counter1 != counter2)
        root = myStack.top();

    if (myStack.empty() == true) { // this stops a crash from trying to pop from empty stack
        cout << "Wrong postfix expression" << endl;
        root = nullptr;
        return false;
    }

    return true;
 
    
}

// Print out the infix expression.Should do
// this by making use of the private (recursive)version
template <typename T>
 void BET<T>::printInfixExpression() {
    printInfixExpression(root);
    cout << endl;  
}

// Print the postfix form of the expression.
// Use the private recursive function to help
template <typename T>
 void BET<T>::printPostfixExpression() {
    printPostfixExpression(root);
    cout << endl;  
}

// Return the number of nodes in the tree (using the private
// recursive function)
template <typename T>
 size_t BET<T>::size() {
    return size(root);
}

// Return the number of leaf nodes in the tree. (Use
// the private recursive function to help)
template <typename T>
 size_t BET<T>::leaf_nodes() {
    return leaf_nodes(root);
}

// return true if the tree is empty.Return false otherwise
template <typename T>
 bool BET<T>::empty() {
    if (root == nullptr)
        return true;
    else return false;
}


//Member function IsOperator returns whether a string is an operator
template <typename T>
bool BET<T>::IsOperator(const string& s) {
    return(s == "+" || s == "-" || s == "/" || s == "*");
}
//Member function IsOperand checks string for operand case
template <typename T>
bool BET<T>::IsOperand(const string& s) {
    if (s.length() == 1) {
        char c = s[0];
        return((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c == '_'));
    }
    else return true;
}


// print to the standard
// output the corresponding infix expression.Note that you may need to
// add parentheses depending on the precedence of operators.You
// should not have unnecessary parentheses.
template <typename T>
 void BET<T>::printInfixExpression(BET<T>::BinaryNode* n)
 {
    if (n != nullptr) {
        //If Node is an operator and it is not the root node
        if (IsOperator(n->element) && n != root)
            cout << "( ";
        printInfixExpression(n->left);
        cout << n->element << " ";
        printInfixExpression(n->right);
        if (IsOperator(n->element) && n != root)
           cout << ") ";
    }
    
}

// print to the standard output the corresponding postfix expression.
template <typename T>
 void BET<T>::printPostfixExpression(BET<T>::BinaryNode* n) 
 {
     if (size(n) == 0) // prevent segfault on empty tree
         return;
     else if (root->left == nullptr && root->right == nullptr)
         cout << root->element << endl;
     else {
         printPostfixExpression(n->right); // print right nodes first
         printPostfixExpression(n->left); // print left nodes next
         cout << n->element << " ";
     }
}

// delete all nodes in the subtree pointed to by t.
template <typename T>
 void BET<T>::makeEmpty(BinaryNode*& t) {
    
    if (t != nullptr) {
        if (t->left != nullptr)
            makeEmpty(t->left);
        if (t->right != nullptr)
            makeEmpty(t->right);
        delete t;   
    }
    t = nullptr;
}

//Clones a given tree by creating new nodes
template <typename T>
 typename BET<T>::BinaryNode* BET<T>::clone(BET<T>::BinaryNode* t) const 
 {
    if (t == nullptr)
        return nullptr;
    else 
        return new BinaryNode{ t->element,clone(t->left),clone(t->right) };
}


// return the number of nodes in the subtree pointed to by t.
template <typename T>
 size_t BET<T>::size(BET<T>::BinaryNode* t) 
 {
     if (t == nullptr)
         return 0;
     else
         return(size(t->left) + size(t->right) + 1);
}

// return the number of leaf nodes in the subtree pointed to by t.
template <typename T>
 size_t BET<T>::leaf_nodes(BET<T>::BinaryNode* t) 
 {
     if (t == nullptr)
         return 0;
     else if ((t->left == nullptr) && (t->right == nullptr))
         return 1;
     else
         return (leaf_nodes(t->left) + leaf_nodes(t->right));
}

int checkPrecedence(const string str) 
{ 
    if (str == "(" || str == ")")
        return (3);
    else if (str == "*" || str == "/")
        return (2);
    else if (str == "+" || str == "-")
        return (1);
    else
        return 0;
}

bool isOperand(const string str)
{ 
    for (int i = 0; i < int(str.size()); i++)
        if (isalnum(str[i]) == false) // check if alphanumeric 
            return false;
    return true;
}
