%{ 
#include <stdio.h> 
#include <stdlib.h> 

extern  int line_no; 
extern  char* yytext;

typedef struct node_str { 
    int elem; 
    struct node_str* next; 
}* Node; 
Node list = NULL; 

int evaluate(Node l); 
%} 
%union { 
    int   integer;  
    struct node_str*  node_ptr;  
} 

%token ASTERISK 
%token <integer> INTCONST 
%type <node_ptr> e  
%left ASTERISK 
%% 
e  : e ASTERISK e 
        { 
            if( list == NULL) {  
                list = $3; 
                $3->next = $1; 
            } else { 
                $3->next = list; 
                list = $3; 
            } 
        } 
 | INTCONST 
        { 
            $$ = (Node)malloc(sizeof(struct node_str));  
            $$->elem = $1;  
            $$->next = NULL;
        } 
    ; 
%%

yyerror(char* mess) { 
    static errors = 10; 
    fprintf(stderr, "line %d: %s before '%s'\n",  
    line_no, mess, yytext); 
    if (! --errors) { 
        fprintf(stderr, "too many errors\n"); 
        exit(1); 
    } 
    return; 
} 
void main() {  
    line_no = 1;
    yyparse(); 
    printf("%d\n", evaluate(list)); 
} 
int evaluate(Node l) { 
    if( l == NULL )  
        return 1; 
    else 
        return l->elem * evaluate(l->next); 
} 