#ifndef DUNGEON_GENERATION_H
#define DUNGEON_GENERATION_H

#define WIDTH 80
#define HEIGHT 21

#define MAX_ROOMS 8
#define MIN_ROOMS 6

struct Room {
    int x;
    int y;
    int height;
    int width;
};

extern char dungeon[HEIGHT][WIDTH];
extern int hardness[HEIGHT][WIDTH];

void emptyDungeon();
void initializeHardness();
int overlapCheck(struct Room r1, struct Room r2);
int createRooms();
void connectRooms(int countRooms);
void placeStairs(int countRooms);
void placePlayer(int countRooms);
void printDungeon();

#endif