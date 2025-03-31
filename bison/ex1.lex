%{ 
#include "ex1.tab.h"
%}
%% 
[ \t]+  ;   
[0-9]+  { return INTCONST; } 
"*"     { return ASTERISK; } 
%% 

int yywrap(void) { return 1; } 