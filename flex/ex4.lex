%{ 
int nchar=0, nword=0, nline=0; 
%}
%% 
\n         { nline++; nchar++; } 
[^ \t\n]+  { nword++, nchar += yyleng; } 
.          { nchar++; } 
%% 
int yywrap(void) {   return 1; } 
int main(int argc, char *argv[])  
{ 
yyin = fopen(argv[1], "r"); 
if(yyin == NULL) exit(1); 
yylex(); 
printf("Number of chars: %d\nNumber of words: %d\nNumber of lines: %d\n", nchar, nword, nline); 
fclose(yyin); 
}