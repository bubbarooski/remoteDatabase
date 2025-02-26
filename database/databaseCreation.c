#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "databaseCreation.h"

void baseFunction(){

    // databaseCreation("data/playerData.csv");

    char playerName[maxLineLength] = "Joe Burrow";

    int place = databaseHashFunction(playerName);
    printf("%d\n", place);

}
