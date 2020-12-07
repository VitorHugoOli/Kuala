#include <stdio.h>
#include <ctype.h>
#include <string.h>

//#define DEBUG

#define FALSE 0
#define TRUE 1

enum code {
	LIST,
	NUM,
    FLT,
	STR,
	SYM,
    AND,
    OR,
	EX_EQ,
	PLUS_OP,
	MINUS_OP,
	MUL_OP,
    DIV_OP,
    REST_OP,
	GET_ARRAY_OP,
	SET_ARRAY_OP,
	CALL_OP,
	DCLR_FUNC,
	FUNC,
	KUALA_AST,
//	PRINTLN_OP,
	IF_STATEMENT,
	ELSE_IF_STATEMENT,
	ELSE_STATEMENT,
	BLOCK_STATEMENT,
	RETURN_STATEMENT,
	WHILE_STATEMENT,
	FOR_STATEMENT,
	LE_OP_AST,
	EQ_OP_AST,
	LT_OP_AST,
	GE_OP_AST,
	GT_OP_AST,
	DIF_OP_AST,
};

typedef struct abstract_syntax_tree {
	enum code op;
	int val;
    float val_float;
	int hold_type; // Variavel auxilar para transmitir o tipo das variaveis 
	int hold_count;
	struct symbol *sym;
	struct abstract_syntax_tree *left, *right;
	char *str;
} AST;

typedef struct symbol {
	char *name;
	int type, pointer;
} Symbol;

#define MAX_SYMBOLS 10000

extern Symbol SymbolTable[];
extern int n_symbols;

AST *makeSymbol(char *name);
Symbol *lookupSymbol(char *name);
Symbol *getSymbol(AST *p);

AST *makeNum(int val);
AST *makeFloat(char *val);
AST *makeStr(char *s);
AST *makeAST(enum code op, AST *right, AST *left);


void printAST(AST *p);

#define makeList1(x1) makeAST(LIST, x1, NULL)
#define makeList2(x1, x2) makeAST(LIST, x1, makeAST(LIST, x2, NULL))
#define makeList3(x1, x2, x3) makeAST(LIST, x1, makeAST(LIST, x2, makeAST(LIST, x3, NULL)))


