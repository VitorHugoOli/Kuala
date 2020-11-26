#include "symbolTable.h"


void createList(symbolList *list) {
    list->head = (Symbol *) malloc(sizeof(Symbol));
    list->head->next = NULL;
    list->last = list->head;
    list->size = 0;
}


int getSymbol(symbolList *list, Symbol s) {
    Symbol *atual = list->head->next;

    while (atual != NULL) {
        if (checkSymbol(*atual, s))
            return 1;

        atual = atual->next;
    }

    return 0;
}

int insertSymbol(symbolList *list, Symbol *s) {
    
    if (getSymbol(list, *s) == 0) {
        list->last->next = s;
        list->last->next->next = NULL;

        list->last = list->last->next;
        list->size++;
        return 1;
    }

    return 0;
}

int removeSymbol(symbolList *list) {
    Symbol *atual = list->head;

    if (list->head->next == NULL) return 0;

    while (atual->next->next != NULL)
        atual = atual->next;

    free(atual->next);
    atual->next = NULL;
    list->size--;
    list->last = atual;

    return 1;

}


int checkSymbol(Symbol s1, Symbol s2) {
    return (s1.tok == s2.tok && s1.op == s2.op && strcmp(s1.lexema,s2.lexema));
}

Symbol createSymbol() {

}

void printSymbols(symbolList *list) {

}

void clear(symbolList *list) {
    Symbol *atual = list->head;
    Symbol *anterior = NULL;
    while (atual != NULL) {
        anterior = atual;
        atual = atual->next;
        free(anterior);
    }
}


Symbol* createString(char *lexema){
    Symbol *s = (Symbol *) malloc(sizeof(Symbol));
    s-> tok = STRING_TOK;
    s-> op = NONE;
    strcpy(s-> lexema, lexema);
    return s;
}


Symbol* createID(char *lexema){
     Symbol *s = (Symbol *) malloc(sizeof(Symbol));
    s-> tok = ID_TOK;
    s-> op = NONE;
    strcpy(s-> lexema, lexema);
    return s;
}

Symbol* createNumber(char *lexema){
 Symbol *s = (Symbol *) malloc(sizeof(Symbol));
    s-> tok = NUMBER_TOK;
    s-> op = NONE;
    strcpy(s-> lexema, lexema);
    return s;
}

Symbol* createRelop(char *lexema, enum operators op){
 Symbol *s = (Symbol *) malloc(sizeof(Symbol));
    s-> tok = RELOP_TOK;
    s-> op = op;
    strcpy(s-> lexema, lexema);
    return s;
}

Symbol* createLogic(char *lexema, enum operators op){
 Symbol *s = (Symbol *) malloc(sizeof(Symbol));
    s-> tok = LOGIC_TOK;
    s-> op = op;
    strcpy(s-> lexema, lexema);
    return s;
}

void printSymbolList(symbolList* list){
    Symbol *teste = list->head->next;
    printf("\n -------------------------------- \n\n");
    while(NULL != teste){ //Percorre todo o vetor palavra ate encontrar a letra que corresponde a primeira letra
        printf("token %u\n",teste->tok);
        printf("Operador %u\n",teste->op);
        printf("Lexema %s\n",teste->lexema);
        printf("\n -------------------------------- \n\n");
        teste = teste->next;
    }

}