%x  QUOTE 

ANY_TEXT .|\n 
QUOTE_SIGN \" 

%% 

<INITIAL>{ 
    {QUOTE_SIGN}    {BEGIN QUOTE;} 
    {ANY_TEXT}      {;}
}
<QUOTE>{ 
    {QUOTE_SIGN}    {BEGIN INITIAL;}
    {ANY_TEXT}      {ECHO; }
}

%%

int yywrap(void)    { return 1; }  
int main(int argc, char *argv[]) { 
    int val; 
        yyin = fopen(argv[1], "r"); 
        if(yyin == NULL) exit(1);

    while(val = yylex())  
        printf("value is %d\n",val); 
    return 0;
}
/*
%x QUOTE 

%% 

<INITIAL>{ 
    \"          {BEGIN(QUOTE);}  // Prelazak u stanje QUOTE kada naiđemo na navodnik
    .|\n        {ECHO;}         // Ispisuje sve ostalo
} 

<QUOTE>{ 
    \"          {BEGIN(INITIAL); printf("\n");} // Zatvaranje navodnika i povratak u INITIAL
    .|\n        {printf("%s", yytext);}  // Ispisuje samo sadržaj unutar navodnika
} 

%%

int yywrap(void) { return 1; }  

int main(int argc, char *argv[]) { 
    yyin = fopen(argv[1], "r"); 
    if (yyin == NULL) exit(1);

    yylex();  // Pokreće leksičku analizu

    fclose(yyin); 
    return 0;
}
*/