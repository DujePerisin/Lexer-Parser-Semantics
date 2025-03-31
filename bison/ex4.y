%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex();
%}

%union {
    int integer;
}

%token <integer> INTCONST
%token PLUS MINUS ASTERISK SLASH LPAREN RPAREN

// correctly alligned all the priorities and association of operators
%left PLUS MINUS
%left ASTERISK SLASH
%right UMINUS //unarny minus where we calculate between a negative and a positive number for example

%%

// grammar rules
expr 
    : expr PLUS expr   { printf("Addition\n"); }
    | expr MINUS expr  { printf("Subtraction\n"); }
    | expr ASTERISK expr { printf("Multiplication\n"); }
    | expr SLASH expr { printf("Division\n"); }
    | LPAREN expr RPAREN { printf("Brackets\n"); }
    | MINUS expr %prec UMINUS { printf("Unary minus\n"); }
    | INTCONST { printf("Number: %d\n", $1); }
    ;

%%


void yyerror(const char *s) {
    fprintf(stderr, "Syntax error: %s\n", s);
}

int main() {
    printf("\nExit program via CTRL+C, recommended after every entry\nbecause of the way parser doesn't reset its state.\n\nEnter expression:\n");
    yyparse();
    return 0;
}
