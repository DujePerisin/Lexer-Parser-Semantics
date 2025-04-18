/*File -> kalk.y*/
%{
#include "kalk.h"
extern char* yytext;
%}
%union {
    double fValue;              /* num value */
    pmatFunT pmatFun;           /* math function pointer*/
    char * str;                 /* variable name */
    NodeT *nPtr;                /* node pointer */
};
%token <fValue> NUMBER
%token <str> VARIABLE
%token <pmatFun> MATFUN
%token WHILE IF ELSE END PRINT NL STMT_LIST
%token FOR SWITCH CASE DEFAULT BREAK
%right '='
%right '?' ':' 
%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/'
%left '^' 
%nonassoc UMINUS
%type <nPtr> stmt expr stmt_list null_stmt case_list case_stmt 
%%
program: /* NULL */    /*exit normally on eof or Ctrl-Z from keyboard*/  
        | program '.'  { exit(0); }  /*exit on '.' when keyboard input*/
        | program stmt { Execute($2); freeNode($2); } /*execute 
                                                statement by statement*/
        ;
stmt:     null_stmt                     { $$ = $1; }        
        | expr NL                       { $$ = Opr1(PRINT, $1); }        
        | expr ';'                      { $$ = $1; }        
        | PRINT expr NL                 { $$ = Opr1(PRINT, $2); }        
        | PRINT expr ';'                { $$ = Opr1(PRINT, $2); }        
        | WHILE '(' expr ')' stmt_list END { $$ = Opr2(WHILE, $3, $5); }
        | IF '(' expr ')' stmt_list END    { $$ = Opr2(IF, $3, $5); }
        | IF '(' expr ')' stmt_list ELSE stmt_list END { $$ = Opr3(IF, $3, $5, $7); }
        | FOR '(' expr ';' expr ';' expr ')' stmt_list END { $$ = Opr3(FOR, $3, $5, Opr2(STMT_LIST, $7, $9)); }
        | SWITCH '(' expr ')' '{' nl_opt case_list '}' { $$ = Opr2(SWITCH, $3, $7); }
        ;

nl_opt:   /* empty */ 
        | NL
        | nl_opt NL
        ;

case_list: case_stmt                    { $$ = $1; }
        | case_list case_stmt           { $$ = Opr2(STMT_LIST, $1, $2); }
        ;

case_stmt: CASE expr ':' nl_opt stmt_list      { $$ = Opr2(CASE, $2, $5); }
        | DEFAULT ':' nl_opt stmt_list         { $$ = Opr2(DEFAULT, NULL, $4); }
        | BREAK ';' nl_opt                   { $$ = Opr1(BREAK, NULL); }
        ;
null_stmt: NL                           { $$ = NULL; }
        | ';'                           { $$ = NULL; }
stmt_list: stmt                 { $$ = ($1) ? AppendStmt(NULL, $1) : NULL; }
        |  stmt_list stmt       { $$ = ($2) ? AppendStmt($1, $2) : $1; }
        ;
expr:     NUMBER                { $$ = NumConst($1); }
        | VARIABLE              { Symbol *sp = lookupSym($1); 
                                  if(!sp) 
                                       yyerror("Variable not defined");
                                  else if(sp->name != $1) 
                                       free($1); 
                                  $$ = Var(sp); 
                                }                     
        | VARIABLE '=' expr     { Symbol *sp = lookupSym($1);
                                  if(!sp) sp = insertSym($1);
                                  $$ = Opr2('=', Var(sp), $3); 
                                }      
        | MATFUN '(' expr ')'   {$$ = MatFun($1, $3); }                           
        |  expr '?' expr ':' expr  { $$ = Opr3('?', $1, $3, $5); }          
        | '-' expr %prec UMINUS { $$ = Opr1(UMINUS, $2); }
        | expr '+' expr         { $$ = Opr2('+', $1, $3); }
        | expr '-' expr         { $$ = Opr2('-', $1, $3); }
        | expr '*' expr         { $$ = Opr2('*', $1, $3); }
        | expr '/' expr         { $$ = Opr2('/', $1, $3); }
        | expr '<' expr         { $$ = Opr2('<', $1, $3); }
        | expr '>' expr         { $$ = Opr2('>', $1, $3); }
        | expr '^' expr         { $$ = Opr2('^', $1, $3); }
        | expr GE expr          { $$ = Opr2(GE,  $1, $3); }
        | expr LE expr          { $$ = Opr2(LE,  $1, $3); }
        | expr NE expr          { $$ = Opr2(NE,  $1, $3); }
        | expr EQ expr          { $$ = Opr2(EQ,  $1, $3); }
        | '(' expr ')'          { $$ = $2; }
        ;
%%
void yyerror(char *s) {
	if(yyin != stdin) fprintf(stdout, "Line: %d: %s\n", lineno, s);
	else fprintf(stdout, "Error: %s (at token '%s')\n", s, yytext);			
	longjmp(jumpdata,0);	/*a better exit than yyparse()==0 error*/
}