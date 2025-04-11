/*
 *  The scanner definition for COOL.
 */

/*
 *  Stuff enclosed in %{ %} in the first section is copied verbatim to the
 *  output, so headers and global definitions are placed here to be visible
 * to the code in the file.  Don't remove anything that was here initially
 */
%option noyywrap 
%{
#include <cool-parse.h>
#include <stringtab.h>
#include <utilities.h>

/* The compiler assumes these identifiers. */
#define yylval cool_yylval
#define yylex  cool_yylex

/* Max size of string constants */
#define MAX_STR_CONST 1025
#define YY_NO_UNPUT   /* keep g++ happy */

extern FILE *fin; /* we read from this file */

/* define YY_INPUT so we read from the FILE fin:
 * This change makes it possible to use this scanner in
 * the Cool compiler.
 */
#undef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( (result = fread( (char*)buf, sizeof(char), max_size, fin)) < 0) \
		YY_FATAL_ERROR( "read() in flex scanner failed");

char string_buf[MAX_STR_CONST]; /* to assemble string constants */
char *string_buf_ptr;

extern int curr_lineno;
extern int verbose_flag;

extern YYSTYPE cool_yylval;




/*
 *  Add Your own definitions here
 */

int comment_depth = 0; /* prati koliko je komentara otvoreno */
    
%}

/*
 * Define names for regular expressions here.
 */

DARROW          =>
WHITESPACE      [ \f\r\t\v]
INVALID         [!#$%^&_>`?`\[\]\\|]
%x COMMENT
%x STRING

%%

 /*
  *  Nested comments
  */

\n              { curr_lineno++; }
{WHITESPACE}+   {/* preskacemo prazan prostor i dash-komentare */};

"--".*        ;

\(\* {
    comment_depth = 1;
    BEGIN(COMMENT);
}


<COMMENT>{
    \(\* {
        comment_depth++;
    }   /* povecavamo ili smanjujemo dubinu ovisno po potrebi te kada dodemo do 0 vracamo se u INITAL stanje */
    \*\) {
        comment_depth--;
        if (comment_depth == 0) {
            BEGIN(INITIAL);
        }
    }
    \n {
        curr_lineno++;
    }   /* ako naidemo na EOF unutar komentara onda vracamo ERROR ocito */
    <<EOF>> {
        BEGIN(INITIAL);
        cool_yylval.error_msg = "EOF in comment";
        return ERROR;
    }
    . ;  /* ignorira se sve ostalo, whitespace, tekst; failswitch za beskonacnost */
}


\*\) {
    cool_yylval.error_msg = "Unmatched *)";
    return ERROR;
}

 /*
  *  The multiple-character operators.
  *//*mozda i single character, BTW NEMA ">" s obzirom da bi mi uvik javljalo <Invalid Token> te je on sam invalid u invalidcharacters.cl stoga smatram da je on invalidni znak*/


"=>"  {return (DARROW);}
"<="  {return (LE);}
"<-"  {return (ASSIGN);}

"{"   {return '{';}
"}"   {return '}';}
"("   {return '(';}
")"   {return ')';}

"+"   {return '+';}
"-"   {return '-';}
"*"   {return '*';}
"/"   {return '/';}
"<"   {return '<';}

"="   {return '=';}

";"   {return ';';}
","   {return ',';}
"."   {return '.';}
":"   {return ':';}

"@"   {return '@';}
"~"   {return '~';}


 /*
  * Keywords are case-insensitive except for the values true and false,
  * which must begin with a lower-case letter.
  */

[eE][lL][sS][eE]  {return (ELSE);}
[cC][lL][aA][sS][sS]  {return (CLASS);}
[fF][iI]  {return (FI);}
[iI][fF]  {return (IF);}
[iI][Nn]  {return (IN);}
[iI][Nn][hH][eE][rR][Ii][Tt][sS]  {return (INHERITS);}
[iI][sS][vV][oO][iI][dD]  {return (ISVOID);}
[lL][eE][tT]  {return (LET);}
[lL][oO][oO][pP]  {return (LOOP);}
[pP][oO][oO][Ll]  {return (POOL);}
[tT][hH][eE][nN]  {return (THEN);}
[wW][hH][iI][lL][eE]  {return (WHILE);}
[cC][aA][sS][eE]  {return (CASE);}
[eE][Ss][aA][cC]  {return (ESAC);}
[nN][eE][Ww]  {return (NEW);}
[oO][fF]  {return (OF);}
[nN][oO][tT]  {return (NOT);}

[ \t\n\r]+     ;

[0-9]*\.[0-9]+ {
  cool_yylval.symbol = inttable.add_string(yytext);
  return INT_CONST;
}

[0-9]+ {
  cool_yylval.symbol = inttable.add_string(yytext);
  return INT_CONST;
}


"_" {
    cool_yylval.error_msg = "_";
    return ERROR;
}

t[rR][uU][eE] {
  cool_yylval.boolean = 1;
  return BOOL_CONST;
}

f[aA][lL][sS][eE] {
  cool_yylval.boolean = 0;
  return BOOL_CONST;
}

[a-z][A-Za-z0-9_]* {
  cool_yylval.symbol = idtable.add_string(yytext);
  return OBJECTID;
}/*46*/

[A-Z][A-Za-z0-9_]* {
    cool_yylval.symbol = idtable.add_string(yytext);
    return TYPEID;
}



 /*
  *  String constants (C syntax)
  *  Escape sequence \c is accepted for all characters c. Except for 
  *  \n \t \b \f, the result is c.
  *
  */
    
\" {
    string_buf_ptr = string_buf; /* reset string_buffer-a */
    BEGIN(STRING);
}

