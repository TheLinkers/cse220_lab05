//
//  IdentifierBinaryTree.h
//  Lab4
//
//  Created by Bryce Holton on 3/28/14.
//  Copyright (c) 2014 Bryce Holton. All rights reserved.
//

#ifndef __Lab4__IdentifierBinaryTree__
#define __Lab4__IdentifierBinaryTree__

#include <iostream>
#include "Token.h"

class IdentifierBinaryTree
{
    Token *treeRoot;
    
    void depthFirstDeleteTree(Token *tok);
    
public:
    IdentifierBinaryTree();
    ~IdentifierBinaryTree();
    void setTreeRoot(Token *root);
    Token *getTreeRoot();
    bool addIdentifier(Token *tok, int lineNum);
};

#endif /* defined(__Lab4__IdentifierBinaryTree__) */
