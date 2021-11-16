#include "name.h"

Name readName(std::string& str) {
    Name name;
    std::string s;
    size_t i = 0;

    while (str[i] != ' ') i++;
    s = str.substr(0, i);
    str = str.erase(0, i + 1);
    name.lName = s;
    i = 0;

    while (str[i] != ' ') i++;
    s = str.substr(0, i);
    str = str.erase(0, i + 1);
    name.fName = s;
    i = 0;

    while (str[i] != ' ') i++;
    s = str.substr(0, i);
    str = str.erase(0, i + 1);
    name.mName = s;
    i = 0;

    return name;
}

void writeName(Name name) {
    std::cout << name.lName << " " << name.fName << " " << name.mName << " ";
}