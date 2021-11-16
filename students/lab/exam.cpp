#include "exam.h"

Exam readExam(std::string& str) {
    Exam exam;
    std::string s;
    size_t i = 0;

    while (str[i] != ' ') i++;
    s = str.substr(0, i);
    str = str.erase(0, i + 1);
    exam.name = s;
    i = 0;

    while (str[i] != ' ') i++;
    s = str.substr(0, i);
    str = str.erase(0, i + 1);
    exam.mark = std::stoi(s);
    i = 0;

    return exam;
}

void writeExam(Exam exam) {
    std::cout << exam.name << " " << exam.mark << " ";
}