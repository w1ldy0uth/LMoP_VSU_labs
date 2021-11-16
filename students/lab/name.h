#include <string>
#include <iostream>

struct Name {
    std::string lName;
    std::string fName;
    std::string mName;
};

Name readName(std::string&);
void writeName(Name);