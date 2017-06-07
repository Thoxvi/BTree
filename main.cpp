#include <iostream>
#include "BTree.h"

#define DEBUG
using namespace std;

int main() {
#ifdef DEBUG
    //二叉树测试代码
    Node<int> *root = new Node<int>(5);
    Node<int> *left = new Node<int>(1);
    Node<int> *right = new Node<int>(6);

    right->setRightNode(new Node<int>(8));
    left->setLeftNode(new Node<int>(0));

    root->setLeftNode(left);
    root->setRightNode(right);

    for (Node<int> *node : root->preOrder()) {
        node->show();
    }
    cout << endl;

    for (Node<int> *node : root->inOrder()) {
        node->show();
    }
    cout << endl;

    for (Node<int> *node : root->postOrder()) {
        node->show();
    }
    cout << endl;

    cout << "size:" << root->size() << endl;
    cout << "hight:" << root->height() << endl;
#endif

#ifndef DEBUG
    //正式代码
    





#endif
    return 0;
}