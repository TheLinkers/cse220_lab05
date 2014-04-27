/* Team 15: https://github.com/TheLinkers/cse220_lab4
 Nikolas Conklin: nconklin
 Daniel Martin: plan10-acme
 Matthew Weser: mweser
 
 28 Apr 2014
 CSE 220
 10:30am T Th
 
 main.cpp
 Lab5 */

    //  Created by Bryce Holton.
    //

#include <iostream>
#include <typeinfo>
#include "common.h"
#include "Print.h"
#include "Scanner.h"
#include "Token.h"
#include "IdentifierBinaryTree.h"

FILE *init_lister(const char *name, char source_file_name[], char dte[]);
void quit_scanner(FILE *src_file, Token *list);
void add_token_to_list(Token *list, Token *new_token);

int main(int argc, const char * argv[])
{
    Token *token = NULL;
    char source_name[MAX_FILE_NAME_LENGTH];
    char date[DATE_STRING_LENGTH];
    FILE *source_file = init_lister(argv[1], source_name, date);
    Print print(source_name, date);
    Scanner scanner(source_file, source_name, date, print);
    IdentifierBinaryTree tree;
    
    do
	{
	number_type = false;
	token = scanner.getToken();
        print.printToken(token);
        if (token->getCode() == IDENTIFIER)
	    {
	    tree.addIdentifier((Identifier*) token, scanner.getLineNumber());
	    }
        else if (token->getCode() != PERIOD && token->getCode() != END_OF_FILE)
	    {
		//delete token;
	    }
	}
    while (token->getCode() != PERIOD && token->getCode() != END_OF_FILE);
    
    print.printTree(tree.getTreeRoot());
	//delete token;
    fclose(source_file);
    return 0;
}
FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
    time_t timer;
    FILE *file;
    strcpy(source_file_name, name);
    file = fopen(source_file_name, "r");
    time(&timer);
    strcpy(dte, asctime(localtime(&timer)));
    return file;
}

