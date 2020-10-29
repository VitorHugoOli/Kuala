void blue(char* string, char* lexema);
        
    void redPrint(char* lexema);
        
    void blue(char* string, char* lexema){
        printf("\e[1m%s\e[0m LEXEMA:\e[1;34m %s \e[0m \n",string,lexema);
    }

        
    void redPrint(char* lexema){
        printf("\e[1;31mNão foi possivel encontrar o LEXEMA: %s \e[0m\n",lexema);
}