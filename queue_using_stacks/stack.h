#include <iostream>

struct Node {
    int data;
    Node *next;
};

typedef Node* TStack;

void init(TStack&);
void print(TStack);
void clear(TStack&);

bool isEmpty(TStack);

int peek(TStack);
void push(TStack&, int);
void pop(TStack&);
