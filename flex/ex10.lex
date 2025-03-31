DOT \.
DIG1 [0-9]
DIG2 [1-9]
EXP [eE][-+]?[0-9]+ 
ANY_TEXT .|\n 
OPEN_BRACKET \(
CLOSE_BRACKET \)


%x IN_BRACKET


%{ 
#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 

int nDot=0;
int nInterpunction=0;
int nCapitalWord=0; 
%}

%%  
<INITIAL>{ 
    {OPEN_BRACKET}    {BEGIN IN_BRACKET;} 
        
    ("umjetna"|"algoritam"|"inteligencija"|"automatizacija"|"etika"|"tehnologija") { 
        for(int i = 0; yytext[i] != '\0'; i++) { 
            putchar(toupper(yytext[i])); 
        } 
    }
    ("Umjetna"|"Algoritam"|"Inteligencija"|"Automatizacija"|"Etika"|"Tehnologija") { 
        nCapitalWord++;     //ensures that after capitalizing the word we still increase the counter because of the problem around
                            //rules when working with Flex where only the lexical rule that covers most of the text is applied
        for(int i = 0; yytext[i] != '\0'; i++) { 
            putchar(toupper(yytext[i])); 
        } 
    }
    ({DOT}{DIG1}+)  { ECHO; }           //adds specifiticty in cases where .999 is recognised as ."999" and removes 999 as number >= than 10
    ({DIG1}{DOT}{DIG1}*)    { ECHO; }   //adds specificity in cases where 9.999 is recognised as 9."999" and removes 999 as number >= than 10
    ({DIG2}{DIG1}+{DOT}{DIG1}+{EXP}?) {;} 
    ({DIG2}{DIG1}+{DOT}?{EXP}?)      {;}

    [.]             { nDot++; nInterpunction++; ECHO; }
    [,]             { nInterpunction++; ECHO; }
    [A-Z][a-zA-Z]* { nCapitalWord++; ECHO;}
    [ ]+$           ;   
    [ ]+            putchar(' '); 
    .|\n    { ECHO; } //ovo osigurava da se ostali znakovi ispisuju pravilno 

}
<IN_BRACKET>{ 
    {CLOSE_BRACKET}   {BEGIN INITIAL;}
    [.]             { nDot++; nInterpunction++; }
    [,]             { nInterpunction++; }
    [A-Z][a-zA-Z]* { nCapitalWord++; }
    {ANY_TEXT}      { ; }
}


%%

int yywrap(void) { return 1; } 

int main(int argc, char *argv[])  
{ 
    yyin = fopen(argv[1], "r"); 
    if(yyin == NULL) exit(1); 
    yylex(); 
    printf("\nAnalysis of the original text before deletion or alteration =>\nNumber of sentences: %d\nNumber of interpunctions: %d\nNumber of words starting with the capital letters: %d\n", nDot, nInterpunction, nCapitalWord);
    fclose(yyin); 
    return 0; 
}  
