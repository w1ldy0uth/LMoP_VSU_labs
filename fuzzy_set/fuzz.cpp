#include "fuzz.h"
#include <iostream>

void init(TList &head) {
    head = nullptr;
}

void print(TList head) {
    TList p = head;
    std::cout << "(";
    while(p->next != nullptr) {
        std::cout << p->data << ": " << p->mu << ", ";
        p = p->next;
    }
    std::cout << p->data << ": " << p->mu << ")\n";
}

void clear(TList &head) {
    while (!isEmpty(head)) {
        deleteFromHead(head);
    }
}

bool isEmpty(TList head) {
    return head == nullptr;
}

bool inSet(TList head, int value) {
    TList p = head;
    bool flag = false;
    while(p != nullptr) {
        if(p->data == value) {
            flag = true;
            break;
        }
        p = p->next;
    }
    return flag;
}

void addToHead(TList &head, int value, double ch) {
    TList p = new Node;
    p->data = value;
    p->mu = ch;
    p->next = head;
    head = p;
}

void addAfterNode(TList pNode, int value, double ch) {
    TList p = new Node;
    p->data = value;
    p->mu = ch;
    p->next = pNode->next;
    pNode->next = p;
}

void addToSet(TList &head, int data, double mu) {
    if(inSet(head, data) || mu > 1 || mu < 0)
        return;
    if(isEmpty(head) || head->data > data)
        addToHead(head, data, mu);
    else {
        TList pos = findPlace(head, data);
        addAfterNode(pos, data, mu);
    }
}
void deleteFromHead(TList &head) {
    TList p = head;
    head = head->next;
    p->next = nullptr;
    delete p;
    p = nullptr;
}

void deleteAfterNode(TList pNode) {
    TList p = pNode->next;
    if (p != nullptr) {
        pNode->next = p->next;
        p->next = nullptr;
        delete p;
        p = nullptr;
    }
}

void createByOrder(TList &head, std::string path) {
    std::ifstream input(path);
    int data;
    double mu;
    while(!input.eof()) {
        input >> data;
        input >> mu;
        addToSet(head, data, mu);
    }
    input.close();
}

TList findPlace(TList head, int value) {
    TList p = head;
    while(p->next != nullptr && p->next->data<value)
        p = p->next;
    return p;
}

TList findCorrectPlace(TList head, int value) {
    TList p = head;
    while(p->data != value)
        p = p->next;
    return p;
}

TList unification(TList head1, TList head2) {
    TList res;
    TList p1 = head1, p2 = head2;
    init(res);
    while(p1 != nullptr) {
        addToSet(res, p1->data, p1->mu);
        p1 = p1->next;
    }
    while(p2 != nullptr) {
        if(!inSet(res, p2->data))
            addToSet(res, p2->data, p2->mu);
        else {
            TList node = findCorrectPlace(res, p2->data);
            node->mu = p2->mu < node->mu ? p2->mu : node->mu;
        }
        p2 = p2->next;
    }
    return res;
}

TList intersection(TList head1, TList head2) {
    TList res, p = head1;
    init(res);
    while(p != nullptr) {
        if(inSet(head2, p->data)) {
            TList node = findCorrectPlace(head2, p->data);
            double mu = p->mu > node->mu ? p-> mu : node->mu;
            addToSet(res, p->data, mu);
        }
        p = p->next;
    }
    return res;
}