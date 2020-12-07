%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "../symbolTable/symbolTable.h"
	#include "../AST/AST.h"
	#define printTree($$) verbose_mode ? printAST($$) : NULL

	int yylex(void);
	int yyerror(const char *s);
	int success = 1;
	#define YYDEBUG_LEXER_TEXT yytext
	Env *env;
	extern int yylineno;
	int verbose_mode = 0;
	extern int verbose_mode;
	Symbol_table *lookup(char *search,char *type);
%}


%define parse.error verbose

%union {
	struct abstract_syntax_tree *val;
	int type;
	int count;
}

%token <type> VOID
%token <val>  KUALA IF ELSE WHILE FOR INT FLOAT BOOL LT_OP LE_OP EQ_OP GT_OP GE_OP DIF_OP STRING  RETURN AT OR_OP AND_OP NOT INCRMT DECRMT
%token <val>  id
%token <val> string char_const
%token <val> float_const
%token <val> int_const

//%type <count>  param_list
%type <type> type_consts relop funct_types logic_op 
%type <val>  kuala program funct_list funct  param_dclr  simple_block block funct_body param_list
%type <val>  call_funct  expr expr_list logic rel   expr_statement stmt array_list
%type <val> rel_oper oper array_entry consts_list array_size dclr list_dclr array
%type <val> list_dclr_types attr_recive attr consts 


/* Operator precedence for mathematical operators */
%left '+' '-'
%left '*' '/'
%left '<' '>'

%nonassoc ELSE
%start program


%%
program : funct_list kuala funct_list	{$$ = makeList3($2, $1, $3); printTree($$);}
		| funct_list kuala 				{$$ = makeList2($2, $1); printTree($$);}
		| kuala funct_list 				{$$ = makeList2($1, $2); printTree($$);}
		| kuala  						{$$ = $1; printTree($$);}
		;

kuala  : KUALA funct_body 		{$$=makeAST(KUALA_AST,0,$2);}
	   | VOID KUALA funct_body 	{$$=makeAST(KUALA_AST,0,$3);}
	   | INT KUALA funct_body 	{$$=makeAST(KUALA_AST,$1,$3);}
	   ;

funct_list	: funct funct_list 	{$$ = makeList2($2, $1);}
			| funct
			;

funct  : funct_types id funct_body {$2->sym->type = $1; $$ = $2; $$=makeAST(FUNC,$2,$3); ht_set(env->hash,$2->sym->name,createSymbolFunct($2->sym->name,yylineno,$1,1));}
	   ;

funct_types	: type_consts
			| VOID {$$ = VOID;}
			;

funct_body 		: '(' ')'  simple_block  			{$$=makeAST(DCLR_FUNC,0,$3);}//{ $$=$3->count=0;}
				| '(' ')' ';'  						{$$=makeAST(DCLR_FUNC,0,0);}//{$$->count=0;}
				| '(' param_list ')' ';' 			{$$=makeAST(DCLR_FUNC,$2,0);}//{$$->count=$2;}
		    	| '(' param_list ')' simple_block 	{$$=makeAST(DCLR_FUNC,$2,$4);}//{ $$->count=$2; } 
				;
				
param_dclr 	: type_consts id 			{ $2->sym->type = $1; $$ = $2;}
			| type_consts id '[' ']' 	{$2->sym->type = $1; $$ = $2;}
			;

param_list : param_dclr ',' param_list 	{$$ = makeList2($3, $1);}
		   | param_dclr                  
		   | error {$$=NULL;}  					 // continue parsing  
		   ;

simple_block  : '{' '}' 		{$$=NULL;}
	   		  | '{' stmt '}'  	{ $$ = makeAST(BLOCK_STATEMENT, $2, 0);}
	   			;

