#include "examlist.h"

void init(pExam& head) {
    head = nullptr;
}

bool isEmpty(pExam head) {
    return head == nullptr;
}

void addToHead(pExam& head, Exam exam) {
    pExam p = new ExamNode;
    p->exam = exam;
    p->next = head;
    head = p;
}

void addAfterNode(pExam node, Exam exam) {
    pExam p = new ExamNode;
    p->exam = exam;
    p->next = node->next;
    node->next = p;
}

void addByOrder(pExam& head, Exam exam) {
    pExam tail;
    if(isEmpty(head)) {
        addToHead(head, exam);
        tail = head;
    }
    else {
        addAfterNode(tail, exam);
        tail = tail->next;
    }
}

pExam readExamList(std::string& str) {
    pExam examlist;
    init(examlist);
    for(size_t i = 0; i < 5; ++i) {
        addByOrder(examlist, readExam(str));
    }
    return examlist;
}

void writeExamList(pExam head) {
    pExam p = head;
    while(p != nullptr) {
        writeExam(p->exam);
        p = p->next;
    }
}