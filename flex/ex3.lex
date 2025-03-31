%{ 
    int lineno=0;   /* the row counter */ 
%}
%% 
^(.*)\n    printf("%4d\t%s", ++lineno, yytext); 
%% 
int yywrap(void) {   return 1; } 
int main(int argc, char *argv[])  
{
    yyin = fopen(argv[1], "r"); 
    if(yyin == NULL) exit(1); 
    yylex(); 
    fclose(yyin); 
}   