call_funct   : id '(' expr_list ')' {$$ = makeAST(CALL_OP, $1, $3); Symbol_table *table = lookup($1->sym->name,"função"); 
					if( table ==  NULL){
						$$->hold_type=-1;
					}else{
						$$->hold_type=table->tipo;
					}
				}
			 | id '(' ')' {$$ = makeAST(CALL_OP, $1, 0); 
			 		Symbol_table *table = lookup($1->sym->name,"função"); 
					if( table ==  NULL){
						$$->hold_type=-1;
					}else{
						$$->hold_type=table->tipo;
					}
				}
			 ;

block  : simple_block 		{$$ = makeAST(BLOCK_STATEMENT, $1, 0);}
	   | simple_block stmt 	{$$ = makeAST(BLOCK_STATEMENT, $1, $2);}
	   ;

stmt       : IF '(' logic ')' block 								{$$ = makeAST(IF_STATEMENT,$3,$5);}
		   | IF '(' logic ')' stmt 									{$$ = makeAST(IF_STATEMENT,$3,$5);}
		   | ELSE IF '(' logic ')' block 							{$$ = makeAST(ELSE_IF_STATEMENT,$4,$6);}
		   | ELSE block 											{$$ = makeAST(ELSE_STATEMENT,$2,0);}
		   | WHILE '(' rel ')' block 								{$$ = makeAST(WHILE_STATEMENT,$3,$5);}
		   | FOR '(' expr_statement rel ';' attr ')' block 			{$$ = makeAST(FOR_STATEMENT,makeList3($3,$4,$6),$8);}
		   | FOR '(' expr_statement rel ';' attr ')' stmt 			{$$ = makeAST(FOR_STATEMENT,makeList3($3,$4,$6),$8);}
		   | expr_statement stmt 									{$$ = makeAST(BLOCK_STATEMENT, $1, $2);}
		   | block 
		   | expr_statement  										
		   | error {$$=NULL;}  // continue parsing 
		   ;

expr_statement	: dclr ';' 			
				| attr ';' 			
				| call_funct ';' 	
				| RETURN oper ';' 	{$$ = makeAST(RETURN_STATEMENT, $2, NULL);}
				| RETURN ';' 		{$$ = makeAST(RETURN_STATEMENT, NULL, NULL);}
				| error {$$=NULL;} 
				;

expr		: logic
			| rel
			| oper
			;

expr_list  	: expr ',' expr_list {$$ = makeAST(LIST, $1, $3);}
			| expr {$$ = $1;}
			;

logic : logic logic_op logic 	{$$ = makeAST($2, $1, $3);}
	  | NOT logic  				{$$ = makeAST(NOT, $2, NULL);}
	  |'(' logic ')' 			{$$=$2;}
	  | rel
	  ;

logic_op 	: OR_OP 	{$$ = OR;}
			| AND_OP 	{$$ = AND;}
			;

rel     : rel_oper relop rel_oper  {$$= makeAST($2, $1, $3);}
		| rel_oper 
		;

relop	: LE_OP 	{$$=LE_OP_AST;}
		| EQ_OP 	{$$=EQ_OP_AST;}
		| LT_OP 	{$$=LT_OP_AST;}
		| GE_OP 	{$$=GE_OP_AST;}
		| GT_OP 	{$$=GT_OP_AST;}
		| DIF_OP 	{$$=DIF_OP_AST;}
		;

rel_oper	: oper 
			| array_entry

