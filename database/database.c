#include "database.h"

struct playerInfo *databaseCreationWrapper(){
    struct playerInfo *database = databaseCreation("../data/playerData.csv");
    return database;
}
