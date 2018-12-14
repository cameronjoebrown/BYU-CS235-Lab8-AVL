//
//  AVL.h
//  Lab7
//
//  Created by Cam on 11/25/18.
//  Copyright © 2018 Cameron Brown. All rights reserved.
//

#ifndef AVL_h
#define AVL_h

#include <stdio.h>
#include "AVLInterface.h"
#include "Node.h"

using namespace std;

class AVL : public AVLInterface {
public:
    AVL();
    ~AVL();
    NodeInterface* getRootNode() const;
    bool add(int val);
    bool addHelper(Node* &T, int val);
    bool remove(int val);
    bool removeHelper(Node* &T, int val);
    void clear();
    void clearHelper(Node* T);
    int traverseTree(Node* T);
    
    void rotateLeft(Node *&T);
    void rotateRight(Node *&T);
    void rebalance(Node *T);
    void updateHeight(Node *T);
    
private:
    Node* root;
};

#endif /* AVL_h */
