%% 
[A-Z]   putchar(yytext[0]-'A'+'a');
[ ]+$   ;
[ ]+    putchar(' '); 
%%

int yywrap(void) { return 1; } 
int main(int argc, char *argv[])  
{ 
    yyin = fopen(argv[1], "r"); 
    if(yyin == NULL) exit(1); 
    yylex(); 
    fclose(yyin); 
    return 0; 
} 