<STRING>{       
    \\n       { *string_buf_ptr++ = '\n'; }
    \\t       { *string_buf_ptr++ = '\t'; }
    \\b       { *string_buf_ptr++ = '\b'; }
    \\f       { *string_buf_ptr++ = '\f'; }
    \\\\      { *string_buf_ptr++ = '\\'; }
    \\\"      { *string_buf_ptr++ = '\"'; }
                                    /*  lekser treba pretvoriti escape sekvence u njihove 
                                      ispravne vrijednosti
                                       na primjer za:
                                      „ a b \ n c d „
                                       lekser treba vratiti token STR_CONST sa sadržajem: */
            
    \\(\r)?\n {
        *string_buf_ptr++ = '\n';
        curr_lineno++;
    }

    \0 {    /* terminator; strasno */
        BEGIN(INITIAL);
        cool_yylval.error_msg = "String contains null character";
        return ERROR;
    }

    \\[^\nntbf\"\\] { /* za nepoznate escape sekvence */
        *string_buf_ptr++ = yytext[1]; 
    }

    \n {                /* Ako string sadrži ASCII znak za novi red (ne u obliku escape sekvence), prijavite tu grešku 
                        s porukom Unterminated string constant i nastavite leksiranje sa početkom 
                        sljedećeg retka */
        BEGIN(INITIAL);
        curr_lineno++;
        cool_yylval.error_msg = "Unterminated string constant";
        return ERROR;
    }

    \" {
        *string_buf_ptr = '\0';
        if (string_buf_ptr - string_buf >= MAX_STR_CONST) {
            BEGIN(INITIAL);
            cool_yylval.error_msg = "String constant too long";
            return ERROR;
        }
        cool_yylval.symbol = stringtable.add_string(string_buf);
        BEGIN(INITIAL);
        return STR_CONST;
    }

    <<EOF>> {
        BEGIN(INITIAL);
        cool_yylval.error_msg = "EOF in string constant";
        return ERROR;
    }

    . {
        *string_buf_ptr++ = yytext[0];
        if (string_buf_ptr - string_buf >= MAX_STR_CONST) {
            BEGIN(INITIAL);
            cool_yylval.error_msg = "String constant too long";
            return ERROR;
        }
    }
}

{INVALID} { /* failswitch vise nego korisno, s obzirom da ce svakako .{ } skupit sve sta nije prepoznato */
    cool_yylval.error_msg = yytext;
    return ERROR;
}

. {
    cool_yylval.error_msg = strdup(yytext);
    return ERROR;
}

%%