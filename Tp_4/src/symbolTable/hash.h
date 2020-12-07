#define _XOPEN_SOURCE 500 /* Enable certain library functions (strdup) on linux.  See feature_test_macros(7) */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>




typedef struct symbol_table {
    char *offset;
    int tipo;
    int lineo;
	int parms_count;
} Symbol_table;


struct entry_s {
	char *key;
	Symbol_table *value;
	struct entry_s *next;
};

typedef struct entry_s entry_t;

struct hashtable_s {
	int size;
	struct entry_s **table;	
};




typedef struct hashtable_s hashtable_t;
void ht_set( hashtable_t *hashtable, char *key, Symbol_table *value );
Symbol_table *ht_get( hashtable_t *hashtable, char *key );
hashtable_t *ht_create( int size );
Symbol_table *createSymbolBasic(char *offset,int lineo,int tipo_recv);
Symbol_table *createSymbolFunct(char *offset,int lineo,int tipo_return,int parms_count);
void printTable(hashtable_t *hashtable);