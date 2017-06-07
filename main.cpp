#include <iostream>
#include <algorithm>
#include "BTree.h"

//#define DEBUG
using namespace std;

template<typename T>
void show(vector<Node<T> *> list) {
    for (Node<T> *node:list) {
        char c = node->getData()->c;
        double p = node->getData()->power;
        if (c == '\0')continue;
        cout << c << ":" << p << endl;
    }
    cout << endl;
}

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
    class Case {
    public:
        char c;
        double power;

        Case(char ca, double po) : c(ca), power(po) {}
    };
    vector<Node<Case> *> list;

    Node<Case> *c1 = new Node<Case>(Case('A', 0.1));
    Node<Case> *c2 = new Node<Case>(Case('B', 0.2));
    Node<Case> *c3 = new Node<Case>(Case('C', 0.3));
    Node<Case> *c4 = new Node<Case>(Case('D', 0.4));

    //c1    c2      c3      c4
    //a     b       c       d
    //0.1   0.2     0.3     0.4
    Node<Case> *c5 = new Node<Case>(c1, c2, Case('\0', c1->getData()->power + c2->getData()->power));

    //c5    c3      c4
    //ab    c       d
    //0.3   0.3     0.4
    Node<Case> *c6 = new Node<Case>(c5, c3, Case('\0', c5->getData()->power + c3->getData()->power));

    //c4    c6
    //d     abc
    //0.4   0.6
    Node<Case> *root = new Node<Case>(c4, c6, Case('\0', c4->getData()->power + c6->getData()->power));


    /*              root
            D                   O
                        0               C
                    A       B
        先序遍历结果：DABC
        中序遍历结果：
        后序遍历结果：
     */

    show(root->preOrder());
    //结果符合DABC

    show(root->inOrder());
    //结果符合DABC

    show(root->postOrder());
    //结果符合DABC

    //综上，霍夫曼编码树符合要求
#endif
    return 0;
}