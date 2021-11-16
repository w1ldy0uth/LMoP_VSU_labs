#include "name.h"
#include "examlist.h"
#include <string>
#include <iostream>

struct Data {
    Name name;
    int course;
    int group;
    std::string type;
    pExam exams;
};

Data readData(std::string);
void writeData(Data);