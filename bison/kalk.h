/* file: kalk.h */
#ifndef KALK_H
#define KALK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <setjmp.h>

/* Type definitions */
typedef struct _sym {
    char* name;
    double val;
    struct _sym* next;
} Symbol;

typedef enum { kindNum, kindVar, kindMatFun, kindOpr } nodeKindT;
typedef double (*pmatFunT)(double);
typedef struct nodeTag NodeT;

struct nodeTag {
    nodeKindT kind; /* type of node */
    int oper;
    union {
        double value; /*num value*/
        Symbol* sp; /*variable */
        pmatFunT pmatFun; /*pointer to math functions*/
        NodeT* next;
        NodeT* extra; /* for: if then else, and statement list */
    };
    NodeT* left; /* operators */
    NodeT* right;
};

/* Include the Bison-generated token definitions */
#include "kalk.tab.h"

/* prototypes in sym.c*/
Symbol* lookupSym(char* str);
Symbol* insertSym(char* s);
char* xstrdup(char* name);
void* xmalloc(size_t size);
void sys_error(char* str);

/* prototypes in kalk.c*/
NodeT* Opr4(int oper, NodeT* n1, NodeT* n2, NodeT* n3, NodeT* n4);
NodeT* Opr3(int oper, NodeT* n1, NodeT* n2, NodeT* n3);
NodeT* Opr2(int oper, NodeT* n1, NodeT* n2);
NodeT* Opr1(int oper, NodeT* n1);
NodeT* Opr0(int oper);
NodeT* AppendStmt(NodeT* list, NodeT* st);
NodeT* Var(Symbol *sp);
NodeT* NumConst(double value);
NodeT* MatFun(pmatFunT pmatFun, NodeT* expr);
NodeT* CreateCase(double value, NodeT* stmt);
NodeT* CreateDefaultCase(NodeT* stmt);
NodeT* AppendCase(NodeT* list, double value, NodeT* stmt);
NodeT* AppendDefaultCase(NodeT* list, NodeT* stmt);
void freeNode(NodeT* p);
double Execute(NodeT* n);
void yyerror(char* s);
int yyparse();
int yylex();

/*global variables*/
extern int lineno;
extern FILE* yyin;
/*jump on error*/
extern jmp_buf jumpdata;

#endif /* KALK_H */