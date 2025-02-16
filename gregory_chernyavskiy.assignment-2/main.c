#include "dungeon_generation.h"

int main(void) {
    srand(time(NULL));

    emptyDungeon();

    int countRooms = createRooms();
    connectRooms(countRooms);
    placeStairs(countRooms);
    placePlayer(countRooms);

    printDungeon();

    saveDungeon();
    loadDungeon();

    return 0;
}