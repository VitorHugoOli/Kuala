//
// Created by vitor on 11/25/20.
//

#include <stdio.h>
#include "symbolTable.h"

void main() {
    symbolList a;
    createList(&a);
    Symbol *b = createString("asknxdojas\n");
    Symbol *c = createID("asknxdojas\n");
    Symbol *d = createNumber("190");
    Symbol *e = createRelop("<",LT);
    Symbol *f = createLogic("&&",AND);

    printf("3\n");
    insertSymbol(&a, b);
    insertSymbol(&a, c);
    insertSymbol(&a, d);
    insertSymbol(&a, e);
    insertSymbol(&a, f);


    printf("%s", a.head->next->lexema);
    printf("%s", a.head->next->next->lexema);
    printf("%s", a.head->next->next->next->lexema);


}