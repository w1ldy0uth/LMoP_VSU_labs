#include "fuzz.h"
#include <iostream>
#include <string>

int main() {
    const std::string path1 = "data/fuzzy1.txt";
    const std::string path2 = "data/fuzzy2.txt";

    TList set1;
    init(set1);
    createByOrder(set1, path1);
    TList set2;
    init(set2);
    createByOrder(set2, path2);

    std::cout << "First set: ";
    print(set1);
    std::cout << "Second set: ";
    print(set2);

    TList iset = intersection(set1, set2);
    std::cout << "\nIntersection of sets: ";
    print(iset);
    TList uset = unification(set1, set2);
    std::cout << "Union of sets: ";
    print(uset);
    return 0;
}
