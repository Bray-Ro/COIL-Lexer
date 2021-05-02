#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "useful_functions.h"
#include "lexer.h"









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

/*Lexed program*/
static _PROGRAM lexed_program;



/*Define array of Keywords*/
void commander_lexer(char *program, _TOKEN TOKENS[2550], int TOKENS_LENGTH) {

	{
		/*What is the current token being lexed?*/
		char CURRENT_TOKEN[255];
		


		
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
							
		
							int ADD_TOKEN = FALSE;
							char tok_str[255];
							SKIP_CHAR = TRUE;
							
							/*Check for punctuator, If one is found then finish statement*/
							if (TOKENS[a].TYPE == _PUNCTUATOR) {

								CURRENT_LEXER_STATE = _PUNCTUATOR_STATE;
								STATEMENTS_PTR++;
							} else if (TOKENS[a].TYPE == _SCOPE) {
												
															ADD_TOKEN = TRUE;
								
								tok_str[0] = CURRENT_CHAR;
								



															CURRENT_LEXER_STATE = _PUNCTUATOR_STATE;
														

							}
						
							/*Do we add a token to the program?*/			
							if (ADD_TOKEN == TRUE) {
								_TOKEN TOKEN_STRUCTURE;
														strcpy(TOKEN_STRUCTURE.LEXEME, tok_str);
														TOKEN_STRUCTURE.TYPE = _SEPARATOR;
														TOKEN_STRUCTURE.ID = TOKENS[a].ID;
								char TYPE_STR[255];

								switch(TOKEN_STRUCTURE.TYPE) {

									case _SEPARATOR:
										strcpy(TYPE_STR, "SEPARATOR");
										break; 

								}
														printf("%s:%s, ", TYPE_STR, TOKEN_STRUCTURE.LEXEME);
															lexed_program.STATEMENTS[STATEMENTS_PTR].TOKENS[TOKENS_PTR] = TOKEN_STRUCTURE;
															strcpy(CURRENT_TOKEN, "");
									
								
							}
							
							a = TOKENS_LENGTH;
							CURRENT_CHAR = program[i+1];

						}
						
					}
					
					a++;
				}
				a = 0;
				while (a <= TOKENS_LENGTH && SKIP_CHAR == TRUE) {
				
					int ADD_TOKEN = FALSE;

					_TOKEN TOKEN_STRUCTURE;
				
								/*If the lexer has encountered a separator then add the current token to the program*/



					
					/*Keyword*/
								if (strcmp(TOKENS[a].LEXEME, CURRENT_TOKEN) == 0 && strcmp(CURRENT_TOKEN, "") != 0) {

										TOKEN_STRUCTURE = TOKENS[a];
						ADD_TOKEN = TRUE;
								} 
					/*Integer literal*/
					else if (isdigit(CURRENT_CHAR) == 1 && strcmp(CURRENT_TOKEN, "") != 0) {
										
						strcpy(TOKEN_STRUCTURE.LEXEME, CURRENT_TOKEN);
											TOKEN_STRUCTURE.TYPE = _LITERAL;
											TOKEN_STRUCTURE.ID = -1;
									
											ADD_TOKEN = TRUE;
						
					}
					/*Identifier*/
					else if (strcmp(TOKENS[a].LEXEME, CURRENT_TOKEN) != 0 && strcmp(CURRENT_TOKEN, "") != 0 && a == TOKENS_LENGTH) {
									
										strcpy(TOKEN_STRUCTURE.LEXEME, CURRENT_TOKEN);
										TOKEN_STRUCTURE.TYPE = _IDENTIFIER;
										TOKEN_STRUCTURE.ID = -2;
									
										ADD_TOKEN = TRUE;
								}


					/*Do we add a token to the program?*/
									if (ADD_TOKEN == TRUE) {
										
										
										
											char TYPE_STR[255];

											switch(TOKEN_STRUCTURE.TYPE) {

												case _KEYWORD:
														strcpy(TYPE_STR, "KEYWORD");
															break;
							case _LITERAL:
															strcpy(TYPE_STR, "LITERAL");
															break;
							case _IDENTIFIER:
															strcpy(TYPE_STR, "IDENTIFIER");
															break;
											}
											printf("%s:%s, ", TYPE_STR, TOKEN_STRUCTURE.LEXEME);
											lexed_program.STATEMENTS[STATEMENTS_PTR].TOKENS[TOKENS_PTR] = TOKEN_STRUCTURE;
											strcpy(CURRENT_TOKEN, "");


									}


					a++;
				}

			}

		
			switch (CURRENT_LEXER_STATE) {
				case _PUNCTUATOR_STATE:
					printf("]\n");
									printf("[");
					STATEMENTS_PTR++;
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
	
	
	


}

void printd() {
	printf("hello");
}
