#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for all player info; maps to a row in "playerData.csv"
struct playerInfo {
    int playerID;           // Not really useful unless imported into SQL database to avoid duplicate players
    char playerName[64];    // Hash function will be based off of player name
    int byeWeek;
    int passingAtt;
    int passingCmp;
    int passingYds;
    int passingTD;
    int passingInt;
    int passing2pt;
    int rushingAtt;
    int rushingYds;
    int rushingTD;
    int rushing2pt;
    int receivingRec;
    int receivingYds;
    int receivingTD;
    int receiving2pt;
    int fumbleLost;
    int fumbleTD;
    int empty;
};

#define maxLineLength 1024
#define maxFieldLength 64
int hashPrime = 23;         // Initial size of database, will double once 75% capacity is reached
int tableSize = 1000;       // Start with 1000 just for starting; will change to dynamic
struct playerInfo *database;

// Used to store the hash function
int databaseHashFunction(char playerName[]) {

  int nameLength = strlen(playerName);
  long long hashValue = 0;

  // Simple hash; this isn't a project on implementing a perfect hash
  for (int i = 0; i < nameLength; i++) {
    hashValue += hashPrime * playerName[i];
  }

  return hashValue % tableSize;
}

// Used to determine if a rehash needs to be done
void databaseResize();

// Used to insert data point into database
void databaseInsertion(char line[], struct playerInfo *database) {
    int tokenCounter = 0;
    struct playerInfo tempStruct;

    // Reading each token from line, delimited by comma
    char *token = strtok(line, ",");
    while (token != NULL) {
        switch(tokenCounter) {
            case 0:
                tempStruct.playerID = atoi(token);
                tokenCounter++;
                token = strtok (NULL, ",");
                continue;
            case 1:
                strcpy(tempStruct.playerName, token);
                token = strtok (NULL, ",");
                tokenCounter++;
                continue;
            case 2:
                tempStruct.byeWeek = atoi(token);
                token = strtok (NULL, ",");
                tokenCounter++;
                continue;
            case 3:
                tempStruct.passingAtt = atoi(token);
                token = strtok (NULL, ",");
                tokenCounter++;
                continue;
            case 4:
                tempStruct.passingCmp = atoi(token);
                token = strtok (NULL, ",");
                tokenCounter++;
                continue;
            case 5:
                tempStruct.passingYds = atoi(token);
                token = strtok (NULL, ",");
                tokenCounter++;
                continue;
            case 6:
                tempStruct.passingTD = atoi(token);
                token = strtok (NULL, ",");
                tokenCounter++;
                continue;
            case 7:
                tempStruct.passingInt = atoi(token);
                token = strtok (NULL, ",");
                tokenCounter++;
                continue;
            case 8:
                tempStruct.passing2pt = atoi(token);
                token = strtok (NULL, ",");
                tokenCounter++;
                continue;
            case 9:
                tempStruct.rushingAtt = atoi(token);
                token = strtok (NULL, ",");
                tokenCounter++;
                continue;
            case 10:
                tempStruct.rushingYds = atoi(token);
                token = strtok (NULL, ",");
                tokenCounter++;
                continue;
            case 11:
                tempStruct.rushingTD = atoi(token);
                token = strtok (NULL, ",");
                tokenCounter++;
                continue;
            case 12:
                tempStruct.rushing2pt = atoi(token);
                token = strtok (NULL, ",");
                tokenCounter++;
                continue;
            case 13:
                tempStruct.receivingRec = atoi(token);
                token = strtok (NULL, ",");
                tokenCounter++;
                continue;
            case 14:
                tempStruct.receivingYds = atoi(token);
                token = strtok (NULL, ",");
                tokenCounter++;
                continue;
            case 15:
                tempStruct.receivingTD = atoi(token);
                token = strtok (NULL, ",");
                tokenCounter++;
                continue;
            case 16:
                tempStruct.receiving2pt = atoi(token);
                token = strtok (NULL, ",");
                tokenCounter++;
                continue;
            case 17:
                tempStruct.fumbleLost = atoi(token);
                token = strtok (NULL, ",");
                tokenCounter++;
                continue;
            case 18:
                tempStruct.fumbleTD = atoi(token);
                token = strtok (NULL, ",");
                tokenCounter++;
            default: ;
        }
    }

    int hashLocation = databaseHashFunction(tempStruct.playerName);

    // Hash collision checker
    if (database[hashLocation].empty == 1) {
        //printf("Collision! Current hash location: %d\n", hashLocation);
        while(database[hashLocation].empty == 1) {
            hashLocation++;

            // Make sure hash location doesn't go above max table size
            if (hashLocation == tableSize - 1) {
                hashLocation = 0;
            }

        }
        //printf("New hash location: %d\n", hashLocation);
    }

    // Insertion into table
    database[hashLocation].empty = 1;
    database[hashLocation].playerID = tempStruct.playerID;
    strcpy(database[hashLocation].playerName, tempStruct.playerName);
    database[hashLocation].byeWeek = tempStruct.byeWeek;
    database[hashLocation].passingAtt = tempStruct.passingAtt;
    database[hashLocation].passingCmp = tempStruct.passingCmp;
    database[hashLocation].passingYds = tempStruct.passingYds;
    database[hashLocation].passingTD = tempStruct.passingTD;
    database[hashLocation].passingInt = tempStruct.passingInt;
    database[hashLocation].passing2pt = tempStruct.passing2pt;
    database[hashLocation].rushingAtt = tempStruct.rushingAtt;
    database[hashLocation].rushingYds = tempStruct.rushingYds;
    database[hashLocation].rushingTD = tempStruct.rushingTD;
    database[hashLocation].rushing2pt = tempStruct.rushing2pt;
    database[hashLocation].receivingRec = tempStruct.receivingRec;
    database[hashLocation].receivingYds = tempStruct.receivingYds;
    database[hashLocation].receivingTD = tempStruct.receivingTD;
    database[hashLocation].receiving2pt = tempStruct.receiving2pt;
    database[hashLocation].fumbleLost = tempStruct.fumbleLost;
    database[hashLocation].fumbleTD = tempStruct.fumbleTD;

}

