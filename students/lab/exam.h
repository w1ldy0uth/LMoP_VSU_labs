#include <string>
#include <iostream>

struct Exam {
    std::string name;
    unsigned int mark;
};

Exam readExam(std::string&);
void writeExam(Exam);