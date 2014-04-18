/* Team 15: https://github.com/TheLinkers/cse220_lab4
 Nikolas Conklin: nconklin
 Daniel Martin: plan10-acme
 Matthew Weser: mweser
 
 28 Apr 2014
 CSE 220
 10:30am T Th
 
 LineNumberList.cpp
 Lab5 */
//  Created by Bryce Holton on 3/28/14.
//  Copyright (c) 2014 Bryce Holton. All rights reserved.
//

#include "LineNumberList.h"

LineNumberList::LineNumberList()
{
    setLineNumber(0);
    setNextLineNumber(NULL);
}
LineNumberList::~LineNumberList()
{
    
}
void LineNumberList::setLineNumber(int num)
{
    this->lineNumber = num;
}
int LineNumberList::getLineNumber()
{
    return this->lineNumber;
}
void LineNumberList::setNextLineNumber(LineNumberList *next)
{
    this->nextLineNumber = next;
}
LineNumberList *LineNumberList::getNextLineNumber()
{
    return this->nextLineNumber;
}
