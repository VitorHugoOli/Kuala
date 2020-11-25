#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum tokens {
    STRING_TOK = 0,
    ID_TOK = 10,
    NUMBER_TOK = 30,
    RELOP_TOK = 50,
    LOGIC_TOK = 60
};


enum operators {
    LT =1,  
    LE =2,  
    EQ =3,
    NE =4,
    GT =5,
    GE =6,
    AND = 7,
    OR = 8,
    NONE = 10
};

typedef struct symbol {
	enum tokens tok;
    enum operators op;
    char *lexema;
    struct symbol *next;
} Symbol;

typedef struct symbolList {
	Symbol *head, *last;
    int size;
} symbolList;

void createList(symbolList *list);
int insertSymbol(symbolList *list, Symbol *s);
int removeSymbol(symbolList *list);
int getSymbol(symbolList *list, Symbol s);
void printSymbols(symbolList *list);
void clear(symbolList *list);
int checkSymbol(Symbol s1, Symbol s2);


Symbol* createString(char *lexema);
Symbol* createID(char *lexema);
Symbol* createNumber(char *lexema);
Symbol* createRelop(char *lexema, enum operators);
Symbol* createLogic(char *lexema, enum operators);



