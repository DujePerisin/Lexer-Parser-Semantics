%{ 
#include "ex5.tab.h" 
#include <stdio.h>
#include <stdlib.h>

int line_no;
%}

%% 
[ \t]+              ;  
[0-9]+              { yylval.integer = atoi(yytext); return INTCONST; }  
"*"                 { return ASTERISK; }  
"+"                 { return PLUS; }  
"-"                 { return MINUS; }  
"/"                 { return SLASH; }  
"%"                 { return PERCENT; }  
"^"                 { return CARET; }  
"("                 { return '('; }  
")"                 { return ')'; }  
\n                  { line_no++; }  
%%

int yywrap(void) { return 1; }  

