/* file: kalk.c */

#include <math.h>
#include "kalk.h"
#include "kalk.tab.h"

jmp_buf   jumpdata; 

NodeT* Opr4(int oper, NodeT* n1, NodeT* n2, NodeT* n3, NodeT* n4) 
{
	NodeT* n = xmalloc(sizeof(NodeT));
	n->kind = kindOpr;
	n->oper = oper;
	n->left  = n1;
	n->right = n2;
	n->next  = n3;
	n->extra = n4;
	return n;
}

NodeT* Opr3(int oper, NodeT* n1, NodeT* n2, NodeT* n3) {
	return Opr4(oper, n1, n2, n3, NULL);
}

NodeT* Opr2(int oper, NodeT* n1, NodeT* n2) {
	return Opr3(oper, n1, n2, NULL);
}

NodeT* Opr1(int oper, NodeT* n1) {
	return Opr3(oper, n1, NULL, NULL);
}

NodeT* Opr0(int oper) {
    return Opr1(oper, NULL);
}

NodeT* NumConst(double value) 
{
	NodeT* n = xmalloc(sizeof(NodeT));        
	n->kind = kindNum;
	n->value = value;
	return n;
}

NodeT* Var(Symbol* sp) 
{
	NodeT* n = xmalloc(sizeof(NodeT));    
	n->kind = kindVar;
	n->sp = sp;
	return n;
}

NodeT* MatFun(pmatFunT pmatFun, NodeT* expr) 
{     
	NodeT* n = Opr3(0, expr, NULL, NULL);
	n->kind = kindMatFun;
	n->pmatFun = pmatFun;	
	return n;
}

NodeT* AppendStmt(NodeT* list, NodeT* stmt) 
{
	NodeT* n = Opr1(STMT_LIST, stmt);
	if(!list)
		list = n;
	else {
		NodeT* p = list;
		while(p->next != NULL) p = p->next;
		p->next= n;
	}
	return list; 
}

NodeT* CreateCase(double value, NodeT* stmt) {
    NodeT* caseVal = NumConst(value);
    return Opr2(CASE, caseVal, stmt);
}

NodeT* CreateDefaultCase(NodeT* stmt) {
    return Opr2(DEFAULT, NULL, stmt);
}

NodeT* AppendCase(NodeT* list, double value, NodeT* stmt) {
    NodeT* newCase = CreateCase(value, stmt);
    if (!list)
        return newCase;
    
    NodeT* p = list;
    while (p->next != NULL) p = p->next;
    p->next = newCase;
    return list;
}

NodeT* AppendDefaultCase(NodeT* list, NodeT* stmt) {
    NodeT* defaultCase = CreateDefaultCase(stmt);
    if (!list)
        return defaultCase;
    
    NodeT* p = list;
    while (p->next != NULL) p = p->next;
    p->next = defaultCase;
    return list;
}

void freeNode(NodeT* n) {
	if (!n) return;
	if (n->kind == kindOpr) {
		freeNode(n->left);
		freeNode(n->right);
		freeNode(n->next);
		freeNode(n->extra);
	}    
	free (n);
	n = NULL;
}

double Execute(NodeT* n)
{
    static int breakFlag = 0;
    static int continueFlag = 0;
    
    if (!n) return 0;
    if (breakFlag || continueFlag) {
        // Allow execution to continue through non-loop constructs
        if (n->kind == kindOpr && (n->oper == WHILE || n->oper == FOR || n->oper == SWITCH))
            return 0;
        // If we're in a STMT_LIST, we'll handle this specially below
        if (n->kind != kindOpr || n->oper != STMT_LIST)
            return 0;
    }
    
    if (n->kind == kindNum) return n->value;
    else if (n->kind == kindMatFun) return (*n->pmatFun)(Execute(n->left));
    else if (n->kind == kindVar) {
        if (!n->sp) {
            yyerror("Variable not defined\n");
            return 0;
        }
        return n->sp->val;
    }
    else if (n->kind == kindOpr) switch(n->oper)
    {
        case WHILE: {
            while (Execute(n->left) && !breakFlag) {
                Execute(n->right);
                if (continueFlag) {
                    continueFlag = 0;  // Reset continue flag after one iteration
                }
            }
            breakFlag = 0;  // Reset break flag after exiting the loop
            return 0;
        }
        case FOR: {
            for (Execute(n->left); Execute(n->right) && !breakFlag; Execute(n->next)) {
                Execute(n->extra);
                if (continueFlag) {
                    continueFlag = 0;  // Reset continue flag after one iteration
                }
            }
            breakFlag = 0;  // Reset break flag after exiting the loop
            return 0;
        }
        case BREAK:
            breakFlag = 1;
            return 0;
        case CONTINUE:
            continueFlag = 1;
            return 0;
        case SWITCH: {
            double switchVal = Execute(n->left);
            NodeT* caseNode = n->right;
            int caseMatched = 0;
            
             while (caseNode) {
        if (caseNode->kind == kindOpr) {
            if (caseNode->oper == CASE) {
                // If we found the correct case or a previous case matched
                if (caseMatched || Execute(caseNode->left) == switchVal) {
                    caseMatched = 1;
                    Execute(caseNode->right);
                }
            } 
            else if (caseNode->oper == DEFAULT && !caseMatched) {
                // Execute default case only if no case matched
                Execute(caseNode->right);
                caseMatched = 1;
            }
        }
        caseNode = caseNode->next; // Move to the next case
    }  // Reset break flag after exiting the switch
            return 0;
        }
        case IF:
            if (Execute(n->left)) Execute(n->right);
            else if (n->next) Execute(n->next);
            return 0;
        case '?':
            if (Execute(n->left)) return Execute(n->right);
            else return Execute(n->next);
        case PRINT:
            printf("> %g\n", Execute(n->left)); 
            return 0;
        case STMT_LIST: {
            NodeT* current = n;
            while (current && !(breakFlag || continueFlag)) {
                Execute(current->left);
                current = current->next;
            }
            return 0;
        }
        case '=':
            return n->left->sp->val = Execute(n->right);
        case UMINUS:
            return -Execute(n->left);
        case '+':
            return Execute(n->left) + Execute(n->right);
        case '-':
            return Execute(n->left) - Execute(n->right);
        case '*':
            return Execute(n->left) * Execute(n->right);
        case '/': {
            double op2 = Execute(n->right);
            if (op2 == 0) {
                yyerror("Zero divide\n");
                op2 = 1;
            }
            return Execute(n->left) / op2;
        }
        case '^': {
            double op2 = Execute(n->right);
            return pow(Execute(n->left), op2);
        }
        case '<':
            return Execute(n->left) < Execute(n->right);
        case '>':
            return Execute(n->left) > Execute(n->right);
        case GE:
            return Execute(n->left) >= Execute(n->right);
        case LE:
            return Execute(n->left) <= Execute(n->right);
        case NE:
            return Execute(n->left) != Execute(n->right);
        case EQ:
            return Execute(n->left) == Execute(n->right);
        default:
            yyerror("Bad operator\n");
            return 0;
    }
    return 0; /*never reached*/
}

 
int main(int argc, char* argv[]) { 
 
 if(argc == 2) { 
  yyin = fopen(argv[1], "rt");     
  if (yyin == NULL) {  
   printf ("Ne moze otvoriti datoteku: %s", argv[1]); 
   exit(1); 
  } 
 } 
 else 
  yyin = stdin; 
 
 setjmp(jumpdata);     
 yyparse(); 
 return 0; 
} 
