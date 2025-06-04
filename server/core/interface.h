#include <stdio.h>
#include <string.h>
#include "compiler.h"

#define DEBUG

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
    char **tokenBuffer;
    
    tokenBuffer = tokenize(inputBuffer);

    #ifdef DEBUG
        for(int i=0; i<maxToken && tokenBuffer[i] != NULL; ++i){
            printf("--interface-- Token: %s\n", tokenBuffer[i]);
        }
    #endif

    //parse();
    //generate();

    // Clean up
    if(tokenBuffer[0] != NULL){
        for(int i=0; i<maxToken && tokenBuffer[i] != NULL; ++i){
            free(tokenBuffer[i]);
        }
        free(tokenBuffer);
    }
}
