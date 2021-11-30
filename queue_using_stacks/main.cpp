#include "Queue.h"
#include <iostream>
#include <fstream>

int main() {
    std::ifstream input("/home/ivan/CLionProjects/lab3lmp/input.txt");
    Queue q;
    int tmp;
    while(!input.eof()) {
        input >> tmp;
        q.enqueue(tmp);
    }
    input.close();

    std::cout << q.getFront() << "\n";
    q.dequeue();
    std::cout << q.getFront() << "\n";
    q.dequeue();
    q.dequeue();
    std::cout << q.getFront() << "\n";

    return 0;
}
