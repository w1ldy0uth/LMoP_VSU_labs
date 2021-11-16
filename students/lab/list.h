#include "data.h"
#include <iostream>

struct Node {
    Data data;
    Node* next;
};

typedef Node* pNode;

void init(pNode&);
void clear(pNode&);

bool isEmpty(pNode);
pNode findPlace(pNode, pNode);

void addToHead(pNode&, Data);
void addAfterNode(pNode, Data);

void deleteFromHead(pNode&);
void deleteAfterNode(pNode);

void transfer(pNode&);