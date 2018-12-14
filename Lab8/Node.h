//
//  Node.h
//  Lab7
//
//  Created by Cam on 11/25/18.
//  Copyright © 2018 Cameron Brown. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>
#include "NodeInterface.h"

class Node : public NodeInterface {
public:
    Node* leftChild;
    Node* rightChild;
    int data;
    int height;
    
    Node(int value, Node* L = nullptr, Node* R = nullptr, int treeHeight = 0) {
        data = value;
        leftChild = L;
        rightChild = R;
        height = treeHeight;
    }
    
    ~Node() {
        
    }
    
    int getData() const {
        return data;
    }
    
    NodeInterface* getLeftChild() const {
        return leftChild;
    }
    
    NodeInterface* getRightChild() const {
        return rightChild;
    }
    
    int getHeight(){
        int leftHeight = 0;
        int rightHeight = 0;
        if (leftChild != nullptr) {
            leftHeight = leftChild->getHeight();
        }
        if (rightChild != nullptr) {
            rightHeight = rightChild->getHeight();
        }
        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        }
        else {
            return rightHeight + 1;
        }
        
    }
    int getBalance(Node *T){
        int rightHeight;
        int leftHeight;
        if (rightChild != nullptr) {
            rightHeight = rightChild->getHeight();
        }
        else {
            rightHeight = 0;
        }
        if (leftChild != nullptr) {
            leftHeight = leftChild->getHeight();
        }
        else {
            leftHeight = 0;
        }
        return rightHeight - leftHeight;
    }
};

#endif /* Node_h */
