cd src
cd yacc && bison -dy --debug translate.y && cd ..  
cd lex && lex lex.l && cd ..
clang lex/lex.yy.c yacc/y.tab.c symbolTable/symbolTable.c symbolTable/hash.c AST/AST.c -ly && ./a.out $1
