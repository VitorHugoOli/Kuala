
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



%% 

{ws}		;

iguana {bluePrint("Foi encontrado um IF.",yytext);}

whale {bluePrint("Foi encontrado um WHILE.",yytext);}

fox {bluePrint("Foi encontrado um FOR.",yytext);}

{positive}   {bluePrint("Foi encontrado um numero inteiro positivo.",yytext);}

{negative} {bluePrint("Foi encontrado um numero inteiro negativo.",yytext);}

{decimal} {bluePrint("Foi encontrado um numero com parte decimal.",yytext);}



%% 

int main(void) 
{ 
    /* Call the lexer, then quit. */ 
    yylex(); 
    return 0; 
}

