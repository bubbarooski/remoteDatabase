#include <stdio.h>
#include "interface.h"

struct userInput{
    char userInput[64];
    char exitString[5];
    int maxStringSize;
    int quitFlag;
};

int userInterface(char runVersion[]){
    struct userInput input;
    strcpy(input.exitString, "quit");
    input.maxStringSize = 64;
    input.quitFlag = 0;
    
    printf("Starting user interface...\n");
    
    while(input.quitFlag == 0){
        
        // Get user input
        strcpy(input.userInput, "");
        getInput(input.userInput, input.maxStringSize);
        printf("User input is: %s\n", input.userInput);

        // Check for commands
        if(input.userInput[0] == '.'){
            input.quitFlag = processCommand(input.userInput);
        }

    }

    return 0;

}