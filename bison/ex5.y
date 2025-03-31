%{ //standard procedure to compile and run but in gcc command there is one change to properly connect the math libaries
   // gcc -w lex.yy.c ex5.tab.h ex5.tab.c -o ex5 -lm
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

typedef struct node_str { 
    int elem; 
    struct node_str* left; 
    struct node_str* right; 
}* Node; 

Node ast = NULL; 

int evaluate(Node l); 
%} 

%union { 
    int   integer;  
    struct node_str*  node_ptr;
} 

%token PLUS 
%token MINUS 
%token ASTERISK 
%token SLASH 
%token PERCENT 
%token CARET 
%token <integer> INTCONST 
%type <node_ptr> e 

%left PLUS MINUS 
%left ASTERISK SLASH PERCENT 
%right CARET 
%% 

e   : e PLUS e 
    { 
        $$ = (Node)malloc(sizeof(struct node_str));  
        $$->elem = '+'; 
        $$->left = $1; 
        $$->right = $3; 
        ast = $$;  
    } 
    | e MINUS e 
    { 
        $$ = (Node)malloc(sizeof(struct node_str));  
        $$->elem = '-'; 
        $$->left = $1; 
        $$->right = $3; 
        ast = $$;  
    } 
    | e ASTERISK e 
    { 
        $$ = (Node)malloc(sizeof(struct node_str));  
        $$->elem = '*'; 
        $$->left = $1; 
        $$->right = $3; 
        ast = $$;  
    } 
    | e SLASH e 
    { 
        $$ = (Node)malloc(sizeof(struct node_str));  
        $$->elem = '/'; 
        $$->left = $1; 
        $$->right = $3; 
        ast = $$;  
    } 
    | e PERCENT e 
    { 
        $$ = (Node)malloc(sizeof(struct node_str));  
        $$->elem = '%'; 
        $$->left = $1; 
        $$->right = $3; 
        ast = $$;  
    } 
    | e CARET e 
    { 
        $$ = (Node)malloc(sizeof(struct node_str));  
        $$->elem = '^'; 
        $$->left = $1; 
        $$->right = $3; 
        ast = $$;  
    } 
    | INTCONST 
    { 
        $$ = (Node)malloc(sizeof(struct node_str));  
        $$->elem = $1;  
        $$->left = NULL; 
        $$->right = NULL; 
        ast = $$;  
    } 
    | '(' e ')'
    {
        $$ = $2; // brackets transfer value between themselves
        ast = $$;
    }
    ; 

%% 

yyerror(const char *s) { 
    fprintf( stderr, "%s\n", s ); 
} 

void main() {  
    yyparse(); 
    printf("%d\n", evaluate(ast)); 
} 

int evaluate(Node l) { 
    if( l == NULL )  
        return 0; 
    
    if( l->left == NULL && l->right == NULL )  
        return l->elem; 
    
    if( l->elem == '+' )  
        return evaluate(l->left) + evaluate(l->right); 
    
    if( l->elem == '-' )  
        return evaluate(l->left) - evaluate(l->right); 
    
    if( l->elem == '*' )  
        return evaluate(l->left) * evaluate(l->right); 
    
    if( l->elem == '/' )  
        return evaluate(l->left) / evaluate(l->right); 
    
    if( l->elem == '%' )  
        return evaluate(l->left) % evaluate(l->right); 
    
    if( l->elem == '^' )  
        return (int)pow(evaluate(l->left), evaluate(l->right)); 
    
    return 0; 
}
