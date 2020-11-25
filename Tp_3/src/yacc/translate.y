%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "../symbolTable/symbolTable.h"
	int yylex(void);
	int yyerror(const char *s);
	int success = 1;
	#define YYDEBUG_LEXER_TEXT yytext
%}




%define parse.error verbose


%token int_const char_const float_const id string  
%token KUALA IF ELSE WHILE FOR INT FLOAT BOOL RELOP STRING VOID RETURN AT
%token LOGIC NOT INCRMT DECRMT

/* Operator precedence for mathematical operators */
%left '+' '-'
%left '*' '/'
%left '<' '>'

%nonassoc ELSE
%start program





%%
program : funct_list kuala funct_list
		| funct_list kuala
		| kuala funct_list
		| kuala
		;

kuala  : KUALA funct_body
	   | VOID KUALA funct_body
	   | INT KUALA funct_body
	   ;

funct_list	: funct funct_list
			| funct
			;

funct  : funct_dclr funct_body
	   | VOID id funct_body
	   ;


funct_body 		: '(' ')'  simple_block
				| '(' ')' ';'
				| '(' param_list ')' ';'
		    	| '(' param_list ')' simple_block
				;

simple_block  : '{' '}'
	   		  | '{' stmt '}'
	   			;

call_funct   : id '(' expr_list ')'
			 ;

block  : simple_block
	   | simple_block stmt
	   ;

stmt       : IF '(' logic ')' block
		   | IF '(' logic ')' stmt
		   | ELSE IF '(' logic ')' block
		   | ELSE block
		   | WHILE '(' rel ')' block
		   | FOR '(' expr_statement rel ';' attr ')' block
		   | FOR '(' expr_statement rel ';' attr ')' stmt
		   | block
		   | expr_statement stmt
		   | expr_statement
		   | error // continue parsing
		   ;

expr_statement	: dclr ';' 
				| attr ';' 
				| call_funct ';'
				| RETURN oper ';'
				| RETURN ';'
				| error
				;

expr		: logic
			| rel
			| oper
			;

expr_list  	: expr ',' expr_list
			| expr
			;

logic : logic LOGIC logic
	  | NOT logic
	  |'(' logic ')'
	  | rel
	  ;

rel     : rel_oper RELOP rel_oper   
		| rel_oper
		;

rel_oper	: oper
			| array_entry

oper   : oper '+' oper
       | oper '-' oper
       | oper '*' oper 
       | oper '/' oper 
       | oper '%' oper 
	   | '-' oper
	   | '+' oper
	   | '(' oper ')'
	   | consts
	   | id
	   | string
	   | array_entry
	   | call_funct
	   ;

array_entry : array_entry '[' oper ']'
			| id '[' oper ']'
			;


funct_dclr 	: type_consts id
		   	;

param_dclr 	: type_consts id
			| type_consts id '[' ']'
			;

param_list : param_dclr ',' param_list 
		   | param_dclr
		   | error // continue parsing 
		   ;

consts_list : consts ',' consts_list
			| consts
			;

array	: '[' array_list ']'
		| '[' consts_list ']'
		;

array_list  : array ',' array_list
			| array
			;


array_size	:array_size array_size
			|'[' consts ']'
			|'[' id ']'
			|'[' ']'
			;

dclr 	   :  type_consts list_dclr
		   |  type_consts id array_size
		   |  type_consts id array_size '=' array_list
		   ;

list_dclr : list_dclr ',' list_dclr
			| id '=' oper
			| id
			;

attr_recive : oper
			| array_list
			;

attr       : id '=' attr_recive
		   | array_entry '=' attr_recive
		   | id INCRMT
	       | id DECRMT
		   | array_entry INCRMT
		   | array_entry DECRMT
		   ;

type_consts            		: INT
							| FLOAT
							| BOOL
							| STRING
							;

consts						: int_const 											
							| char_const
							| float_const
							;

%%

int main(int argc,char *argv[])
{
	yydebug = 0;

	symbolList symbollist;
    createList(&symbollist);


	extern int verbose;
	 if( argc == 2 && strcmp(argv[1],"--verbose")==0) {
      verbose=1;
      printf("\n\nVerbose Mode\n\n %s\n", argv[1]);
    }

    yyparse();

	

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
