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
#include "Token.h"

using namespace std;

class Identifier : public Token {
public:
    Identifier();
    ~Identifier();
    getLiteral();
    setLiteral(LiteralType literal);		// modify to suit proper way to call templates of literal
    
    
private:
    Literal LiteralType;
    
    
};