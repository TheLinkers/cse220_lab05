/* Team 15: https://github.com/TheLinkers/cse220_lab4
 Nikolas Conklin: nconklin
 Daniel Martin: plan10-acme
 Matthew Weser: mweser
 
 28 Apr 2014
 CSE 220
 10:30am T Th
 
 Integer.h
 Lab5 */

#ifndef __cse220_lab05__Integer__
#define __cse220_lab05__Integer__

#include <iostream>
#include "Literal.h"

using namespace std;

class Integer : public Literal<int> {
private:
    
public:
    Integer();
    ~Integer();
    virtual void print();
};

#endif /* defined(__cse220_lab05__Integer__) */
