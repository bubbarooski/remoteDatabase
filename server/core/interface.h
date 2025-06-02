#include <stdio.h>
#include <string.h>
#include "compiler.h"

void getInput(char* inputBuffer ,int maxSize){        
    printf("db > ");
    fgets(inputBuffer, maxSize, stdin);
    inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
}


int processCommand(char* inputBuffer){

    if(strcmp(inputBuffer, ".quit") == 0){
        return 1;
    }

    if(strcmp(inputBuffer, ".test") == 0){
        printf("test\n");
        return 0;
    }
}

void executeStatement(char* inputBuffer){
    tokenize(inputBuffer);
    parse();
    generate();
}
