
%{ 
#include "../library/prints.h"
#include "../library/define.h"
#include "y.tab.h"

int yyline=1;
int yychar_count=1;
extern int yyline;
extern int yychar_count;
int verbose = 0;
extern int verbose;
#define show(mensg) verbose ? blue(mensg,yytext) : NULL

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

{simpleComments}                                                      show("comentario simples"); yyline++; 

{blockComments}                                                       show("comentario em bloco"); 

{ws}		                                                              yyline++;yychar_count=1;

{space}                                                                yychar_count++;

{string}                                                               show("STRING"); yychar_count+=strlen(yytext); return string; 

kuala                                                                  show("Kuala"); yychar_count+=5; return KUALA;

"ʕ·͡ᴥ·ʔ"                                                                  show("ʕ·͡ᴥ·ʔ"); yychar_count+=5; return KUALA;

iguana                                                                 show("IF"); yychar_count+=6; return IF;

eel                                                                    show("ELSE"); yychar_count+=3; return ELSE;

whale                                                                  show("WHILE"); yychar_count+=5; return WHILE;

fox                                                                    show("FOR"); yychar_count+=3; return FOR;

ibis                                                                   show("INT"); yychar_count+=4; return INT;

frog                                                                   show("FLOAT"); yychar_count+=4;return FLOAT;

bug                                                                    show("BOOL"); yychar_count+=3;return BOOL;

snake                                                                  show("STRING"); yychar_count+=5; return STRING;

viper                                                                  show("void"); yychar_count+=5; return VOID;

rabbit                                                                 show("return"); yychar_count+=5; return RETURN;

{id}	                                                                 show("ID"); yychar_count+=strlen(yytext); return id;

{positive}                                                             show("numero inteiro positivo"); yychar_count+=strlen(yytext); return int_const;

{negative}                                                             show("numero inteiro negativo"); yychar_count+=strlen(yytext); return int_const;

{decimal}                                                              show("numero com parte decimal"); yychar_count+=strlen(yytext); return float_const;

{decimalNegative}                                                      show("numero com parte decimal NEGATIVA"); yychar_count+=strlen(yytext); return float_const;

"+"                                                                    show("+"); yychar_count++; yylval = PLUS; return '+';

"++"                                                                    show("++"); yychar_count++; yylval = PLUS; return INCRMT;

"-"                                                                    show("-"); yychar_count++; yylval = MINUS; return '-';

"--"                                                                    show("--"); yychar_count++; yylval = MINUS; return DECRMT;

"*"                                                                    show("*"); yychar_count++; yylval = TIMES; return '*';

"/"                                                                    show("/"); yychar_count++; yylval = DIVIDE; return '/';

"&&"                                                                   show("&&"); yychar_count+=2; yylval = AND; return AND;

"||"                                                                   show("||"); yychar_count+=2; yylval = OR; return OR;

"<"                                                                    show("<"); yychar_count+=2; yylval = LT; return LT;

"<="                                                                   show("<="); yychar_count+=2; yylval = LE; return LE;

"=="                                                                   show("=="); yychar_count+=2; yylval = EQ; return EQ;

"!="                                                                   show("!="); yychar_count+=2; yylval = NE; return NE;

">"                                                                    show(">"); yychar_count+=2; yylval = GT; return GT;

">="                                                                   show(">="); yychar_count+=2; yylval = GE; return GE;

{especialChar}                                                  	   show("char especial"); yychar_count++; return yytext[0]; 

. {redPrint(yytext,yyline,yychar_count);yychar_count++; } //yyterminate();

%% 

/* int main(int argc,char *argv[]) 
{ 
    
    if( argc == 2 && strcmp(argv[1],"--verbose")==0) {
      verbose=1;
      printf("Modo Verboso %s\n", argv[1]);
    }
    yylex(); 
    return 0; 
}   */
