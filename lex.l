
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

{simpleComments}                                                      {blue("comentario simples",yytext);}

{blockComments}                                                       {blue("comentario em bloco",yytext);}

{ws}		;

{string}                                                              {blue("STRING",yytext);}

kuala                                                                 {blue("Kuala",yytext);}

"ʕ·͡ᴥ·ʔ"                                                                 {blue("ʕ·͡ᴥ·ʔ",yytext);}

iguana                                                                {blue("IF",yytext);}

eel                                                                   {blue("ELSE",yytext);}

whale                                                                 {blue("WHILE",yytext);}

fox                                                                   {blue("FOR",yytext);}

ibis                                                                  {blue("INT",yytext);}

frog                                                                  {blue("FLOAT",yytext);}

bug                                                                   {blue("BOOL",yytext);}

snake                                                                 {blue("STRING",yytext);}

viper                                                                 {blue("void",yytext);}

{id}	                                                              {blue("ID",yytext);}

{positive}                                                            {blue("numero inteiro positivo",yytext);}

{negative}                                                            {blue("numero inteiro negativo",yytext);}

{decimal}                                                             {blue("numero com parte decimal",yytext);}

"+"                                                                   {blue("+",yytext);}//yylval = PLUS; return(OP);

"-"                                                                   {blue("-",yytext);}//yylval = MINUS; return(OP);

"*"                                                                   {blue("*",yytext);}//yylval = TIMES; return(OP);

"/"                                                                   {blue("/",yytext);}//yylval = DIVIDE; return(OP);

"&&"                                                                  {blue("&&",yytext);}//yylval = AND; return(RELOP);

"||"                                                                  {blue("||",yytext);}//yylval = OR; return(RELOP);

"<"                                                                   {blue("<",yytext);}//yylval = LT; return(RELOP);

"<="                                                                  {blue("<=",yytext);}//yylval = LE; return(RELOP);

"=="                                                                  {blue("==",yytext);}//yylval = EQ; return(RELOP);

"!="                                                                  {blue("!=",yytext);}//yylval = NE; return(RELOP);

">"                                                                   {blue(">",yytext);}//yylval = GT; return(RELOP);

">="                                                                  {blue(">=",yytext);}//yylval = GE; return(RELOP);

{especialChar}                                                  	  {blue("char especial",yytext);}

. {redPrint(yytext);}

%% 

int main(void) 
{ 
    /* Call the lexer, then quit. */ 
    yylex(); 
    return 0; 
}

