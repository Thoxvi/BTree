//
// Created by Thoxvi on 2017/6/7.
//

#ifndef BTREE_BTREE_H
#define BTREE_BTREE_H

#include <functional>
#include <vector>
#include <iostream>

//必须手动clean释放空间，析构函数屁事不做
template<class T>
class Node {
private:
    Node *leftNode;
    Node *rightNode;
    T *data;

    void preOrderHelper(Node *node, std::vector<Node *> &list);

    void inOrderHelper(Node *node, std::vector<Node *> &list);

    void postOrderHelper(Node *node, std::vector<Node *> &list);

    void heightHelper(Node *node, int n, int &m);

public:
    //带值树
    Node(T d) : leftNode(nullptr), rightNode(nullptr), data(new T(d)) {}

    //带左右节点和值的树
    Node(Node *left, Node *right, T d) : leftNode(left), rightNode(right), data(new T(d)) {}

    ~Node() {};

    //是否为空
    bool isEmpty();

    //简单输出单个节点
    void show();

    //参数确定是否释放空间
    void clean(bool isFree);

    //拆分树，左右和值buff当作参数传入
    void breakMe(Node *leftBuff, Node *rightBuff, T *dataBuff);

    //中序遍历,把排出顺序的值放在一个vector里
    std::vector<Node *> inOrder();

    //前序遍历,同上
    std::vector<Node *> preOrder();

    //后续遍历，同上
    std::vector<Node *> postOrder();

    //计算节点数量
    int size();

    //计算高度
    int height();


    //Getter && Setter
    Node *getLeftNode() {
        return leftNode;
    }

    void setLeftNode(Node *leftNode) {
        Node::leftNode = leftNode;
    }

    Node *getRightNode() {
        return rightNode;
    }

    void setRightNode(Node *rightNode) {
        Node::rightNode = rightNode;
    }

    T *getData() {
        return data;
    }

    void setData(T *data) {
        Node::data = data;
    }

};

template<class T>
void Node<T>::breakMe(Node *leftBuff, Node *rightBuff, T *dataBuff) {
    *leftBuff = *leftNode;
    *rightBuff = *rightNode;
    *dataBuff = *getData();
    this->clean(false);
}

template<class T>
void Node<T>::clean(bool isFree) {
    if (isFree) {
        if (leftNode != nullptr)delete leftNode;
        if (rightNode != nullptr)delete rightNode;
        if (data != nullptr)delete data;
    }
    leftNode = nullptr;
    rightNode = nullptr;
    data = nullptr;
}

template<class T>
bool Node<T>::isEmpty() {
    if (leftNode != nullptr)return false;
    if (rightNode != nullptr)return false;
    return nullptr == data;
}

template<class T>
void Node<T>::show() {
    std::cout << *data << std::endl;
}

template<class T>
std::vector<Node<T> *> Node<T>::preOrder() {
    std::vector<Node *> list;
    preOrderHelper(this, list);
    return list;
}

template<class T>
void Node<T>::preOrderHelper(Node *node, std::vector<Node *> &list) {
    if (node != nullptr) {
        list.push_back(node);
        node->preOrderHelper(node->leftNode, list);
        node->preOrderHelper(node->rightNode, list);
    }
}

template<class T>
std::vector<Node<T> *> Node<T>::inOrder() {
    std::vector<Node *> list;
    inOrderHelper(this, list);
    return list;
}

template<class T>
void Node<T>::inOrderHelper(Node *node, std::vector<Node *> &list) {
    if (node != nullptr) {
        node->inOrderHelper(node->leftNode, list);
        list.push_back(node);
        node->inOrderHelper(node->rightNode, list);
    }
}

template<class T>
std::vector<Node<T> *> Node<T>::postOrder() {
    std::vector<Node *> list;
    postOrderHelper(this, list);
    return list;
}

template<class T>
void Node<T>::postOrderHelper(Node *node, std::vector<Node *> &list) {
    if (node != nullptr) {
        node->postOrderHelper(node->leftNode, list);
        node->postOrderHelper(node->rightNode, list);
        list.push_back(node);
    }
}

template<class T>
int Node<T>::size() {
    if (isEmpty())
        return 0;
    return postOrder().size();
}

template<class T>
int Node<T>::height() {
    int n = 0, m = 0;
    heightHelper(this, n, m);
    return m;
}

template<typename T>
void Node<T>::heightHelper(Node *node, int n, int &m) {
    if (node != nullptr) {
        node->heightHelper(node->leftNode, ++n, m);
        n--;
        node->heightHelper(node->rightNode, ++n, m);
        n--;
    } else {
        if (n > m)m = n;
    }
}


#endif //BTREE_BTREE_H
