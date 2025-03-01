#include <stdio.h>
#include <unistd.h>

// Checks if the data file containing player data exists
int dataFileCheck(){
    printf("Checking for player data file...\n");

    FILE *file;
    if((file = fopen("../data/playerData.csv", "r"))){
        printf("File exists!\n");
        fclose(file);
        return 1;
    }
    printf("File does not exist!\n");
    return 0;
}

// Creates player data
// TODO: fix this to actually work instead of manually running Python script
int createPlayerData() {

    printf("Creating player data...\n");

    if (system("python3 --version") != 0) {
        printf("Python3 is not installed or not in PATH!\n");
        return 0;
    }

    FILE* file = fopen("../data/pullData.py", "r");
    if (file == NULL) {
        printf("Python file can't be found!\n");
        return 0;
    }
    fclose(file);

    printf("Running Python script...\n");
    if (system("python3 ../data/pullData.py") != 0) {
        printf("Failed to run Python script!\n");
        return 0;
    }

    printf("Player data created successfully!\n");
    return 1;

}

// Wrapper function for creation of player data
void createDataWrapper(){

    // Check for if data file exists and if not, create it
    if (dataFileCheck() == 0) {
        // Creating data file via Python Script
        createPlayerData();
    }
    else {
        printf("Player data is created!\n");
    }
}
