#pragma once
#include "Tree.h"
#include <iostream>

class Stack {
    struct Node {
        char data;
        Node* next;
    };
    typedef Node* pStack;

    pStack top;

public:
    Stack();
    ~Stack();

    void print();
    void clear();
    bool isEmpty();

    pStack getTop();
    char peek();
    void push(char);
    char pop();
};

class TreeStack{
    struct Node {
        Tree::TreeNode* data;
        Node* next;
    };
    typedef Node* pTStack;

    pTStack top;

public:
    TreeStack();
    ~TreeStack();

    void clear();
    bool isEmpty();

    pTStack getTop();
    Tree::TreeNode* peek();
    void push(Tree::TreeNode*);
    Tree::TreeNode* pop();
};
