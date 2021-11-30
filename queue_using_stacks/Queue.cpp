#include "Queue.h"

Queue::Queue() {
    init(s1);
    init(s2);
}

Queue::~Queue() {
    clear(s1);
    clear(s2);
}

bool Queue::is_Empty() {
    return (isEmpty(s1) && isEmpty(s2));
}

void Queue::enqueue(int value) {
    push(s1, value);
}

void Queue::dequeue() {
    shift();
    pop(s2);
}

int Queue::getFront() {
    shift();
    return peek(s2);
}

void Queue::shift() {
    if (!isEmpty(s2))
        return;
    while(!isEmpty(s1)) {
        push(s2, peek(s1));
        pop(s1);
    }
}