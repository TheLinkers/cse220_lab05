/* Team 15: https://github.com/TheLinkers/cse220_lab4
 Nikolas Conklin: nconklin
 Daniel Martin: plan10-acme
 Matthew Weser: mweser
 
 28 Apr 2014
 CSE 220
 10:30am T Th
 
 Literal.h
 Lab5 */

#ifndef __cse220_lab05__Literal__
#define __cse220_lab05__Literal__

#include <iostream>
#include "Token.h"

using namespace std;

template <typename T>

class Literal : public Token{
private:
    T literal;
public:
    Literal(T lit) {setLiteral(lit);}
    ~Literal(){}
    void setLiteral(T lit) {literal = lit;}
    T getLiteral() {return literal;}
    virtual void print() = 0;
};

#endif /* defined(__cse220_lab05__Literal__) */
