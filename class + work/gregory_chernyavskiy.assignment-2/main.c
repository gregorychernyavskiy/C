#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <sys/stat.h> 
#include <unistd.h>  
#include "dungeon_generation.h"
#include "dungeon_save_load.h"
#include <time.h>

int player_x, player_y; // Global player position

int main(int argc, char *argv[]) {
    srand(time(NULL));

    const char *home = getenv("HOME");
    if (!home) {
        fprintf(stderr, "ERROR: Could not get home directory.\n");
        return 1;
    }

    char dirPath[256];
    char filePath[512]; // Increased size to prevent truncation

    snprintf(dirPath, sizeof(dirPath), "%s/.rlg327", home);

    struct stat st;
    if (stat(dirPath, &st) == -1) {
        if (mkdir(dirPath, 0777) != 0) {
            perror("ERROR: Failed to create directory");
            return 1;
        }
    }

    snprintf(filePath, sizeof(filePath), "%s/dungeon", dirPath); // Prevent truncation issues

    int load = 0, save = 0;
    char customFilePath[512] = ""; // Increased size

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--save") == 0) save = 1;
        if (strcmp(argv[i], "--load") == 0) load = 1;
        if (load && i + 1 < argc) { // Allow loading from a custom file
            strncpy(customFilePath, argv[i + 1], sizeof(customFilePath) - 1);
            customFilePath[sizeof(customFilePath) - 1] = '\0';
        }
    }

    struct stat buffer;
    int fileExists = (stat(filePath, &buffer) == 0);

    if (load) {
        const char *loadPath = fileExists ? filePath : customFilePath;
        printf("Loading dungeon from %s...\n", loadPath);
        loadDungeon(loadPath);
    } else {
        printf("Generating a new dungeon...\n");
        emptyDungeon();
        int countRooms = createRooms();
        connectRooms(countRooms);
        placeStairs(countRooms);
        placePlayer(countRooms);
        initializeHardness();
        printDungeon();
    }

    if (save) {
        printf("Saving dungeon to %s...\n", filePath);
        saveDungeon(filePath);
    }

    return 0;
}
