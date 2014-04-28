/* Team 15: https://github.com/TheLinkers/cse220_lab4
 Nikolas Conklin: nconklin
 Daniel Martin: plan10-acme
 Matthew Weser: mweser
 
 28 Apr 2014
 CSE 220
 10:30am T Th
 
 Identifier.cpp
 Lab5 */

#include "Identifier.h"

using namespace std;

Identifier::Identifier() {
    setLeftChild(NULL);
    setRightChild(NULL);
}

Identifier::~Identifier() {
    
}

void Identifier::setLeftChild(Identifier *tok) {
    this->leftChild = tok;
}

Identifier* Identifier::getLeftChild() {
	// not sure how to inherit this from Token
    return leftChild;
}

void Identifier::setRightChild(Identifier *tok) {
        rightChild = tok;
}

Identifier* Identifier::getRightChild() {
    	// not sure how to inherit this from Token
    return this->rightChild;
}
