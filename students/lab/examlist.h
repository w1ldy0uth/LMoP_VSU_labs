#include "exam.h"
#include <string>

struct ExamNode {
    Exam exam;
    ExamNode* next;
};

typedef ExamNode* pExam;

void init(pExam&);
bool isEmpty(pExam);
void addToHead(pExam&, Exam);
void addAfterNode(pExam, Exam);
void addByOrder(pExam&, Exam);

pExam readExamList(std::string&);
void writeExamList(pExam);