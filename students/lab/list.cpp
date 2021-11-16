#include "list.h"

void init(pNode& head) {
    head == nullptr;
}

void clear(pNode& head) {
    while(!isEmpty(head))
        deleteFromHead(head);
}

bool isEmpty(pNode head) {
    return head == nullptr;
}

pNode findPlace(pNode head, pNode toFind) {
    pNode res, p = head;
    while(p != nullptr) {
        if(p->next == toFind) {
            res = p;
        }
        p = p->next;
    }
    return res;
}

void addToHead(pNode& head, Data data) {
    pNode p = new Node;
    p->data = std::move(data);
    p->next = head;
    head = p;
}

void addAfterNode(pNode node, Data data) {
    pNode p = new Node;
    p->data = std::move(data);
    p->next = node->next;
    node->next = p;
}

void deleteFromHead(pNode& head) {
    pNode p = head;
    head = head->next;
    p->next = nullptr;
    delete p;
    p = nullptr;
}

void deleteAfterNode(pNode node) {
    pNode p = node->next;
    if (p != nullptr) {
        node->next = p->next;
        p->next = nullptr;
        delete p;
        p = nullptr;
    }
}

void transfer(pNode& head) {
    pNode p = head;
    while(p != nullptr) {
        pExam curr = p->data.exams;
        bool flag = true;
        while(curr != nullptr) {
            if(curr->exam.mark < 3) {
                flag = false;
            }
            curr = curr->next;
        }
        if(flag) {
            if (p->data.course != 4 && p->data.course != 6)
                p->data.course++;
            else {
                if(p == head) {
                    deleteFromHead(head);
                }
                else {
                    pNode k = p;
                    p = p->next;
                    deleteAfterNode(findPlace(head, k));
                }
            }
        }
        p = p->next;
    }
}