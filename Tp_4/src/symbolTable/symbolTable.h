#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"



typedef struct env {
    hashtable_t *hash;
    struct env *next;
} Env;

Env *createEnv();
void printEnv(Env *env);
