#include <stdio.h>
#include <string.h>

#define DEBUG

void tokenize(char* inputBuffer){
    char* tokenBuffer[32] = {""};
    char delimiter[] = " ";
    char* token;
    int tokenCounter = 0;

    token = strtok(inputBuffer, delimiter);
    printf("%s\n", token);

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
    #else
        printf("User input: %s\n", inputBuffer);
    #endif
    
}

void parse(){

}

void generate(){

}