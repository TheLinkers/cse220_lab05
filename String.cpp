/* Team 15: https://github.com/TheLinkers/cse220_lab4
 Nikolas Conklin: nconklin
 Daniel Martin: plan10-acme
 Matthew Weser: mweser
 
 28 Apr 2014
 CSE 220
 10:30am T Th
 
 String.cpp
 Lab5 */

#include "String.h"

String::String():  Literal<string>("") {
    
    
}

void String::print() {
    	cout << "    >> <STRING>\t\t" << this->getLiteral() << "\n";
}