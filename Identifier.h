/* Team 15: https://github.com/TheLinkers/cse220_lab4
 Nikolas Conklin: nconklin
 Daniel Martin: plan10-acme
 Matthew Weser: mweser
 
 28 Apr 2014
 CSE 220
 10:30am T Th
 
 Identifier.h
 Lab5 */

#ifndef __cse220_lab05__Identifier__
#define __cse220_lab05__Identifier__

#include <iostream>
#include "Token.h"

class Identifier : public Token {
public:
    Identifier();
    ~Identifier();
    void setLeftChild(Identifier *tok);
    Identifier *getLeftChild();
    void setRightChild(Identifier *tok);
    Identifier *getRightChild();
    
private:    
    Identifier* rightChild;
    Identifier* leftChild;
    
};


#endif /* defined(__cse220_lab05__Identifier__) */
