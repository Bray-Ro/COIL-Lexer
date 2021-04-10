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
_TOKEN SYNTAX[255]; 


void commander_lexer();

void printd();
