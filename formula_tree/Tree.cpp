#include "Tree.h"
#include "Stack.h"

Tree::Tree() {
    root = nullptr;
}

Tree::~Tree() {
    clear();
}

void Tree::clear(pTree& node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
        node = nullptr;
    }
}

void Tree::clear() {
    clear(root);
}

void Tree::print(std::string prefix, pTree node, bool isLeft) {
    if (node) {
        print(prefix + "\t", node->right, true);
        std::cout << prefix;
        std::cout << "─ ";
        std::cout << node->val << std::endl;
        print(prefix + "\t", node->left, false);
    }
}

void Tree::print() {
    print("", root, false);
}

void Tree::stringToTree(std::string postfix) {
    TreeStack st;
    pTree temp_tree1, temp_tree2;
    for (char i : postfix) {
        if (!(i == '+' || i == '-' || i == '*')) {
            root = new TreeNode(i);
            st.push(root);
        }
        else {
            root = new TreeNode(i);
            temp_tree1 = st.pop();
            temp_tree2 = st.pop();
            root->right = temp_tree1;
            root->left = temp_tree2;
            st.push(root);
        }
    }
}

Tree::pTree Tree::copyInOrder(pTree _root) {
    if (_root == nullptr)
        return nullptr;
    else {
        pTree tmp = new TreeNode;
        tmp->val = _root->val;
        tmp->right = copyInOrder(_root->right);
        tmp->left = copyInOrder(_root->left);
        return tmp;
    }
}

void Tree::openBrackets() {
    openBrackets(root);
}

void Tree::openBrackets(pTree _root) {
    pTree copyTree1, copyTree3;
    pTree copyTree2, copyTree4;

    if (!_root)
        return;

    if (_root->left && (_root->left->val == '-' || _root->left->val == '+')) {
        char sign = _root->left->val;

        copyTree1 = copyInOrder(_root->right);
        delete _root->right->left;
        delete _root->right->right;

        copyTree2 = copyInOrder(_root->left->right);
        delete _root->left->right;

        _root->left->val = '*';
        _root->val = sign;
        _root->right->val = '*';
        _root->right->right = copyTree1;
        _root->right->left = copyTree2;
        _root->left->right = copyInOrder(copyTree1);

        openBrackets(_root);
        openBrackets(_root->left);
        openBrackets(_root->right);
    }
    else if (_root->right && (_root->right->val == '-' || _root->right->val == '+')) {
        char sign = _root->right->val;

        copyTree3 = copyInOrder(_root->left);
        delete _root->left->left;
        delete _root->left->right;

        copyTree4 = copyInOrder(_root->right->left);
        delete _root->right->left;

        _root->left->val = '*';
        _root->val = sign;
        _root->right->val = '*';
        _root->left->left = copyTree3;
        _root->left->right = copyTree4;
        _root->right->left = copyInOrder(copyTree3);

        openBrackets(_root);
        openBrackets(_root->left);
        openBrackets(_root->right);
    }
    else {
        openBrackets(_root->left);
        openBrackets(_root->right);
    }
}

void Tree::multiplyBrackets(pTree _root) {
    if (_root->val == '*') {
        openBrackets(_root->left);
        openBrackets(_root);
        openBrackets(_root->right);
    }
}

void Tree::multiplyBrackets() {
    multiplyBrackets(root);
}

std::string Tree::treeToString(pTree _root) {
    std::string res;
    if(_root) {
        res += " ";
        res += treeToString(_root->left);
        res+= _root->val;
        res += treeToString(_root->right);
        res += " ";
    }
    return res;
}

std::string Tree::treeToString() {
    return treeToString(root);
}
