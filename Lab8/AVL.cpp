//
//  AVL.cpp
//  Lab8
//
//  Created by Cam on 11/25/18.
//  Copyright © 2018 Cameron Brown. All rights reserved.
//

#include "AVL.h"

AVL :: AVL() {
    root = nullptr;
}
AVL :: ~AVL() {
    clear();
}

NodeInterface* AVL :: getRootNode() const {
    return root;
}
bool AVL :: add(int val) {
    if(root == nullptr) {
        Node* newRoot = new Node(val);
        root = newRoot;
        return true;
    }
    else if(addHelper(this->root, val)) {
        return true;
    }
    else {
        return false;
    }
}

bool AVL :: addHelper(Node* &T, int val) {
    if(T == nullptr) {
        T = new Node(val);
        return true;
    }
    else if(T->data < val) {
        return addHelper(T->rightChild, val);
    }
    else if(T->data > val) {
        return addHelper(T->leftChild, val);
    }
    else {
        return false;
    }
}

bool AVL :: remove(int val) {
    return removeHelper(root, val);
}

bool AVL :: removeHelper(Node* &T, int val) {
    if(T == nullptr) {
        return false;
    }
    else if(val == T->data) {
        if(T->leftChild == nullptr && T->rightChild == nullptr) {
            Node* tempNode = T;
            T = nullptr;
            delete tempNode;
            return true;
        }
        if (T->rightChild != nullptr && T->leftChild == nullptr) {
            Node* tempNode = T;
            T = T->rightChild;
            delete tempNode;
            return true;
        }
        if (T->rightChild == nullptr && T->leftChild != nullptr) {
            Node* tempNode = T;
            T = T->leftChild;
            delete tempNode;
            return true;
        }
        else {
            T->data = traverseTree(T->leftChild);
            return removeHelper(T->leftChild, T->data);
        }
    }
    else if(val < T->data) {
        return removeHelper(T->leftChild, val);
    }
    else {
        return removeHelper(T->rightChild, val);
    }
}

int AVL :: traverseTree(Node *T) {
    if (T == nullptr) {
        return -1;
    }
    int currVal = T->data;
    Node* left = T->leftChild;
    if (left != nullptr) {
        int leftVal = traverseTree(left);
        if (leftVal > currVal) {
            currVal = leftVal;
        }
    }
    
    Node* right = T->rightChild;
    if (right != nullptr) {
        int rightVal = traverseTree(right);
        if (rightVal > currVal) {
            currVal = rightVal;
        }
    }
    return currVal;
}
void AVL :: clear() {
    clearHelper(root);
    root = nullptr;
}

void AVL :: clearHelper(Node* T) {
    if(T == nullptr) {
        return;
    }
    else if(T->leftChild != nullptr) {
        clearHelper(T->leftChild);
    }
    else if(T->rightChild != nullptr) {
        clearHelper(T->rightChild);
    }
    delete T;
    return;
}

void AVL :: rotateLeft(Node *&T){
    
}
void AVL :: rotateRight(Node *&T){
    
}


void AVL :: rebalance(Node *T){
    
}

void AVL :: updateHeight(Node *T) {
    if(T->leftChild && T->rightChild)
    {
        if(T->leftChild->height > T->rightChild->height)
            T->height = T->leftChild->height + 1;
        else
            T->height = T->rightChild->height + 1;
    }
    else if(T->rightChild)
    {
        T->height = T->rightChild->height + 1;
    }
    else if(T->leftChild)
    {
        T->height = T->leftChild->height + 1;
    }
    else
    {
        T->height = 0;
    }
}

