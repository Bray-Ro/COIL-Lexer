/*
Compile as normal C program (clang example.c -o example)
====================================================
		Run: ./example program.c

*/


// Define tokens as macros here
#define _INT            "int"
#define _SPACE          " "
#define _SEMICOLON      ";"

#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"








/*
Define an array of Tokens here.
First value is the type of the token, the second is the token's corrosponding string an the third is the token's ID.
*/
_TOKEN SYNTAX[2550] = {
        {_KEYWORD, _INT, 0},
        {_SEPARATOR, _SPACE, 10},
        {_PUNCTUATOR, _SEMICOLON, 370}
};


int main(int argc, char* argv[255]) {
        /*Read program from a file based on the first argument*/
        FILE *f = fopen(argv[1], "rb");
        fseek(f, 0, SEEK_END);
        long fsize = ftell(f);
        fseek(f, 0, SEEK_SET);  /* same as rewind(f); */
        char *program = malloc(fsize + 1);
        fread(program, 1, fsize, f);
        fclose(f);
  /*
  Run lexer function.
  Arguments in order:
      . The program that is being lexed
      . A reference to an array that holds all of the tokens in the language
      . How many tokens are there?
  */
        commander_lexer(program, SYNTAX, 3);
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nes:%s\n", lexed_program.STATEMENTS[0].TOKENS[0].LEXEME);
        return 0;
}
