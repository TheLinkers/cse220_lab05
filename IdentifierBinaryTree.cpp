//
//  IdentifierBinaryTree.cpp
//  Lab4
//
//  Created by Bryce Holton on 3/28/14.
//  Copyright (c) 2014 Bryce Holton. All rights reserved.
//

#include "IdentifierBinaryTree.h"
#include "LineNumberList.h"

using namespace std;

IdentifierBinaryTree::IdentifierBinaryTree()
{
    setTreeRoot(NULL);
}
IdentifierBinaryTree::~IdentifierBinaryTree()
{
    Token *root = getTreeRoot();
    
    if (root != NULL)
    {
        depthFirstDeleteTree(root);
    }
}
void IdentifierBinaryTree::depthFirstDeleteTree(Token *tok)
{
    if (tok->getLeftChild() != NULL)
    {
        depthFirstDeleteTree(tok->getLeftChild());
    }
//    cout << tok->getTokenString() << "\n";
    if (tok->getRightChild() != NULL)
    {
        depthFirstDeleteTree(tok->getRightChild());
    }
    delete tok;
}
void IdentifierBinaryTree::setTreeRoot(Token *root)
{
    this->treeRoot = root;
}
Token *IdentifierBinaryTree::getTreeRoot()
{
    return this->treeRoot;
}
bool IdentifierBinaryTree::addIdentifier(Token *tok, int lineNum)
{
    bool success = false;
    LineNumberList *listItem = new LineNumberList();
    
    listItem->setLineNumber(lineNum);
    if (getTreeRoot() == NULL)
    {
        setTreeRoot(tok);
        tok->addToLineNumberList(listItem);
        success = true;
    }
    else
    {
        string tokenName = tok->getTokenString();
        Token *parentNode = getTreeRoot();
        string treeNodeName;
        int stringComparison;
        
        while (parentNode != NULL)
        {
            treeNodeName = parentNode->getTokenString();
            stringComparison = tokenName.compare(treeNodeName);
            if (stringComparison == 0)
            {
                //They are the same identifier token we just need to add a new line number to the list.
                parentNode->addToLineNumberList(listItem);
                parentNode = NULL; //Exit the loop
                delete tok;         //We won't need tok and it won't be deleted in main.
                success = true;
            }
            else if (stringComparison < 0)
            {
                //Go to the left.
                if (parentNode->getLeftChild() == NULL)
                {
                    //Add tok to the left
                    tok->addToLineNumberList(listItem);
                    parentNode->setLeftChild(tok);
                    parentNode = NULL;
                    success = true;
                }
                else
                {
                    parentNode = parentNode->getLeftChild();
                }
            }
            else
            {
                //Go to the right.
                if (parentNode->getRightChild() == NULL)
                {
                    //Add tok to the right
                    tok->addToLineNumberList(listItem);
                    parentNode->setRightChild(tok);
                    parentNode = NULL;
                    success = true;
                }
                else
                {
                    parentNode = parentNode->getRightChild();
                }
            }
        }
    }
    return success;
}
