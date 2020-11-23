clear
cd src/lex
bison -dy --debug yacc.y && lex lex.l && gcc lex.yy.c y.tab.c && ./a.out $1

