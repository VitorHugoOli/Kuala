#include <stdlib.h>
#include "AST.h"

// for debug
char *code_name(enum code op)
{
	switch (op) {
	case LIST:
		return "LIST";
	case NUM:
		return "NUM";
	case STR:
		return "STR";
	case SYM:
		return "SYM";
	case EX_EQ:
		return "EX_EQ";
	case PLUS_OP:
		return "PLUS_OP";
	case MINUS_OP:
		return "MINUS_OP";
	case MUL_OP:
		return "MUL_OP";
	case DIV_OP:
		return "DIV_OP";
	case GET_ARRAY_OP:
		return "GET_ARRAY_OP";
	case SET_ARRAY_OP:
		return "SET_ARRAY_OP";
	case CALL_OP:
		return "CALL_OP";
	case AND:
		return "AND";
	case OR:
		return "OR";
	case IF_STATEMENT:
		return "IF_STATEMENT";
	case ELSE_IF_STATEMENT:
		return "ELSE_IF_STATEMENT";
	case ELSE_STATEMENT:
		return "ELSE_STATEMENT";
	case BLOCK_STATEMENT:
		return "BLOCK_STATEMENT";
	case RETURN_STATEMENT:
		return "RETURN_STATEMENT";
	case WHILE_STATEMENT:
		return "WHILE_STATEMENT";
	case FOR_STATEMENT:
		return "FOR_STATEMENT";
	case LE_OP_AST:
		return "LE_OP";
	case EQ_OP_AST:
		return "EQ_OP";
	case LT_OP_AST:
		return "LT_OP";
	case GE_OP_AST:
		return "GE_OP";
	case GT_OP_AST:
		return "GT_OP";
	case DIF_OP_AST:
		return "DIF_OP";
	case DCLR_FUNC:
		return "DCLR_FUNC";
	case FUNC:
		return "FUNC";
	case KUALA_AST:
		return "KUALA_AST";
	default:
		return "???";
	}
}
void _printAST(AST *p,int num)
{
	if(num==7){
		num=1;
	}

	if (p == NULL) {
		printf("()");
		return;
	}
	switch (p->op) {
	case NUM:
		printf("%d", p->val);
		break;
	case FLT:
		printf("%f", p->val_float);
		break;
	case STR:
		printf("'%s'", p->str);
		break;
	case SYM:
		printf("'%s'", p->sym->name);
		break;
	case LIST:
		printf("(LIST ");
		while (p != NULL) {
			_printAST(p->left,num+1);
			
			p = p->right;
			if (p != NULL) {
				printf(" ");
			}
			
		}
		printf(")");
		break;
	default:
		printf("(%s ",code_name(p->op));
		
		_printAST(p->left,num+1);
		printf(" ");
		_printAST(p->right,num+1);
		
		printf(")");
		
	}
	fflush(stdout);
}
void printAST(AST *p)
{
	printf("\n\n\e[32;1mCodigo Intermediario - Abstract Syntax Tree\n\033[35m");
	_printAST(p,1);
	printf("\033[0m\n");
}


Symbol SymbolTable[MAX_SYMBOLS];
int n_symbols = 0;

AST *makeNum(int val)
{
	AST *p = (AST *)malloc(sizeof(AST));
	p->op = NUM;
	p->val = val;
	return p;
}

AST *makeFloat(char *val)
{
	AST *p = (AST *)malloc(sizeof(AST));
	p->op = FLT;
	p->val_float = atof(val);
	return p;
}


AST *makeStr(char *s)
{
	AST *p = (AST *)malloc(sizeof(AST));
	p->op = STR;
	p->str = s;
	return p;
}

AST *makeAST(enum code op, AST *left, AST *right)
{
	AST *p = (AST *)malloc(sizeof(AST));
	p->op = op;
	p->left = left;
	p->right = right;
	return p;
}

Symbol *lookupSymbol(char *name)
{
	Symbol *sp = NULL;
	for (int i=0; i < n_symbols; i++) {
		if (strcmp(SymbolTable[i].name, name) == 0) {
			sp = &SymbolTable[i];
			break;
		}
	}
	if (sp == NULL) {
		sp = &SymbolTable[n_symbols++];
		sp->name = strdup(name);
	}
	return sp;
}

AST *makeSymbol(char *name)
{
	AST *p = (AST *)malloc(sizeof(AST));
	p->op = SYM;
	p->sym = lookupSymbol(name);
	return p;
}

Symbol *getSymbol(AST *p)
{
	//printf("getSymbol [%x]\n", p);
	if (!p) fprintf(stderr, "AST is null at getSymbol!\n");
	if (p->op != SYM) {
		fprintf(stderr, "bad access to symbol\n");
		printAST(p);
		printf("\n");
		exit(1);
	}
	return p->sym;
}
