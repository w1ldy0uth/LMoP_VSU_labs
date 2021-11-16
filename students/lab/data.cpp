#include "data.h"

Data readData(std::string str) {
    Data data;
    std::string s;
    size_t i = 0;

    data.name = readName(str);

    while (str[i] != ' ') i++;
    s = str.substr(0, i);
    str = str.erase(0, i + 1);
    data.course = std::stoi(s);
    i = 0;

    while (str[i] != ' ') i++;
    s = str.substr(0, i);
    str = str.erase(0, i + 1);
    data.group = std::stoi(s);
    i = 0;

    while (str[i] != ' ') i++;
    s = str.substr(0, i);
    str = str.erase(0, i + 1);
    data.type = s;
    i = 0;

    data.exams = readExamList(str);

    return data;
}

void writeData(Data data) {
    writeName(data.name);
    std::cout << data.course << "c " << data.group << "gr " << data.type << " ";
    writeExamList(data.exams);
    std::cout << "\n";
}