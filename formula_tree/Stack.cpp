#include "Stack.h"

Stack::Stack() {
    top = nullptr;
}

Stack::~Stack() {
    clear();
}

void Stack::print() {
    pStack p = top;
    while(p != nullptr) {
        std::cout << p->data << "\n";
        p = p->next;
    }
}

void Stack::clear() {
    while(!isEmpty())
        pop();
}

bool Stack::isEmpty() {
    return top == nullptr;
}

char Stack::peek() {
    return top->data;
}

Stack::pStack Stack::getTop() {
    return top;
}

void Stack::push(char value) {
    pStack p = new Node;
    p->data = value;
    p->next = top;
    top = p;
}

char Stack::pop() {
    char val = peek();
    pStack p = top;
    top = top->next;
    p->next = nullptr;
    delete p;
    p = nullptr;
    return val;
}

TreeStack::TreeStack() {
    top = nullptr;
}

TreeStack::~TreeStack() {
    clear();
}

void TreeStack::clear() {
    while (!isEmpty())
        pop();
}

bool TreeStack::isEmpty() {
    return top == nullptr;
}

TreeStack::Node* TreeStack::getTop() {
    return top;
}

Tree::TreeNode* TreeStack::peek() {
    return top->data;
}

void TreeStack::push(Tree::TreeNode* value) {
    pTStack p = new Node;
    p->data = value;
    p->next = top;
    top = p;
}

Tree::TreeNode* TreeStack::pop() {
    Tree::TreeNode* val = peek();
    pTStack p = top;
    top = top->next;
    p->next = nullptr;
    delete p;
    p = nullptr;
    return val;
}