#include <stdio.h>
#include "../core/interface.c"

int main(int argc, char *argv[])
{

    int loopStatus = 1;
    char *version = argv[1];

    #ifdef DEBUG
        // Print arguements being based on command line
        for(int i = 0; i < argc; i++) {
            printf("argv[%d] = %s\n", i, argv[i]);
        }
    #endif

    if (argc < 2 | argc > 2)
    {
        printf("Invalid number of command line arguements");
        return 1;
    }

    while (loopStatus == 1)
    {
        loopStatus = userInterface(version);
    }
}