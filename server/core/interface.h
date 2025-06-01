#include <stdio.h>
#include <string.h>

void getInput(char* inputBuffer ,int maxSize){        
    printf("db > ");
    fgets(inputBuffer, maxSize, stdin);
    inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
}


int processCommand(char* inputBuffer){
    if(strcmp(inputBuffer, ".quit") == 0){
        return 1;
    }
}