oper   : oper '+' oper 	{
							$$= makeAST(PLUS_OP, $1, $3);
							if($1->hold_type!=$3->hold_type) printf("\e[1;93mSemantica - Valores de Operação incompatives; linha: %d\e[0m \n",yylineno);
							$$->hold_type=$1->hold_type;
						}
       | oper '-' oper 	{$$= makeAST(MINUS_OP, $1, $3);
	   						if($1->hold_type!=$3->hold_type) printf("\e[1;93mSemantica - Valores de Operação incompatives; linha: %d\e[0m \n",yylineno);
							$$->hold_type=$1->hold_type;
						   }
       | oper '*' oper 	{$$= makeAST(MUL_OP, $1, $3);
	   						if($1->hold_type!=$3->hold_type) printf("\e[1;93mSemantica - Valores de Operação incompatives; linha: %d\e[0m \n",yylineno);
							$$->hold_type=$1->hold_type;
	   					}
       | oper '/' oper 	{$$= makeAST(DIV_OP, $1, $3);
	   						if($1->hold_type!=$3->hold_type) printf("\e[1;93mSemantica - Valores de Operação incompatives; linha: %d\e[0m \n",yylineno);
							$$->hold_type=$1->hold_type;
						   }
       | oper '%' oper 	{$$= makeAST(REST_OP, $1, $3);
	   						if($1->hold_type!=$3->hold_type) printf("\e[1;93mSemantica - Valores de Operação incompatives; linha: %d\e[0m \n",yylineno);
							$$->hold_type=$1->hold_type;
	   					}
	   | '-' oper 		{$$= makeAST(MUL_OP, $2, makeNum(-1)); $$->hold_type=$2->hold_type;}
	   | '+' oper 		{$$= $2; $$->hold_type=$2->hold_type;}
	   | '(' oper ')' 	{$$=$2; $$->hold_type=$2->hold_type;}
	   | consts         {$$->hold_type=$1->hold_type;}
	   | id 			{$$->hold_type=$1->sym->type;}
	   | string         {$$->hold_type=STRING;}
	   | array_entry 
	   | call_funct     {$$->hold_type=$1->hold_type;}
	   ;

array_entry : array_entry '[' oper ']' 	{$$ = makeAST(SET_ARRAY_OP, $1, $3);}
			| id '[' oper ']'			{$$ = makeAST(SET_ARRAY_OP, $1, $3); } 
			;

consts_list : consts ',' consts_list  {$$ = makeList2($1, $3);}
			| consts  
			;

array	: '[' array_list ']'  	{$$ = $2;}
		| '[' consts_list ']'  	{$$ = $2;}
		;

array_list  : array ',' array_list 		{$$ = makeList2($1, $3);}
			| array 
			;


array_size	:array_size array_size 		{$$ = makeList2($1, $2);}
			|'[' consts ']'  			{$$ = $2;}
			|'[' id ']'       			{$$ = $2;}
			|'[' ']' 					{$$ = NULL;}
			;

dclr 	   :  list_dclr	 		 														
		   |  type_consts id array_size     			{
			   												$2->sym->type = $1; 
														    $$ = makeAST(SET_ARRAY_OP, $2, $3); 
															ht_set(env->hash,$2->sym->name,createSymbolBasic($2->sym->name,yylineno,$1));	
														} 
		   |  type_consts id array_size '=' array_list  {	
			   												$2->sym->type = $1; 
		   													$$ = makeAST(EX_EQ, makeAST(SET_ARRAY_OP, $2, $3), $5 );
															ht_set(env->hash,$2->sym->name,createSymbolBasic($2->sym->name,yylineno,$1));
														}
		   ;

list_dclr 	: list_dclr ',' list_dclr_types {   $$ = makeList2($1, $3); 
											
												$$->hold_type=$1->hold_type;
												if ($3->sym != NULL){
													ht_set(env->hash,$3->sym->name,createSymbolBasic($3->sym->name,yylineno,$$->hold_type));
												}else{
													ht_set(env->hash,$3->left->sym->name,createSymbolBasic($3->left->sym->name,yylineno,$$->hold_type));
												}

											}
			| type_consts list_dclr_types 	{ if($2->sym != NULL){ 
													$2->sym->type = $1; 
											    	ht_set(env->hash,$2->sym->name,createSymbolBasic($2->sym->name,yylineno,$1));
												}else{ 
													$2->left->sym->type = $1;
											    	ht_set(env->hash,$2->left->sym->name,createSymbolBasic($2->left->sym->name,yylineno,$1));
												}  
											  	$$ = $2;
												$$->hold_type = $1;
											}
			;

