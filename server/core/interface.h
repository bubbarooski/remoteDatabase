#include <stdio.h>
#include <string.h>
#include "compiler.h"

// #define DEBUG

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


// I changed this so less pointers
void executeStatement(char* inputBuffer){
    
    // This will eventually return something but for now, this works
    compiler(inputBuffer);


}
