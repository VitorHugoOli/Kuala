
%{ 
#include "../library/prints.h"
#include "../library/define.h"
#include <string.h>
#include "../yacc/y.tab.h"
#include "../AST/AST.h"




int yyline=1;
extern int yyline;

int yychar_count=1;
extern int yychar_count;

int verbose = 0;
extern int verbose;


#define show(mensg) verbose ? blue(mensg,yytext) : NULL
int countNewLine(char *s);
%} 

%option noyywrap 
%option yylineno


/* definicoes regulares */ 

space [ ]
delim [\t\n] 
ws {delim}+ 
upperCase [A-Z]
lowerCase [a-z]
bothCase [A-Za-z]
digit [0-9]  
id (_|{bothCase})({bothCase}|{digit}|_)*
inteiro {digit}+ 
float \.{digit}+ 
decimal {inteiro}{float}
especialChar [;|=|,|{|}|(|)|\[|\]|?|:|&|||^|<|>|\'|\']
string \"(\\.|[^\"])*\"
simpleComments \/\/(.|[^\n])*
blockComments [/][*]([^*]|[*]*[^*/])*[*][/]

%% 

{simpleComments}                                                       show("comentario simples"); yyline++; 

{blockComments}                                                        show("comentario em bloco"); yyline+=countNewLine(yytext); 

{ws}		                                                               yyline++;yychar_count=1; 

{space}                                                                yychar_count++;

{string}                                                               show("STRING"); yyline+=countNewLine(yytext); yylval.val = makeStr(strdup(yytext)); yychar_count+=strlen(yytext);  return string; 

kuala                                                                  show("Kuala"); yychar_count+=5;  return KUALA;

"ʕ·͡ᴥ·ʔ"                                                                show("ʕ·͡ᴥ·ʔ"); yychar_count+=5;  return KUALA;

iguana                                                                 show("IF"); yychar_count+=6;  return IF;

eel                                                                    show("ELSE"); yychar_count+=3;  return ELSE;

whale                                                                  show("WHILE"); yychar_count+=5;  return WHILE;

fox                                                                    show("FOR"); yychar_count+=3;  return FOR;

ibis                                                                   show("INT"); yychar_count+=4;  return INT;

frog                                                                   show("FLOAT"); yychar_count+=4;  return FLOAT;

bug                                                                    show("BOOL"); yychar_count+=3;  return BOOL;

snake                                                                  show("STRING"); yychar_count+=5;   return STRING;

viper                                                                  show("void"); yychar_count+=5;  return VOID;

rabbit                                                                 show("return"); yychar_count+=5;  return RETURN;

{id}	                                                                 show("ID"); yylval.val = makeSymbol(yytext); return id;

{inteiro}                                                              show("numero inteiro"); yylval.val = makeNum(atoi(yytext)); return int_const;

{decimal}                                                              show("numero decimal"); yylval.val = makeFloat(strdup(yytext)); return float_const;

"+"                                                                    show("+"); yychar_count++; return '+';

"-"                                                                    show("-"); yychar_count++; return '-';

"*"                                                                    show("*"); yychar_count++; return '*';

"/"                                                                    show("/"); yychar_count++; return '/';

"%"                                                                    show("%"); yychar_count++; return '%';

"--"                                                                   show("--"); yychar_count++; return DECRMT;

"++"                                                                   show("++"); yychar_count++; return INCRMT;

"&&"                                                                   show("&&"); yychar_count+=2; return AND_OP;

"||"                                                                   show("||"); yychar_count+=2; return OR_OP;

"!"                                                                    show("!"); yychar_count++; return NOT;

"<"                                                                    show("<"); yychar_count+=2; return LT_OP;

"<="                                                                   show("<="); yychar_count+=2; return LE_OP;

"=="                                                                   show("=="); yychar_count+=2; return EQ_OP;

"!="                                                                   show("!="); yychar_count+=2; return DIF_OP;

">"                                                                    show(">"); yychar_count+=2; return GT_OP;

">="                                                                   show(">="); yychar_count+=2; return GE_OP;

{especialChar}                                                  	   show("char especial"); yychar_count++; return yytext[0]; 

. {redPrint(yytext,yyline,yylineno,yychar_count);yychar_count++; } //yyterminate();

%% 

int countNewLine(char *s){
  
  return *s == '\0' ? 0 : countNewLine(s + 1) + (*s == '\n');
}


/* int main(int argc,char *argv[]) 
{ 
    
    if( argc == 2 && strcmp(argv[1],"--verbose")==0) {
      verbose=1;
      printf("Modo Verboso %s\n", argv[1]);
    }
    yylex(); 
    return 0; 
}   */

