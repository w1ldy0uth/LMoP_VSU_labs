#include "stack.h"

void init(TStack &top) {
    top = nullptr;
}

void print(TStack top) {
    TStack p = top;
    while(p != nullptr) {
        std::cout << p->data << "\n";
        p = p->next;
    }
}

void clear(TStack &top) {
    while(!isEmpty(top))
        pop(top);
}

bool isEmpty(TStack top) {
    return top == nullptr;
}

int peek(TStack top) {
    return top->data;
}

void push(TStack &top, int value) {
    TStack p = new Node;
    p->data = value;
    p->next = top;
    top = p;
}

void pop(TStack &top) {
    TStack p = top;
    top = top->next;
    p->next = nullptr;
    delete p;
    p = nullptr;
}