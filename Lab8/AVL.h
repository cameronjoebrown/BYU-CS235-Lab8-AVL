//
//  AVL.h
//  Lab7
//
//  Created by Cam on 11/25/18.
//  Copyright © 2018 Cameron Brown. All rights reserved.
//

#ifndef AVL_h
#define AVL_h

#include "NodeInterface.h"
#include "AVLInterface.h"
#include "Node.h"

using namespace std;

class AVL : public AVLInterface {
public:
    Node* root;
    Node* T;
    AVL();
    ~AVL();
    
    NodeInterface * getRootNode() const;
    bool add(int data);
    bool remove(int data);
    void clear();
    bool insert(Node *&T, int val);
    bool removeNode(Node *&T, int val);
    Node* traverseTree(Node* &T);
    void deleteNodes(Node *T);
    void rotateLeft(Node *&T);
    void rotateRight(Node *&T);
    void rotateRightLeft(Node *&T);
    void rotateLeftRight(Node *&T);
    bool rebalance(Node *&T, int val);
};

#endif /* AVL_h */