// Used to delete datapoint from database
void databaseDeletion();

// Used to search for player in database (string based for first implementation)
void databaseSearch(struct playerInfo *database,char playerName[]) {
    // Search by hash function
    int hashLocation = databaseHashFunction(playerName);
    int playerFound = 0;

    while(hashLocation < 1000) {
        if (strcmp(database[hashLocation].playerName, playerName) == 0) {
            playerFound = 1;
            printf("Player name: %s\n", database[hashLocation].playerName);
            printf("Player ID: %d\n", database[hashLocation].playerID);
            break;
        }
        hashLocation++;
    }

    if (playerFound == 0) {
        printf("Player not found!\n");
    }

}

// Used to create database
struct playerInfo *databaseCreation(char fileName[]){
    char line[maxLineLength];
    int lineLength = 0;
    int lineCounter = 0;

    // Initialize database
    struct playerInfo *database = malloc(tableSize * sizeof(struct playerInfo));
    // struct playerInfo **databasePointer = &database;

    // Clear out char field and set empty flag
    for (int i = 0; i < tableSize; i++) {
        strcpy(database[i].playerName, "");
        database[i].empty = 0;
    }

    // Read in CSV file with player data
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("File could not be opened\n");
        exit(0);
    }

    // Main loop of database insertion
    while (fgets(line, maxLineLength, file) != NULL) {

        // If header line, pass
        if (lineCounter == 0) {
            lineCounter++;
            continue;
        }

        // Check for size of database; if >= 75% capacity, resize database and move over existing data
        // TODO: implement dynamic sizing
        // databaseResize();

        // Removing new line character at end of line
        lineLength = strlen(line);
        if (lineLength > 0 && line[lineLength - 1] == '\n') {
            line[lineLength - 1] = '\0';
        }

        // Insert player into database
        databaseInsertion(line, database);

        lineCounter++;
    }

    /**
    // Printing names from all members of database
    for (int i = 0; i < tableSize; i++) {
        printf("Position %d: %s\n", i, database[i].playerName);
    }
    **/

    printf("Database created!\n");

    return database;

}

