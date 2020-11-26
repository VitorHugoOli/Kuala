
%{ 
#include "../library/prints.h"
#include "../library/define.h"
#include "../yacc/y.tab.h"



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

{simpleComments}                                                      show("comentario simples"); yyline++; 

{blockComments}                                                       show("comentario em bloco"); yyline+=countNewLine(yytext); 

{ws}		                                                              yyline++;yychar_count=1; 

{space}                                                                yychar_count++;

{string}                                                               show("STRING"); yyline+=countNewLine(yytext); yylval = createString(yytext); addTeste(yylval); yychar_count+=strlen(yytext);  return string; 

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

{id}	                                                                 show("ID");  return id; yylval = createID(yytext);

{inteiro}                                                              show("numero inteiro"); yylval = createNumber(yytext);  addTeste(yylval); return int_const;

{decimal}                                                              show("numero decimal"); yylval = createNumber(yytext); addTeste(yylval); return float_const;

"+"                                                                    show("+"); yychar_count++; yylval = PLUS; return '+';

"-"                                                                    show("-"); yychar_count++; yylval = MINUS; return '-';

"*"                                                                    show("*"); yychar_count++; yylval = TIMES; return '*';

"/"                                                                    show("/"); yychar_count++; yylval = DIVIDE; return '/';

"%"                                                                    show("%"); yychar_count++; yylval = REST; return '%';

"--"                                                                    show("--"); yychar_count++; yylval = MINUS; return DECRMT;

"++"                                                                    show("++"); yychar_count++; yylval = PLUS; return INCRMT;

"&&"                                                                   show("&&"); yychar_count+=2; yylval = AND; return LOGIC;

"||"                                                                   show("||"); yychar_count+=2; yylval = OR; return LOGIC;

"!"                                                                    show("!"); yychar_count++; yylval = createRelop(yytext, NOTE); addTeste(yylval); return NOT;

"<"                                                                    show("<"); yychar_count+=2; yylval = createRelop(yytext, LT); addTeste(yylval); return RELOP;

"<="                                                                   show("<="); yychar_count+=2; yylval = createRelop(yytext, LE); addTeste(yylval); return RELOP;

"=="                                                                   show("=="); yychar_count+=2; yylval = createRelop(yytext, EQ); addTeste(yylval); return RELOP;

"!="                                                                   show("!="); yychar_count+=2; yylval = createRelop(yytext, NE); addTeste(yylval); return RELOP;

">"                                                                    show(">"); yychar_count+=2; yylval = createRelop(yytext, GT); addTeste(yylval); return RELOP;

">="                                                                   show(">="); yychar_count+=2; yylval = createRelop(yytext, GE); addTeste(yylval); return RELOP;

{especialChar}                                                  	   show("char especial"); yychar_count++; return yytext[0]; 

. {redPrint(yytext,yyline,yychar_count);yychar_count++; } //yyterminate();

%% 

int countNewLine(char *s){
  
  return *s == '\0' ? 0 : countNewLine(s + 1) + (*s == '\n');
}

void addTeste(struct symbol *lex){
  extern symbollist;
  insertSymbol(&symbollist,lex);
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

