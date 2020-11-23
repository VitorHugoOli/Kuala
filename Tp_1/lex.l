
%{ 

#include "prints.h"

%} 
 
%option noyywrap 

/* definicoes regulares */ 

delim [ \t\n] 
ws {delim}+ 
upperCase [A-Z]
lowerCase [a-z]
bothCase [A-Za-z]
digit [0-9]  
positive \+?{digit}+ 
negative \-[1-9]{digit}*
float \.{digit}+ 
decimal {positive}{float}
decimalNegative \-{digit}+{float}
licensePlate {upperCase}{3}\-{digit}{4}
word {bothCase}+
phone {digit}{4}\-{digit}{4}
name {upperCase}{1}{bothCase}*
fullName ({name}[ ]){2}{name}+([ ]{name})?


%% 

{ws}		;

{positive}   {bluePrint("Foi encontrado um numero inteiro positivo.",yytext);}

{negative} {bluePrint("Foi encontrado um numero inteiro negativo.",yytext);}

{decimal} {bluePrint("Foi encontrado um numero com parte decimal.",yytext);}

{decimalNegative} {bluePrint("Foi encontrado um numero com parte decimal negativo.",yytext);}

{licensePlate} {bluePrint("Foi encontrado uma placa.",yytext);}

{word} {bluePrint("Foi encontrado uma palavra.",yytext);}

{phone} {bluePrint("Foi encontrado um telefone.",yytext);}

{fullName} {bluePrint("Foi encontrado um nome proprio.",yytext);}

. {redPrint(yytext);}


%% 

int main(void) 
{ 
    /* Call the lexer, then quit. */ 
    yylex(); 
    return 0; 
}

