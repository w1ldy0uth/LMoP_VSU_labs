/* Special thanks to Nikolay 'L1SP' Serov for public code examples <3 */

#include "Stack.h"
#include "Tree.h"
#include <iostream>
#include <fstream>

bool isOperator(char c) {
    bool flag;
    if (c == '+' || c == '-' || c == '*')
        flag = true;
    else
        flag = false;
    return flag;
}
int checkOperator(char c) {
    int state;
    if (c == '*')
        state = 2;
    else if (c == '+' || c == '-')
        state = 1;
    else
        state = -1;
    return state;
}
std::string infixToPostfix(std::string infix) {
    Stack s;
    std::string postfix;
    for (char i : infix) {
        if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i>='0' && i<='9'))
            postfix += i;
        else if (i == '(')
            s.push(i);
        else if (i == ')') {
            while ((s.getTop()->data != '(') && (!s.isEmpty()))
                postfix += s.pop();
            if (s.getTop()->data == '(')
                s.pop();
        }
        else if (isOperator(i)) {
            if (s.isEmpty())
                s.push(i);
            else {
                if (checkOperator(i) > checkOperator(s.getTop()->data))
                    s.push(i);
                else {
                    while ((!s.isEmpty()) && (checkOperator(i) <= checkOperator(s.getTop()->data)))
                        postfix += s.pop();
                    s.push(i);
                }
            }
        }
    }
    while (!s.isEmpty())
        postfix += s.pop();
    return postfix;
}

int main() {
    std::ifstream input("frm.txt");
    std::string infix;
    input >> infix;
    std::cout << "Original formula\n" << infix << '\n';

    std::string postfix = infixToPostfix(infix);
    std::cout << "\nPostfix formula\n" << postfix << '\n';

    Tree tree;
    tree.stringToTree(postfix);
    std::cout << "\nFormula tree before opening the brackets\n";
    tree.print();
    tree.openBrackets();
    tree.multiplyBrackets();
    std::cout << "\nFormula tree after opening the brackets\n";
    tree.print();
    std::cout << "\nFormula in non-tree view\n" << tree.treeToString() << "\n";
    return 0;
}
