#!/bin/bash
#******************************************************
#Team 15: https://github.com/TheLinkers/cse220_lab05
#Nikolas Conklin: nconklin
#Daniel Martin: plan10-acme
#Matthew Weser: mweser
# 
#Lab 5
#28 Apr 2014
#CSE 220
#10:30am T Th
#******************************************************* 

OBJS = Identifier.o IdentifierBinaryTree.o Integer.o LineNumberList.o \
        main.o Print.o Real.o Scanner.o String.o Token.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

CrossReference : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o CrossReference

main.o : main.cpp common.h Print.h Scanner.h Token.h IdentifierBinaryTree.h
	$(CC) $(CFLAGS) main.cpp

Identifier.o : Identifier.h Identifier.cpp 
	$(CC) $(CFLAGS) Identifier.cpp

IdentifierBinaryTree.o : IdentifierBinaryTree.h IdentifierBinaryTree.cpp LineNumberList.h
	$(CC) $(CFLAGS) IdentifierBinaryTree.cpp

Integer.o : Integer.h Integer.cpp
	$(CC) $(CFLAGS) Integer.cpp

LineNumberList.o : LineNumberList.h LineNumberList.cpp
	$(CC) $(CFLAGS) LineNumberList.cpp

Print.o : Print.h Print.cpp
	$(CC) $(CFLAGS) Print.cpp

Real.o : Real.h Real.cpp
	$(CC) $(CFLAGS) Real.cpp

Scanner.o : Scanner.h Scanner.cpp
	$(CC) $(CFLAGS) Scanner.cpp

String.o : String.h String.cpp 
	$(CC) $(CFLAGS) String.cpp

Token.o : Token.h Token.cpp
	$(CC) $(CFLAGS) Token.cpp

clean:
	\rm *.o *~ CrossReference


