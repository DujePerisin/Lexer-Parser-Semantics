EXP [eE][-+]?[0-9]+ 
DOT \. 
DIG [0-9] 
%% 
({DIG}*{DOT}{DIG}+{EXP}?) {printf("number\n");} 
({DIG}+{DOT}?{EXP}?)      {printf("number\n");}
. ECHO; 

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