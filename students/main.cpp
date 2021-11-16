#include "list.h"
#include <iostream>
#include <string>
#include <fstream>

pNode read(std::string filePath) {
    pNode list;
    init(list);
    std::ifstream inp(filePath);
    std::string tmp;
    while(!inp.eof()) {
        std::getline(inp, tmp);
        addToHead(list, readData(tmp));
    }
    return list;
}

void write(pNode list) {
    pNode p = list;
    while(p != nullptr) {
        writeData(p->data);
        p = p->next;
    }
    std::cout << "\n";
}

int main() {
    pNode list = read("/home/ivan/CLionProjects/LMPlab3/input.txt");
    write(list);
    transfer(list);
    write(list);
    clear(list);
    return 0;
}
