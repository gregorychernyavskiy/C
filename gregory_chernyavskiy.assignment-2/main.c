#include "dungeon_generation.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int load = 0, save = 0;
    char *filename = "dungeon";

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--save") == 0) {
            save = 1;
        } else if (strcmp(argv[i], "--load") == 0) {
            load = 1;
        }
    }

    if (load) {
        loadDungeon(filename);
    } else {
        emptyDungeon();
        int countRooms = createRooms();
        connectRooms(countRooms);
        placeStairs(countRooms);
        placePlayer(countRooms);
    }

    printDungeon();

    if (save) {
        saveDungeon(filename);
    }

    return 0;
}
