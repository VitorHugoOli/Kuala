%{
	#include<stdio.h>
	#include <string.h>
	int yylex(void);
	int yyerror(const char *s);
	int success = 1;
	#define YYDEBUG_LEXER_TEXT yytext
%}

%define parse.error verbose


%token int_const char_const float_const id string  
%token KUALA IF ELSE WHILE FOR INT FLOAT BOOL OP RELOP STRING VOID RETURN AT
%token AND OR NOT LE GE LT GT EQ NE INCRMT DECRMT

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
	   ;

funct_list	: funct funct_list
			| funct
			;

funct  : funct_dclr funct_body
	   | VOID id funct_body
	   ;


funct_body 		: '(' ')'  block
				| '(' param_list ')'
		    	| '(' param_list ')' block
				;

call_funct   : id '(' expr_list ')'
			 ;

block  : '{' '}'
	   | '{' '}' stmt
	   | '{' stmt '}'
	   | '{' stmt '}' stmt
	   ;

stmt       : IF '(' logic ')' block
		   | IF '(' logic ')' stmt
		   | ELSE IF '(' logic ')' block
		   | ELSE block
		   | WHILE '(' rel ')' block
		   | FOR '(' expr_statement rel ';' attr ')' block
		   | FOR '(' expr_statement rel ';' attr ')' stmt
		   | block
		   | funct
		   | expr_statement stmt
		   | expr_statement
		   | error // continue parsing
		   ;

expr_statement	: dclr ';' 
				| attr ';' 
				| call_funct ';'
				| error
				;

expr		: logic
			| rel
			| oper
			| oper_str
			| attr
			| string
			;

expr_list  : expr ',' expr_list
			| expr
			;

logic : logic AND logic 
	  | logic OR logic
	  | logic NOT logic
	  |'(' logic ')'
	  | rel
	  ;

rel     : oper LT oper   
	    | oper GT oper
	    | oper LE oper
	    | oper GE oper
	    | oper EQ oper
	    | oper NE oper
		;

oper   : oper '+' oper 
	   | oper '-' oper	
	   | oper '*' oper
	   | oper '/' oper //division by 0
	   | oper '%' oper
	   | '(' oper ')'
	   | consts 
	   | array_entry
	   | id
	   ;

array_entry : array_entry '[' consts ']'
			| array_entry '[' id ']'
			| id '[' consts ']'
			| id '[' id ']'
			;

oper_str : oper_str '+' oper_str
		 | id
		 | string
		 | '(' oper_str ')'
		 ;


dclr 	   :  type_consts id_list 
		   |  type_consts id '[' consts ']' 
		   |  type_consts id '[' ']'
		   ;

id_list : id ',' id_list
		| id
		;

funct_dclr : type_consts id
		   ;

param_list : funct_dclr ',' param_list
		   | funct_dclr
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

attr_types 	: dclr
			| id
			| array_entry
			;

attr       : attr_types '=' oper 
		   | attr_types '=' string
		   | attr_types '=' array
		   | attr_types '=' array_entry
		   | id INCRMT
	       | id DECRMT
		   | array_entry INCRMT
		   | array_entry DECRMT
		   | 
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
	yydebug= 0;

	extern int verbose;
	 if( argc == 2 && strcmp(argv[1],"--verbose")==0) {
      verbose=1;
      printf("\n\nVerbose Mode\n\n %s\n", argv[1]);
    }

    yyparse();

	

    if(success)
    	printf("\n\n\e[1;32mParsing Successful ʕ·͡ᴥ·ʔ \n\n");
    return 0;
}

int yyerror(const char *msg)
{
	extern int yylineno;
	extern int yyline;
	extern int yychar_count;

	printf("\e[1;34mSyntatic Error:\nLine Number(yylineno): %d\nLine Number(yyline): %d Char Number: %d\n\e[1;0mMenssage:\n  %s\n\e[0m",yylineno,yyline, yychar_count, msg);
	success = 0;
	return 0;
}
