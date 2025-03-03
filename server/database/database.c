#include <ctype.h>
#include <stdio.h>
#include "../startup/dataCreation.h"
#include "database.h"

struct playerInfo *database;

void databaseCreationWrapper(){
    database = databaseCreation("./data/playerData.csv");
}

void databaseSetup(){
    createDataWrapper();
    databaseCreationWrapper();
}

void databaseSearchWrapper(char *playerName) {
    databaseSearch(database, playerName);
}
