#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define DEBUG
# define maxToken 32

char *keywords[] = {
    "CREATE",
    "DROP"
};

// Need to handle getting more than 32 tokens
char** tokenize(char* inputBuffer){
    char** tokenBuffer = malloc(maxToken * sizeof(char*));
    char delimiter[] = " ";
    char* token;
    int tokenCounter = 0;

    token = strtok(inputBuffer, delimiter);

    while(token){
        tokenBuffer[tokenCounter] = malloc((strlen(token) + 1) * sizeof(char));
        strcpy(tokenBuffer[tokenCounter], token);
        token = strtok(NULL, delimiter);
        ++tokenCounter;
    }

    tokenBuffer[tokenCounter] = NULL;

    #ifdef DEBUG
        for(int i = 0; i<tokenCounter; ++i){
            printf("--compiler-- Token: %s\n", tokenBuffer[i]);
        }
    #endif
    
    return tokenBuffer;
}

// should return a keyword and the text associated with it, in order
void parse(){

}

void generate(){

}