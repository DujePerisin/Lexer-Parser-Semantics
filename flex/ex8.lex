%{ 
#include <stdio.h> 
#define NUMBER 400 
#define COMMENT 401 
#define STRING 402 
#define COMMAND 403 
#define NEWLINE 404 
#define SEPARATOR 405
#define OPERATOR 406
%}
%% 
[ \t]+      ;
[0-9]+ |                
[0-9]+\.[0-9]+ |        
\.[0-9]+                { return NUMBER; }
\"[^\"\n]*\"            { return STRING; }
[a-zA-Z][a-zA-Z0-9]+    { return COMMAND; } 
"//".*                  { return COMMENT; }
\n                      { return NEWLINE; }
[(,;.:)]                ;
[+*-/=]                 ;
%% 
int yywrap(void)  { return 1; }  
int main(int argc, char *argv[]) { 
    int val; 
    yyin = fopen(argv[1], "r"); 
    if(yyin == NULL) exit(1); 

    while(val = yylex())  
        printf("value is %d\n",val); 
    return 0; 
}