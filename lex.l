
%{ 

#include "prints.h"
#include "defines.h"

%} 
 
%option noyywrap 

/* definicoes regulares */ 

delim [ \t\n] 
ws {delim}+ 
upperCase [A-Z]
lowerCase [a-z]
bothCase [A-Za-z]
digit [0-9]  
id {bothCase}({bothCase}|{digit})*
positive \+?{digit}+ 
negative \-[1-9]{digit}*
float \.{digit}+ 
decimal {positive}{float}
decimalNegative \-{digit}+{float}
especialChar [;|=|,|{|}|(|)|\[|\]|?|:|&|||^|!|~|%|<|>|\'|\']
string \"(\\.|[^\"])*\"
simpleComments \/\/(.|[^\n])*
blockComments [/][*]([^*]|[*]*[^*/])*[*][/]

%% 

{simpleComments}                                                      {bluePrint("Foi encontrado um comentario simples.",yytext);}

{blockComments}                                                       {bluePrint("Foi encontrado um comentario em bloco.",yytext);}

{ws}		;

{string}                                                              {bluePrint("Foi encontrado uma STRING.",yytext);}

kuala                                                                 {bluePrint("Foi encontrado um Kuala.",yytext);}

"ʕ·͡ᴥ·ʔ"                                                                 {bluePrint("Foi encontrado um  ʕ·͡ᴥ·ʔ.",yytext);}

iguana                                                                {bluePrint("Foi encontrado um IF.",yytext);}

eel                                                                   {bluePrint("Foi encontrado um ELSE.",yytext);}

whale                                                                 {bluePrint("Foi encontrado um WHILE.",yytext);}

fox                                                                   {bluePrint("Foi encontrado um FOR.",yytext);}

ibis                                                                  {bluePrint("Foi encontrado um INT.",yytext);}

frog                                                                  {bluePrint("Foi encontrado um FLOAT.",yytext);}

bug                                                                   {bluePrint("Foi encontrado um BOOL.",yytext);}

snake                                                                 {bluePrint("Foi encontrado um STRING.",yytext);}

viper                                                                 {bluePrint("Foi encontrado um void.",yytext);}

{id}	                                                              {bluePrint("Foi encontrado um ID.",yytext);}

{positive}                                                            {bluePrint("Foi encontrado um numero inteiro positivo.",yytext);}

{negative}                                                            {bluePrint("Foi encontrado um numero inteiro negativo.",yytext);}

{decimal}                                                             {bluePrint("Foi encontrado um numero com parte decimal.",yytext);}

"+"                                                                   {bluePrint("Foi encontrado um +.",yytext);}//yylval = PLUS; return(OP);

"-"                                                                   {bluePrint("Foi encontrado um -.",yytext);}//yylval = MINUS; return(OP);

"*"                                                                   {bluePrint("Foi encontrado um *.",yytext);}//yylval = TIMES; return(OP);

"/"                                                                   {bluePrint("Foi encontrado um /.",yytext);}//yylval = DIVIDE; return(OP);

"&&"                                                                  {bluePrint("Foi encontrado um &&.",yytext);}//yylval = AND; return(RELOP);

"||"                                                                  {bluePrint("Foi encontrado um ||.",yytext);}//yylval = OR; return(RELOP);

"<"                                                                   {bluePrint("Foi encontrado um <.",yytext);}//yylval = LT; return(RELOP);

"<="                                                                  {bluePrint("Foi encontrado um <=.",yytext);}//yylval = LE; return(RELOP);

"=="                                                                  {bluePrint("Foi encontrado um ==.",yytext);}//yylval = EQ; return(RELOP);

"!="                                                                  {bluePrint("Foi encontrado um !=.",yytext);}//yylval = NE; return(RELOP);

">"                                                                   {bluePrint("Foi encontrado um >.",yytext);}//yylval = GT; return(RELOP);

">="                                                                  {bluePrint("Foi encontrado um >=.",yytext);}//yylval = GE; return(RELOP);

{especialChar}                                                  	  {bluePrint("Foi encontrado um char especial.",yytext);}

%% 

int main(void) 
{ 
    /* Call the lexer, then quit. */ 
    yylex(); 
    return 0; 
}

