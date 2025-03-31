%{
#include "ex4.tab.h"
%}

%option noyywrap

%%

[0-9]+    { yylval.integer = atoi(yytext); return INTCONST; }
"*"       { return ASTERISK; }
"/"       { return SLASH; }
"+"       { return PLUS; }
"-"       { return MINUS;}
"("       { return LPAREN; }
")"       { return RPAREN; }
[ \t\n]   ;  // ignore whitespace
.         { printf("Unknown symbol: %s\n", yytext); return 1; }

%%