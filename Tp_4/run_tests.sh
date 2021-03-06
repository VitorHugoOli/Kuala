cd src
cd yacc && bison -dy --debug translate.y && cd ..  
cd lex && lex lex.l && cd ..
clang lex/lex.yy.c yacc/y.tab.c symbolTable/symbolTable.c symbolTable/hash.c AST/AST.c -ly

log=false;
verbose=0;


if [[ $1 == *"--log"* ||  $2 == *"--log"*  ]]; then
    log=true;
fi

if [[ $1 == *"--verbose"* || $2 == *"--verbose"*  ]]; then
       verbose="--verbose"; 
fi



for d in ../tests/succ/* ; do
    result=$(./a.out $verbose < $d)
    if [[ $result == *"Programa sintaticamente correto"* ]]; then
        echo -e "Teste: $d - \e[1;32m Parsing Successful ʕ·͡ᴥ·ʔ! \e[0m\n"
    else
        echo -e "Teste: $d - \e[1;31;5m Parsing Fail! \e[0m\n"
        if $log ; then
            echo -e "LOG ERROR:"
            echo -e "---------------------------"
            echo -e "$result"
            echo -e "---------------------------\n"
        fi
    fi
done


for d in ../tests/fail/* ; do
    result=$(./a.out $verbose < $d)
     if [[ $result == *"Programa sintaticamente correto"* ]]; then
        echo -e "Teste: $d - \e[1;32m Parsing Successful ʕ·͡ᴥ·ʔ! \e[0m\n"
     else
        echo -e "Teste: $d - \e[1;31;5m Parsing Fail! \e[0m\n"
        if $log ; then
            echo -e "\e[1mLOG ERROR: \e[0m"
            echo -e "---------------------------"
            echo -e "$result"
            echo -e "\e[0m---------------------------\n"
        fi
    fi
done


