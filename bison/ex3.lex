%{ 
#include "ex3.tab.h" 
int line_no;
%}
%% 
[ \t]+ ; 
[0-9]+  { yylval.integer = atoi(yytext); return INTCONST; }  
"*"     { return ASTERISK; } 
\n      { line_no++; } 
%% 
int yywrap(void)  { return 1; }