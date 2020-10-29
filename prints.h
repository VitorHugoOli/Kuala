void bluePrint(char* string, char* lexema);

void redPrint(char* lexema);

void bluePrint(char* string, char* lexema){
    printf("%s LEXEMA: %s  \n",string,lexema);
}

void redPrint(char* lexema){
    printf("Não foi possivel encontrar o LEXEMA: %s \n",lexema);
}