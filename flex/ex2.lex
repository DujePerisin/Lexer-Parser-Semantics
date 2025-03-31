%% 
[\t\r ]+       ;     /* preskoci bijele znakove */;
 
while |  
if |  
do |  
for |  
switch |  
case |  
else |  
break | 
continue |  
static                  {printf("%s: kljucna rijec\n", yytext);}
"string"                {printf("%s: string\n", yytext);}
("*")[a-zA-Z_]+         {printf("%s: pointer\n", yytext);}
("**")[a-zA-Z_]+        {printf("%s: pointer na pointer\n", yytext);}
("&")[a-zA-Z_]+         {printf("%s: adresa varijable\n", yytext);}
("++")[a-zA-Z_]+        {printf("%s: prefiks inkrement s identifikatorom\n", yytext);}
[a-zA-Z_]+("++")        {printf("%s: postfiks inkrement s identifikatorom\n", yytext);}
[0-9]*\.[0-9]+          {printf("%s: decimalni broj\n", yytext);}   
[0-9]+                  {printf("%s: broj\n", yytext);}   
[a-zA-Z]+               {printf("%s: identifikator \n", yytext);} 
[\*+\-=<>]              {printf("%s: operator\n", yytext);} 
[()\[\];]               {printf("%s: separator\n", yytext);} 
.|\n                    { ECHO; /*default */} 
%% 
int yywrap(void) { return 1; } 
int main () 
{ 
yylex(); 
return 0; 
} 