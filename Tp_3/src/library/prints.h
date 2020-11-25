void blue(char* string, char* lexema);
        
void redPrint(char* lexema,int linha, int chara);
        
void blue(char* string, char* lexema){
    printf("\e[1m%s\e[0m LEXEMA:\e[1;34m %s \e[0m \n",string,lexema);
}

        
void redPrint(char* lexema,int linha,int chara){
    printf("\e[1;31mLexical Error, Couldn't find a compatible lexeme: %s\nDEGUG -> Line: %d  Char: %d\e[0m\n\n",lexema,linha,chara);
}