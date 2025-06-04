#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define DEBUG

char* tokenize(char* inputBuffer){
    char* tokenBuffer[32] = {""};
    char delimiter[] = " ";
    char* token;
    int tokenCounter = 0;

    token = strtok(inputBuffer, delimiter);

    while(token){
        tokenBuffer[tokenCounter] = malloc(64 * sizeof(char));
        strcpy(tokenBuffer[tokenCounter], token);
        token = strtok(NULL, delimiter);
        ++tokenCounter;
    }

    #ifdef DEBUG
        for(int i = 0; i<tokenCounter; ++i){
            printf("Token: %s\n", tokenBuffer[i]);
        }
    #endif
    
    return *tokenBuffer;
}

// should return a keyword and the text associated with it, in order
void parse(){

}

void generate(){

}