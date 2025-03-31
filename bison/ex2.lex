%{ 
#include "ex2.tab.h" 
%}
%% 
[ \t]+ ; 
[0-9]+  { yylval.integer = atoi(yytext); return INTCONST; }  
"*"     { return ASTERISK; } 
%% 
int yywrap(void)  { return 1; }