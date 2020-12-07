#include "symbolTable.h"


Env *createEnv() {
    Env *env = (Env *) malloc(sizeof(Env));
    env->hash = ht_create(65536);
    env->next=NULL;
    return env;
}


void printEnv(Env *env){
    printf("\n\n\e[1;32mTabela de símbolos!\e[0m\n");
    printTable(env->hash);
}
