//
//  common.h
//  Lab3
//
//  Created by Bryce Holton.
//

#ifndef CSE220_project2_common_h
#define CSE220_project2_common_h

#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>

#define FORM_FEED_CHAR          '\f'
#define EOF_CHAR                '\x7f'
#define MAX_FILE_NAME_LENGTH    70
#define MAX_SOURCE_LINE_LENGTH  256
#define MAX_TOKEN_STRING_LENGTH MAX_SOURCE_LINE_LENGTH
#define MAX_PRINT_LINE_LENGTH   80
#define MAX_LINES_PER_PAGE      50
#define DATE_STRING_LENGTH      26

/***************************
 Token Codes
 ***************************/
typedef enum
{
    NO_TOKEN, IDENTIFIER, NUMBER, STRING, UPARROW, STAR, LPAREN,
    RPAREN, MINUS, PLUS, EQUAL, LBRACKET,
    RBRACKET, COLON, SEMICOLON, LT, GT, COMMA, PERIOD, SLASH,
    COLONEQUAL, LE, GE, NE, DOTDOT, END_OF_FILE, ERROR, AND,
    ARRAY, BEGIN, CASE, CONST, DIV, DO, DOWNTO, ELSE, END, FFILE,
    FOR, FUNCTION, GOTO, IF, IN, LABEL, MOD, NIL, NOT, OF, OR, PACKED,
    PROCEDURE, PROGRAM, RECORD, REPEAT, SET, THEN, TO, TYPE, UNTIL,
    VAR, WHILE, WITH,
}
TokenCode;

/*****************************
 Literal Type
 *****************************/
typedef enum
{
    INTEGER_LIT, REAL_LIT, STRING_LIT, NO_TYPE,
}
LiteralType;

#endif
