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
    Node(int value, Node* L = nullptr, Node* R = nullptr) {
        data = value;
        leftChild = L;
        rightChild = R;
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
    Node* leftChild;
    Node* rightChild;
    int data;
};

#endif /* Node_h */
