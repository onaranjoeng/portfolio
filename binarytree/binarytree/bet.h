//  BY OSCAR NARANJO
// NOVEMBER 2, 2022
// COP4530

#ifndef BET_H
#define BET_H
#include <iostream>
#include <sstream>  
#include <stack>
using namespace std;

template <typename T>
class BET {
private:

    struct BinaryNode {
        string element;
        BinaryNode* left;
        BinaryNode* right;

        //ConstructorS
        BinaryNode() : left{ nullptr }, right{ nullptr }{}
        BinaryNode(const std::string& elm, BinaryNode* ll, BinaryNode* rr)
            : element{ elm }, left{ ll }, right{ rr }{}
    };
public:
    BET();  //default 
    BET(const string postfix);
    BET(const BET&);    //copy
    ~BET(); //destructor

    bool buildFromPostfix(const string postfix);
    const BET& operator=(const BET&);  // assign operator

    void printInfixExpression();    //print infix
    void printPostfixExpression();  //print postfix


    size_t size();  //num nodes in tree
    size_t leaf_nodes();    //num leaf nodes in tree
    bool empty();   //tree is empty

private:

    
    BinaryNode* root;   //Root node

    bool IsOperator(const string& s);
    bool IsOperand(const string& s);
    
    void printInfixExpression(BinaryNode* n);   //print infix
    void makeEmpty(BinaryNode*& t); //delete all nodes in subtree
    void printPostfixExpression(BinaryNode* n);

    BinaryNode* clone(BinaryNode* t) const;   //clone all nodes,
    size_t size(BinaryNode* t); //num nodes in subtree of t
    size_t leaf_nodes(BinaryNode* t);   //num leafnodes

};
#include "bet.hpp"
#endif
