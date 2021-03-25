/*
The COIL Lexical analysis library
*/






// Types of tokens
#define _KEYWORD 		1
#define _OPERATOR 		2
#define _SEPARATOR 		3
#define _LITERAL 		4
#define _IDENTIFIER		5
#define _COMMENT		6
#define _PUNCTUATOR		7
#define _SCOPE			8
// Define states of lexer
#define _SEARCHING		10
#define _SEARCHING_FOR_LITERAL	20
#define _PUNCTUATOR_STATE	30
// Define Booleans
#define TRUE			1
#define FALSE			0




#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "useful_functions.h"








typedef struct _TOKEN {
	int TYPE;
	char LEXEME[255]; 
	int ID; 
	
		
	
} _TOKEN;

typedef struct _STATEMENT {

	_TOKEN TOKENS[255]; 

} _STATEMENT;


typedef struct _PROGRAM {
	_STATEMENT STATEMENTS[25500];
	
} _PROGRAM;


/*Checks if string is a number*/
char is_number(char *text)
{
    int j;
    j = strlen(text);
    while(j--)
    {
        if(text[j] > 47 && text[j] < 58)
            continue;

        return 0;
    }
    return 1;
}

/*What is the current state of the lexer?*/
char CURRENT_LEXER_STATE = _SEARCHING;

int SKIP_CHAR = FALSE;


/*Define array of Keywords*/
void commander_lexer(char *program, _TOKEN TOKENS[2550], int TOKENS_LENGTH) {


	/*What is the current token being lexed?*/
	char CURRENT_TOKEN[255];
	

	/*Lexed program*/	
	static _PROGRAM lexed_program; 
	
	int i = 0; 

	/*How many statements have been lexed so far*/
        int STATEMENTS_PTR = 1;

	/*How many tokens are in the current statement so far?*/
	int TOKENS_PTR = 0;
	printf("[");
	/*Loop through the entire program*/
	while (i < strlen(program)) {
		
		
		/*What is the current character being read by the lexer?*/
		char CURRENT_CHAR = program[i];
		
		

		
		{
			int a = 0; 

			/*Get type and other data of current token*/
			while (a <= TOKENS_LENGTH) {
				/*Is current character a Seperator or an operator?*/	
				if (TOKENS[a].TYPE == _SEPARATOR || TOKENS[a].TYPE == _SCOPE || TOKENS[a].TYPE == _PUNCTUATOR) {
					if (TOKENS[a].LEXEME[0] == CURRENT_CHAR) {
						
						

						SKIP_CHAR = TRUE;
						
						/*Check for punctuator, If one is found then finish statement*/
						if (TOKENS[a].TYPE == _PUNCTUATOR) {

							CURRENT_LEXER_STATE = _PUNCTUATOR_STATE;
							STATEMENTS_PTR++;
						} else if (TOKENS[a].TYPE == _SCOPE) {
                                        	
                                                        
							_TOKEN SEPARATOR;
                                        		SEPARATOR.LEXEME[0] = CURRENT_CHAR;
                                        		SEPARATOR.TYPE = _SEPARATOR;
                                        		SEPARATOR.ID = -1;
                                        		printf("SEPARATOR:%s, ", SEPARATOR.LEXEME);
                                        		lexed_program.STATEMENTS[STATEMENTS_PTR-1].TOKENS[TOKENS_PTR] = SEPARATOR;
                                        		strcpy(CURRENT_TOKEN, "");

                                                        CURRENT_LEXER_STATE = _PUNCTUATOR_STATE;
                                                        STATEMENTS_PTR++;

						}
						
						a = TOKENS_LENGTH;
						CURRENT_CHAR = program[i+1];

					}
					
				}
				
				a++;
			}
			a = 0;
			while (a <= TOKENS_LENGTH && SKIP_CHAR == TRUE) {
			
			   
                       	/*If the lexer has encountered a separator then add the current token to the program*/



				
				/*Keyword*/
                        	if (strcmp(TOKENS[a].LEXEME, CURRENT_TOKEN) == 0 && strcmp(CURRENT_TOKEN, "") != 0) {

                               		lexed_program.STATEMENTS[STATEMENTS_PTR-1].TOKENS[TOKENS_PTR] = TOKENS[a];   
					if (TOKENS[a].TYPE == _KEYWORD) {                                                   
                        			printf("KEYWORD:%s, ", TOKENS[a].LEXEME);
					} 
					strcpy(CURRENT_TOKEN, "");
                        	} 
				/*Integer literal*/
				else if (isdigit(CURRENT_CHAR) == 1 && strcmp(CURRENT_TOKEN, "") != 0) {
                                        _TOKEN LITERAL;
                                        strcpy(LITERAL.LEXEME, CURRENT_TOKEN);
                                        LITERAL.TYPE = _LITERAL;
                                        LITERAL.ID = -1;
                                        printf("LITERAL:%s, ", LITERAL.LEXEME);
                                        lexed_program.STATEMENTS[STATEMENTS_PTR-1].TOKENS[TOKENS_PTR] = LITERAL;
                                        strcpy(CURRENT_TOKEN, "");

					
				}
				/*Identifier*/
				else if (strcmp(TOKENS[a].LEXEME, CURRENT_TOKEN) != 0 && strcmp(CURRENT_TOKEN, "") != 0 && a == TOKENS_LENGTH) {
                               		_TOKEN IDEN;
                                	strcpy(IDEN.LEXEME, CURRENT_TOKEN);
                                	IDEN.TYPE = _IDENTIFIER;
                                	IDEN.ID = -1;
                                	printf("IDENTIFIER:%s, ", IDEN.LEXEME);
                                	lexed_program.STATEMENTS[STATEMENTS_PTR-1].TOKENS[TOKENS_PTR] = IDEN;
					strcpy(CURRENT_TOKEN, "");
                        	}
				a++;
			}

		}

	
		switch (CURRENT_LEXER_STATE) {
			case _PUNCTUATOR_STATE:
				printf("]\n");
                                printf("[");
				CURRENT_LEXER_STATE = _SEARCHING;
				break;
			
		}
		/*Check if we have to skip a character*/
		if (SKIP_CHAR == FALSE) {
				/*Add current character to current token*/
				sprintf(CURRENT_TOKEN, "%s%c", CURRENT_TOKEN, CURRENT_CHAR);
		} else {
			SKIP_CHAR = FALSE;
		}
			


		i++;
	}



}
