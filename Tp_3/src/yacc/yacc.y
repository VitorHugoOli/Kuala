%{
	#include<stdio.h>
	int yylex(void);
	int yyerror(const char *s);
	int success = 1;
%}

%token int_const char_const float_const id string enumeration_const storage_const type_const qual_const struct_const enum_const DEFINE
%token IF FOR DO WHILE BREAK SWITCH CONTINUE RETURN CASE DEFAULT GOTO SIZEOF PUNC or_const and_const eq_const shift_const rel_const inc_const
%token point_const param_const ELSE HEADER

/* Operator precedence for mathematical operators */
%left '+' '-'
%left '*' '/'

%nonassoc "then"
%nonassoc ELSE
%define parse.error verbose
%start program_unit

%%
kuala    : '(' ')''{' block '}'



%%

int main()
{
    yyparse();
    if(success)
    	printf("Parsing Successful\n");
    return 0;
}

int yyerror(const char *msg)
{
	extern int yylineno;
	printf("Parsing Failed\nLine Number: %d %s\n",yylineno,msg);
	success = 0;
	return 0;
}
