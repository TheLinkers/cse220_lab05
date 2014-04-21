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

class String: public Token{
    public:
        String():Literal<string>(""){}
        void print(){
            //sprintf(line, "    >> %-16s %-s\n", "<IDENTIFIER>", token->getStringLiteral().c_str());
        }
};