/* Team 15: https://github.com/TheLinkers/cse220_lab4
 Nikolas Conklin: nconklin
 Daniel Martin: plan10-acme
 Matthew Weser: mweser
 
 28 Apr 2014
 CSE 220
 10:30am T Th
 
 Integer.cpp
 Lab5 */

#include "Integer.h"

Integer::Integer() : Literal<int>(0) {


}

void Integer::print() {
	cout << "    >> <NUMBER>" << this->getLiteral() << " (integer)\n";
}
