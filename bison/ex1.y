
%{
#include <stdio.h> 
%} 

%token ASTERISK 
%token INTCONST 

%% 
e   : INTCONST t; 
t   : ASTERISK INTCONST t 
    | /*epsilon*/ 
    ; 
%%  
yyerror(const char* s) { 
    fprintf( stderr, "%s\n", s ); 
} 
main() {  
    yyparse();  
} 