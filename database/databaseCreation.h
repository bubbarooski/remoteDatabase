#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
};

#define maxLineLength 1024
#define maxFieldLength 64
int hashPrime = 23;   // Initial size of database, will double once 75% capacity is reached
int tableSize = 4;

// Used to store the hash function
inline int databaseHashFunction(char playerName[]) {

  int nameLength = strlen(playerName);
  long long hashValue = 0;

  for (int i = 0; i < nameLength; i++) {
    hashValue += hashPrime * int(playerName[i]);
  }

  return int(hashValue % tableSize);
}

// Used to determine if a rehash needs to be done
void databaseRehash();

// Used to insert data point into database
void databaseInsertion();

// Used to delete datapoint from database
void databaseDeletion();

// Used to search for player in database
void databaseSearch();

// Used to create database
inline void databaseCreation(char fileName[]){
    char line[maxLineLength];
    int lineLength = 0;
    struct playerInfo *database[tableSize] = malloc(tableSize * sizeof(struct playerInfo));
    int lineCounter = 0;

    // Read in CSV file with player data
    FILE *file = fopen(fileName, "r");
    if (file == nullptr) {
        printf("File could not be opened\n");
        exit(0);
    }

    // Main loop of database insertion
    while (fgets(line, maxLineLength, file) != nullptr) {

        // If header line, pass
        if (lineCounter == 0) {
            continue;
        }

        // Check for size of database; if >= 75% capacity, resize database and move over existing data
        databaseRehash();

        // Removing new line character at end of line
        lineLength = strlen(line);
        if (lineLength > 0 && line[lineLength - 1] == '\n') {
            line[lineLength - 1] = '\0';
        }

        // Insert player into database
        databaseInsertion();

        lineCounter++;
    }
}

