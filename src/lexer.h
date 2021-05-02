// Types of tokens
#define _KEYWORD                1
#define _OPERATOR               2
#define _SEPARATOR              3
#define _LITERAL                4
#define _IDENTIFIER             5
#define _COMMENT                6
#define _PUNCTUATOR             7
#define _SCOPE                  8
// Define states of lexer
#define _SEARCHING              10
#define _SEARCHING_FOR_LITERAL  20
#define _PUNCTUATOR_STATE       30
// Define Booleans
#define TRUE                    1
#define FALSE                   0




typedef struct _TOKEN {
        int TYPE;
        char LEXEME[255];
        int ID;


        
} _TOKEN;

typedef struct _STATEMENT {
        
        _TOKEN TOKENS[255];

} _STATEMENT;

typedef struct _PROGRAM {
        _STATEMENT STATEMENTS[2550];

} _PROGRAM;


/*Syntax for lexer is stored here*/
_TOKEN TOKENS[2550]; 


void commander_lexer();

void printd();
