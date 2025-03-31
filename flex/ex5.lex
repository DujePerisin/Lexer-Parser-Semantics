digit     [0-9] 
letter    [A-Za-z]

%{ 
    int count; 
%}
%% 
    /* match identifier */ 
{letter}({letter}|{digit})*    count++; 
{digit}({letter}|{digit})*     ECHO; 
%% 
int yywrap(void) { return 1; }  

int main(int argc, char *argv[])  
{ 
    yyin = fopen(argv[1], "r"); 
    if(yyin == NULL) exit(1); 
    yylex(); 
    printf("\nNumber of identifiers = %d\n", count); 
    fclose(yyin); 
    return 0; 
}