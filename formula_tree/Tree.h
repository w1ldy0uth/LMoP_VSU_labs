#pragma once
#include <iostream>

class Tree {
public:
    struct TreeNode {
        char val;
        TreeNode* left;
        TreeNode* right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
    };
    typedef TreeNode* pTree;

private:
    pTree root;

    void print(std::string, pTree, bool);
    void clear(pTree&);
    void openBrackets(pTree);
    void multiplyBrackets(pTree);
    std::string treeToString(pTree);

public:
    Tree();
    ~Tree();

    void clear();
    void print();

    void stringToTree(std::string);
    std::string treeToString();
    pTree copyInOrder(pTree);
    void openBrackets();
    void multiplyBrackets();
};

