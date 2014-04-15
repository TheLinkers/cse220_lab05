//
//  Scanner.cpp
//  Lab4
//
//  Created by Bryce Holton.
//

#include "Scanner.h"
#include "Print.h"

typedef struct
{
    char *string;
    TokenCode token_code;
}
RwStruct;

const RwStruct rw_table[9][10] = {
    {{"do",DO},{"if",IF},{"in",IN},{"of",OF},{"or",OR},{"to",TO},{NULL,NO_TOKEN}}, //Reserved words of size 2
    {{"and",AND},{"div",DIV},{"end",END},{"for",FOR},{"mod",MOD},{"nil",NIL},{"not",NOT},{"set",SET},{"var",VAR},{NULL,NO_TOKEN}}, //Reserved words of size 3
    {{"case",CASE},{"else",ELSE},{"file",FFILE},{"goto",GOTO},{"then",THEN},{"type",TYPE},{"with",WITH},{NULL,NO_TOKEN}}, //Reserved words of size 4
    {{"array",ARRAY},{"begin",BEGIN},{"const",CONST},{"label",LABEL},{"until",UNTIL},{"while",WHILE},{NULL,NO_TOKEN}},  //Reserved words of size 5
    {{"downto",DOWNTO}, {"packed",PACKED},{"record",RECORD}, {"repeat",REPEAT},{NULL,NO_TOKEN}},  // Reserved words of size 6
    {{"program", PROGRAM},{NULL,NO_TOKEN}}, // Reserved words of size 7
    {{"function", FUNCTION},{NULL,NO_TOKEN}}, // Reserved words of size 8
    {{"procedure", PROCEDURE},{NULL,NO_TOKEN}}  // Reserved words of size 9
};