list_dclr_types : id '=' oper {$$=makeAST(EX_EQ,$1,$3);}
				| id
				;

attr_recive : oper
			| array_list
			;

attr       : id '=' attr_recive 			{ 
												$$ = makeAST(EX_EQ, $1, $3);  		
												Symbol_table *table = lookup($1->sym->name,"variavel");
												
												if(table == NULL){
													if (-1 != $3->hold_type) printf("\e[1;93mSemantico - Atribuição imcompativel; linha: %d\n \e[0m",yylineno);											  	
												}else{
													if (table->parms_count >= 1){
														printf("\e[1;93mSemantico - Atribuição em FUNÇÃO; linha: %d\n \e[0m",yylineno);	
													}else{
														if (table->tipo != $3->hold_type) printf("\e[1;93mSemantico - Atribuição imcompativel; linha: %d\n \e[0m",yylineno);											  														
													}
												}
											}
		   | array_entry '=' attr_recive 	{ $$ = makeAST(EX_EQ, $1, $3); }
		   | id INCRMT 						{ $$ = makeAST(EX_EQ, $1, makeAST(EX_EQ, $1,makeAST(PLUS_OP, $1, makeNum(1)))); }
	       | id DECRMT 						{ $$ = makeAST(EX_EQ, $1, makeAST(EX_EQ, $1,makeAST(MINUS_OP, $1, makeNum(1)))); }
		   | array_entry INCRMT 			{ $$ = makeAST(EX_EQ, $1, makeAST(EX_EQ, $1,makeAST(PLUS_OP, $1, makeNum(1))));}
		   | array_entry DECRMT 			{ $$ = makeAST(EX_EQ, $1, makeAST(EX_EQ, $1,makeAST(MINUS_OP, $1, makeNum(1)))); }
		   ;

type_consts            		: INT       	{$$=INT;}
							| FLOAT			{$$=FLOAT;}
							| BOOL			{$$=BOOL;}
							| STRING		{$$=STRING;}
							;

consts						: int_const  	{$$->hold_type=INT;} 								
							| char_const  	{$$->hold_type=STRING;}
							| float_const 	{$$->hold_type=FLOAT;}
							;

%%
Symbol_table *lookup(char *search,char* type) {
	Symbol_table *table = ht_get(env->hash,search);
	if (table == 0){
	 	printf("\e[1;93mSemantico - A %s '%s' não foi declarada; linha: %d\n \e[0m",type,search,yylineno); 	
		return NULL;
	}else{
		return table;
	}
	
}

int main(int argc,char *argv[])
{
	yydebug = 0;

	
 	
	env = createEnv();

	
	extern int verbose;
	extern int verbose_mode;

	 if( argc == 2 && strcmp(argv[1],"--verbose")==0) {
      verbose=1;
	  verbose_mode=1;
      printf("\n\n\e[1;32mVerbose Mode\e[0m\n\n");

      printf("\e[1;32m-->Analise Lexica & Sintatica & Semantica\e[0m\n");
    }


    yyparse();

	if(verbose){
		printEnv(env);
	}

	

    if(success)
    	printf("\n\n\e[1;32mPrograma sintaticamente correto ʕ·͡ᴥ·ʔ\e[0m \n\n");
	else printf("\n\n\e[1;31mPrograma sintaticamente incorreto ʕ·͡ᴥ·ʔ\e[0m \n\n");
    return 0;
}

int yyerror(const char *msg)
{
	extern int yylineno;
	extern int yyline;
	extern int yychar_count;

	printf("\e[1;34mSyntatic Error:\nErro próximo a linha(yylineno): %d\nErro próximo a linha(yyline): %d  coluna: %d\n\e[1;0mMenssage:\n  %s\e[0m \n\n ",yylineno,yyline, yychar_count, msg);
	success = 0;
	return 0;
}
