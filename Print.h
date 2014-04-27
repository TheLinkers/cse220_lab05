/* Team 15: https://github.com/TheLinkers/cse220_lab4
 Nikolas Conklin: nconklin
 Daniel Martin: plan10-acme
 Matthew Weser: mweser
 
 28 Apr 2014
 CSE 220
 10:30am T Th
 
 Print.h
 Lab5 */
//  Created by Bryce Holton.
//

#ifndef __Lab4__Print__
#define __Lab4__Print__

#include <iostream>
#include "common.h"
#include "Token.h"
#include "Identifier.h"
#include "Integer.h"
#include "Real.h"
#include "String.h"

using namespace std;

class LineNumberList;


class Print {
private:
    string sourceFileName;
    string currentDate;
    int pageNumber;
    int lineCount;
    void printPageHeader();
    
public:
    Print(char source_name[], char date[]);
    ~Print();
    void printLine(char line[]);
    void printToken(Token *token);
    int getLineCount();
    void printTree(Identifier *identifier);
    void printTreeRecursive(Identifier *identifier);
};

#endif /* defined(__Lab4__Print__) */
