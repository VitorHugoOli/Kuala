#include "hash.h"

Symbol_table* createSymbolBasic(char *offset,int lineo,int tipo){
    Symbol_table *symb = (Symbol_table *) malloc(sizeof(Symbol_table));
	symb->offset = offset;  
    symb->lineo=lineo;
    symb->tipo=tipo;


	symb->parms_count=-1;
    return symb;
}


Symbol_table* createSymbolFunct(char *offset,int lineo,int tipo,int parms_count){
    Symbol_table *symb = (Symbol_table *) malloc(sizeof(Symbol_table));
	symb->offset = offset;  
    symb->lineo=lineo;
    symb->tipo=tipo;


	symb->parms_count=parms_count;
    return symb;
}


/* Create a new hashtable. */
hashtable_t *ht_create( int size ) {

	hashtable_t *hashtable = NULL;
	int i;

	if( size < 1 ) return NULL;

	/* Allocate the table itself. */
	if( ( hashtable = malloc( sizeof( hashtable_t ) ) ) == NULL ) {
		return NULL;
	}

	/* Allocate pointers to the head nodes. */
	if( ( hashtable->table = malloc( sizeof( entry_t * ) * size ) ) == NULL ) {
		return NULL;
	}
	for( i = 0; i < size; i++ ) {
		hashtable->table[i] = NULL;
	}

	hashtable->size = size;

	return hashtable;	
}

/* Hash a string for a particular hash table. */
int ht_hash( hashtable_t *hashtable, char *key ) {

	unsigned long int hashval = 5381;
	int i = 0;

	/* Convert our string to an integer */
	while( hashval < ULONG_MAX && i < strlen( key ) ) {
		hashval = hashval << 8;
		hashval += key[ i ];
		i++;
	}

	return hashval % hashtable->size;
}

/* Create a key-value pair. */
entry_t *ht_newpair( char *key, Symbol_table *value ) {
	entry_t *newpair;

	if( ( newpair = malloc( sizeof( entry_t ) ) ) == NULL ) {
		return NULL;
	}

	if( ( newpair->key = strdup( key ) ) == NULL ) {
		return NULL;
	}

	if( ( newpair->value =  value  ) == NULL ) {
		return NULL;
	}

	newpair->next = NULL;

	return newpair;
}

/* Insert a key-value pair into a hash table. */
void ht_set( hashtable_t *hashtable, char *key, Symbol_table *value ) {
	int bin = 0;
	entry_t *newpair = NULL;
	entry_t *next = NULL;
	entry_t *last = NULL;

	bin = ht_hash( hashtable, key );

	next = hashtable->table[ bin ];

	while( next != NULL && next->key != NULL && strcmp( key, next->key ) > 0 ) {
		last = next;
		next = next->next;
	}

	/* There's already a pair.  Let's replace that string. */
	if( next != NULL && next->key != NULL && strcmp( key, next->key ) == 0 ) {

		free( next->value );
		next->value = value;

	/* Nope, could't find it.  Time to grow a pair. */
	} else {
		newpair = ht_newpair( key, value );

		/* We're at the start of the linked list in this bin. */
		if( next == hashtable->table[ bin ] ) {
			newpair->next = next;
			hashtable->table[ bin ] = newpair;
	
		/* We're at the end of the linked list in this bin. */
		} else if ( next == NULL ) {
			last->next = newpair;
	
		/* We're in the middle of the list. */
		} else  {
			newpair->next = next;
			last->next = newpair;
		}
	}
}

/* Retrieve a key-value pair from a hash table. */
Symbol_table *ht_get( hashtable_t *hashtable, char *key ) {
	int bin = 0;
	entry_t *pair;

	bin = ht_hash( hashtable, key );

	/* Step through the bin, looking for our value. */
	pair = hashtable->table[ bin ];
	while( pair != NULL && pair->key != NULL && strcmp( key, pair->key ) > 0 ) {
		pair = pair->next;
	}

	/* Did we actually find anything? */
	if( pair == NULL || pair->key == NULL || strcmp( key, pair->key ) != 0 ) {
		return NULL;
	} else {
		return pair->value;
	}
}

void printTable(hashtable_t *hashtable){
    entry_t *pair;
    for (int i = 0; i < hashtable->size; i++){
        pair = hashtable->table[ i ];
        while( pair != NULL && pair->key != NULL) {
			if (pair->value->parms_count >= 1){
				printf("├──Func id -> %s \n",pair->key);
				printf("|  ├──quantidade de parametro -> %d \n",pair->value->parms_count);
				printf("|  ├──offset -> %p \n",pair->value->offset);
				printf("|  ├──linha -> %d \n",pair->value->lineo);
				printf("|  └──tipo -> %d\n",pair->value->tipo);
			}else{
				printf("├──Id -> %s \n",pair->key);
				printf("|  ├──offset -> %p \n",pair->value->offset);
				printf("|  ├──linha -> %d \n",pair->value->lineo);
				printf("|  └──tipo -> %d\n",pair->value->tipo);
			}
           
			pair = pair->next;
	    }
    }
}
