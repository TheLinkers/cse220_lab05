/* Team 15: https://github.com/TheLinkers/cse220_lab4
 Nikolas Conklin: nconklin
 Daniel Martin: plan10-acme
 Matthew Weser: mweser
 
 28 Apr 2014
 CSE 220
 10:30am T Th
 
 Real.cpp
 Lab5 */

#include "Real.h"

Real::Real() : Literal<float>(0.0) {
    number_type = false;
    
    
}

 void Real::print()
{
    cout << "    >> <NUMBER>\t\t" << this->getLiteral() << " (real)\n";
}

