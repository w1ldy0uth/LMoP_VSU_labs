#include "stack.h"

class Queue {
    TStack s1;
    TStack s2;

    void shift();

public:
    Queue();
    ~Queue();

    bool is_Empty();
    void enqueue(int);
    void dequeue();
    int getFront();
};
