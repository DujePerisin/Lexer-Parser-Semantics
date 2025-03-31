%{ 
#include <stdio.h> 
#include <stdlib.h> 
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
%type <node_ptr> e t 

%% 
e  : INTCONST t  
        {  
        list = (Node)malloc(sizeof(struct node_str));  
        list->elem = $1;  
        list->next = (Node)$2;  
        } 
    ;

t : ASTERISK INTCONST t  
        {  
        $$ = (Node)malloc(sizeof(struct node_str));  
        $$->elem = $2;  
        $$->next = $3;
        } 
    | /*epsilon*/ 
    { $$ = (Node)NULL; } 
    ; 

%% 
yyerror(const char *s) { 
    fprintf( stderr, "%s\n", s ); 
} 
void main() {  
    yyparse(); 
    printf("%d\n", evaluate(list)); 
} 
int evaluate(Node l) { 
    if( l == NULL )  
        return 1; 
    else 
        return l->elem * evaluate(l->next); 
} 