Scanner::Scanner(FILE *source_file, char source_name[], char date[], Print printer) : print(printer)
{
    src_file = source_file;
    strcpy(src_name, source_name);
    strcpy(todays_date, date);
    
    /*******************
     initialize character table, this table is useful for identifying what type of character
     we are looking at by setting our array up to be a copy the ascii table.  Since C thinks of
     a char as like an int you can use ch in get_token as an index into the table.
     *******************/
    unsigned int i;
    for (i = 0; i < CHAR_TABLE_SIZE; i++)
    {
        if (i >= '0' && i <= '9')
        {
            char_table[i] = DIGIT;
        }
        else if ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z'))
        {
            char_table[i] = LETTER;
        }
        else
        {
            char_table[i] = SPECIAL;
        }
    }
    char_table['\''] = QUOTE;
    char_table[EOF_CHAR] = EOF_CODE;
    
    line_number = 0;
    source_line[0] = '\0';
}
Scanner::~Scanner()
{
    
}
bool Scanner::getSourceLine(char source_buffer[])
{
    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
    
    if (fgets(source_buffer, MAX_SOURCE_LINE_LENGTH, src_file) != NULL)
    {
        ++line_number;
        sprintf(print_buffer, "%4d: %s", line_number, source_buffer);
        print.printLine(print_buffer);
        return true;
    }
    else
    {
        return false;
    }
}
Token* Scanner::getToken()
{
    char ch = '\0'; //This can be the current character you are examining during scanning.
    char token_string[MAX_TOKEN_STRING_LENGTH] = {'\0'}; //Store your token here as you build it.
    char *token_ptr = token_string; //write some code to point this to the beginning of token_string
    Token *new_token = new Token();
    
    new_token->setType(NO_TYPE);
    //1.  Skip past all of the blanks
    if (line_ptr == NULL)
    {
        line_ptr = source_line;
    }
    skipBlanks(source_line);
    ch = *line_ptr;
    
    //2.  figure out which case you are dealing with LETTER, DIGIT, QUOTE, EOF, or special, by examining ch
    switch (char_table[ch])
    {//3.  Call the appropriate function to deal with the cases in 2.
        case LETTER:
            getWord(token_string, token_ptr, new_token);
            break;
        case DIGIT:
            getNumber(token_string, token_ptr, new_token);
            break;
        case QUOTE:
            getString(token_string, token_ptr, new_token);
            break;
        case EOF_CODE:
            new_token->setCode(END_OF_FILE);
            break;
        default:
            getSpecial(token_string, token_ptr, new_token);
            break;
    }
    
    return new_token; //What should be returned here?
}
char Scanner::getChar(char source_buffer[])
{
    /*
     If at the end of the current line (how do you check for that?),
     we should call get source line.  If at the EOF (end of file) we should
     set the character ch to EOF and leave the function.
     */
    char ch;
    
    if (*line_ptr == '\0')
    {
        if (!getSourceLine(source_buffer))
        {
            ch = EOF_CHAR;
            return ch;
        }
        line_ptr = source_buffer;
    }
    
    /*
     Write some code to set the character ch to the next character in the buffer
     */
    ch = *line_ptr;
    if ((ch == '\n') || (ch == '\t') || (ch == '\r'))
    {
        ch = ' ';
    }
    if (ch == '{')
    {
        skipComment(source_buffer);
    }
    return ch;
}
void Scanner::skipBlanks(char source_buffer[])
{
    /*
     Write some code to skip past the blanks in the program and return a pointer
     to the first non blank character
     */
    while (getChar(source_buffer) == ' ' && (*line_ptr != EOF_CHAR))
    {
        line_ptr++;
    }
}
void Scanner::skipComment(char source_buffer[])
{
    /*
     Write some code to skip past the comments in the program and return a pointer
     to the first non blank character.  Watch out for the EOF character.
     */
    char ch;
    
    do
    {
        ch = *line_ptr++;
    }
    while ((ch != '}') && (ch != EOF_CHAR));
}
void Scanner::getWord(char *str, char *token_ptr, Token *tok)
{
    /*
     Write some code to Extract the word
     */
    char ch = *line_ptr;
    while ((char_table[ch] == LETTER) || (char_table[ch] == DIGIT))
    {
        *token_ptr++ = *line_ptr++;
        ch = *line_ptr;
    }
    *token_ptr = '\0';
    
    //Downshift the word, to make it lower case
    downshiftWord(str);
    
    /*
     Write some code to Check if the word is a reserved word.
     if it is not a reserved word its an identifier.
     */
    if (!isReservedWord(str, tok))
    {
        //set token to identifier
        tok->setCode(IDENTIFIER);
    }
    tok->setTokenString(string(str));
}
void Scanner::getNumber(char *str, char *token_ptr, Token *tok)
{
    /*
     Write some code to Extract the number and convert it to a literal number.
     */
    char ch = *line_ptr;
    bool int_type = true;
    
    do
    {
        *(token_ptr++) = ch;
        ch = *(++line_ptr);
    }
    while (char_table[ch] == DIGIT);
    
    if (ch == '.')
    {
        //Then we might have a dot or dotdot
        ch = *(++line_ptr);
        if (ch == '.')
        {
            //We have a dotdot, back up ptr and our number is an int.
            int_type = true;
            --line_ptr;
        }
        else
        {
            int_type = false;
            *(token_ptr++) = '.';
            //We have a floating point number
            do
            {
                *(token_ptr++) = ch;
                ch = *(line_ptr++);
            }
            while (char_table[ch] == DIGIT);
        }
    }
    if (ch == 'e' || ch == 'E')
    {
        int_type = false;
        *(token_ptr++) = ch;
        ch = *(++line_ptr);
        if (ch == '+' || ch == '-')
        {
            *(token_ptr++) = ch;
            ch = *(++line_ptr);
        }
        do
        {
            *(token_ptr++) = ch;
            ch = *(++line_ptr);
        }
        while (char_table[ch] == DIGIT);
    }
    *token_ptr = '\0';
    tok->setCode(NUMBER);
    if (int_type)
    {
        tok->setType(INTEGER_LIT);
        tok->setLiteral((int)atoi(str));
    }
    else
    {
        tok->setType(REAL_LIT);
        tok->setLiteral((float)atof(str));
    }
}
void Scanner::getString(char *str, char *token_ptr, Token *tok)
{
    /*
     Write some code to Extract the string
     */
    *token_ptr++ = '\'';
    char ch = *(++line_ptr);
    while (ch != '\'')
    {
        *token_ptr++ = ch;
        ch = *(++line_ptr);
    }
    *token_ptr++ = *line_ptr++;
    *token_ptr = '\0';
    tok->setCode(STRING);
    tok->setType(STRING_LIT);
    string test(str);
    tok->setLiteral(test);
}
void Scanner::getSpecial(char *str, char *token_ptr, Token *tok)
{
    /*
     Write some code to Extract the special token.  Most are single-character
     some are double-character.  Set the token appropriately.
     */
    char ch = *line_ptr;
    *token_ptr = ch;
    
    switch (ch)
    {
        case '^':
            tok->setCode(UPARROW);
            token_ptr++;
            line_ptr++;
            break;
        case '*':
            tok->setCode(STAR);
            token_ptr++;
            line_ptr++;
            break;
        case '(':
            tok->setCode(LPAREN);
            token_ptr++;
            line_ptr++;
            break;
        case ')':
            tok->setCode(RPAREN);
            token_ptr++;
            line_ptr++;
            break;
        case '-':
            tok->setCode(MINUS);
            token_ptr++;
            line_ptr++;
            break;
        case '+':
            tok->setCode(PLUS);
            token_ptr++;
            line_ptr++;
            break;
        case '=':
            tok->setCode(EQUAL);
            token_ptr++;
            line_ptr++;
            break;
        case '[':
            tok->setCode(LBRACKET);
            token_ptr++;
            line_ptr++;
            break;
        case ']':
            tok->setCode(RBRACKET);
            token_ptr++;
            line_ptr++;
            break;
        case ';':
            tok->setCode(SEMICOLON);
            token_ptr++;
            line_ptr++;
            break;
        case ',':
            tok->setCode(COMMA);
            token_ptr++;
            line_ptr++;
            break;
        case '/':
            tok->setCode(SLASH);
            token_ptr++;
            line_ptr++;
            break;
        case ':':
            token_ptr++;
            ch = *(++line_ptr);
            if (ch == '=')
            {
                *token_ptr = '=';
                tok->setCode(COLONEQUAL);
                token_ptr++;
                line_ptr++;
            }
            else
            {
                tok->setCode(COLON);
            }
            break;
        case '<':
            token_ptr++;
            ch = *(++line_ptr);
            if (ch == '=')
            {
                *token_ptr = '=';
                tok->setCode(LE);
                token_ptr++;
                line_ptr++;
            }
            else if (ch == '>')
            {
                *token_ptr = '>';
                tok->setCode(NE);
                token_ptr++;
                line_ptr++;
            }
            else
            {
                tok->setCode(LT);
            }
            break;
        case '>':
            token_ptr++;
            ch = *(++line_ptr);
            if (ch == '=')
            {
                *token_ptr = '=';
                tok->setCode(GE);
                token_ptr++;
                line_ptr++;
            }
            else
            {
                tok->setCode(GT);
            }
            break;
        case '.':
            token_ptr++;
            ch = *(++line_ptr);
            if (ch == '=')
            {
                *token_ptr = '.';
                tok->setCode(DOTDOT);
                token_ptr++;
                line_ptr++;
            }
            else
            {
                tok->setCode(PERIOD);
            }
            break;
        default:
            tok->setCode(ERROR);
            token_ptr++;
            line_ptr++;
            break;
    }
    *token_ptr = '\0';
    tok->setTokenString(string(str));
}
void Scanner::downshiftWord(char word[])
{
    /*
     Make all of the characters in the incoming word lower case.
     */
    int index;
    
    for (index = 0; index < strlen(word); index++)
    {
        word[index] = tolower(word[index]);
    }
}
bool Scanner::isReservedWord(char *str, Token *tok)
{
    /*
     Examine the reserved word table and determine if the function input is a reserved word.
     */
    size_t str_len = strlen(str);
    
    if (str_len >= 2 && str_len <= 9)
    {
        RwStruct rw = rw_table[str_len - 2][0];
        int i;
        for (i = 0; i < 10 && rw_table[str_len - 2][i].token_code != 0; i++)
        {
            rw = rw_table[str_len - 2][i];
            if (strcmp(str, rw.string) == 0)
            {
                tok->setCode(rw.token_code);
                return true;
            }
        }
    }
    return false;
}
int Scanner::getLineNumber()
{
    return this->line_number;
}
