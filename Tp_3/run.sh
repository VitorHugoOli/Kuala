clear
cd src
cd yacc && bison -dy --debug yacc.y && cd ..  
cd lex && lex lex.l && cd ..
gcc lex/lex.yy.c yacc/y.tab.c && ./a.out $1

