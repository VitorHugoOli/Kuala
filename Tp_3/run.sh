cd src
cd yacc && bison -dy  --debug translate.y && cd ..  
cd lex && lex lex.l && cd ..
gcc lex/lex.yy.c yacc/y.tab.c symbolTable/symbolTable.c -ly && ./a.out $1

