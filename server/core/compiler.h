#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG
#define maxToken 32
#define maxKeywords 2

char* keywords[] = {
    "CREATE",
    "DROP"
};

typedef enum{
    CREATE,
    DROP,
    UNKNOWN
} keywordEnum;

keywordEnum keywordMatch(char* token){
    if(strcmp(token, "CREATE") == 0){
        return CREATE;
    }
    
    if(strcmp(token, "DROP") == 0){
        return DROP;
    }
}

// Need to handle getting more than 32 tokens
void compiler(char* inputBuffer){
    
    // TOKENIZER -------------------------------------------------------------------
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

    // END OF TOKENIZER ------------------------------------------------------------



    // PARSER ----------------------------------------------------------------------
    char** commands;
    char currentCommand[129];
    int tokenNum = 0;
    int keywordFlag = 0;
    
    // Statement should always start with keyword
    while(tokenBuffer[tokenNum] != NULL){
        switch(keywordMatch(tokenBuffer[tokenNum])){
            case CREATE:
                keywordFlag = 1;
                break;
            case DROP:
                keywordFlag = 1;
                break;
            default:
        }

        if(keywordFlag == 1){
            strcat(currentCommand, tokenBuffer[tokenNum]);
            ++tokenNum;

            while(keywordFlag = 1){
                
            }

        }
        else{
            printf("INVALID STATEMENT\n");
            break;
        }


    }

    // END OF PARSER ---------------------------------------------------------------



    // INTERPERTER -----------------------------------------------------------------
    
    // Keyword switch statement

    // END OF INTERPERTER ----------------------------------------------------------

    // Memory clean up
    for(int i = 0; i<maxToken && tokenBuffer[i] != NULL; ++i){
        free(tokenBuffer[i]);
    }
    free(tokenBuffer);
}