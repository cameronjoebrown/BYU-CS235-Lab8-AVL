//
//  Node.h
//  Lab7
//
//  Created by Cam on 11/25/18.
//  Copyright © 2018 Cameron Brown. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include "NodeInterface.h"
#include <iostream>
using namespace std;

class Node : public NodeInterface {
    friend class AVL;
    
public:
    Node *leftChild;
    Node *rightChild;
    int val;
    int height;
    
    Node(int value) {
        val = value;
        leftChild = NULL;
        rightChild = NULL;
        height = 0;
    }
    ~Node() {}
    
    int getData() const {
        return val;
    }
    
    NodeInterface * getLeftChild() const {
        return leftChild;
    }
    
    NodeInterface * getRightChild() const {
        return rightChild;
    }
    
    int getHeight() {
        int leftHeight = 0;
        int rghtHeight = 0;
        if (leftChild != NULL) {
            leftHeight = leftChild->getHeight();
        }
        if (rightChild != NULL) {
            rghtHeight = rightChild->getHeight();
        }
        if (leftHeight > rghtHeight) {
            return leftHeight + 1;
        }
        else {
            return rghtHeight + 1;
        }
    }
    int getBalance() {
        int rghtHeight;
        int leftHeight;
        if (rightChild != NULL) {
            rghtHeight = rightChild->getHeight();
        }
        else {
            rghtHeight = 0;
        }
        if (leftChild != NULL) {
            leftHeight = leftChild->getHeight();
        }
        else {
            leftHeight = 0;
        }
        return rghtHeight - leftHeight;
    }
};

#endif /* Node_h */
