// Define tokens as macros here
#define _INT "int"


#include <stdio.h>

#include "lexer.h"








/*
Define an array of Tokens here. 
First value is the type of the token, the second is the token's corrosponding string an the third is the token's ID.
*/
_TOKEN SYNTAX[2550] = {
	{_KEYWORD, _INT, 0},
}; 


int main(int argc, char* argv[255]) {


  /*
  Run lexer function. 
  Arguments in order:
      . The program that is being lexed
      . A reference to an array that holds all of the tokens in the language
      . How many tokens are there?
  */
	commander_lexer("int variable", SYNTAX, 1);
	return 0;
}
