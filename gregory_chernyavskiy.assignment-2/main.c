#include "dungeon_generation.h"

int main(void) {
    srand(time(NULL));
    emptyDungeon();
    initializeHardness();

    int countRooms = createRooms();
    connectRooms(countRooms);
    placeStairs(countRooms);
    placePlayer(countRooms);

    printDungeon();
    printf("\n");
    printHardness();
    return 0;
}