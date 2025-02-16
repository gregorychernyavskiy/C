#include "dungeon_generation.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int load = 0, save = 0; // Flags for --load and --save

    // Check command-line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--save") == 0) {
            save = 1;
        } else if (strcmp(argv[i], "--load") == 0) {
            load = 1;
        }
    }

    if (load) {
        // If --load is provided, load the dungeon from file
        loadDungeon();
    } else {
        // If no --load, generate a new dungeon
        emptyDungeon();
        int countRooms = createRooms();
        connectRooms(countRooms);
        placeStairs(countRooms);
        placePlayer(countRooms);
    }

    // Print the dungeon after loading or generating
    printDungeon();

    if (save) {
        // If --save is provided, save the dungeon to file
        saveDungeon();
    }

    return 0;
}
