#include <stdio.h>
#include "startup/dataCreation.h"
#include "database/database.C"

int main() {
    createDataWrapper();
    struct playerInfo *database = databaseCreationWrapper();

    char playerName[] = "Trevor Lawrece";

    databaseSearch(database, playerName);

}
