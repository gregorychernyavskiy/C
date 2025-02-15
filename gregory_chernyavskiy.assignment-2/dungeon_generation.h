#ifndef DUNGEON_GENERATION_H
#define DUNGEON_GENERATION_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 21

#define MAX_ROOMS 8
#define MIN_ROOMS 6

#define MIN_ROOM_HEIGHT 3
#define MAX_ROOM_HEIGHT 9

#define MIN_ROOM_WIDTH 4
#define MAX_ROOM_WIDTH 12

#define MAX_HARDNESS 255
#define MIN_HARDNESS 1

#define CORRIDOR '#'
#define ROCK ' '
#define CORNER '+'
#define FLOOR '.'
#define STAIR_UP '<'
#define STAIR_DOWN '>'

extern char dungeon[HEIGHT][WIDTH];
extern unsigned char hardness[HEIGHT][WIDTH];

struct Room {
    int x;
    int y;
    int height;
    int width;
};

extern struct Room rooms[MAX_ROOMS];
extern int num_rooms;
extern int player_x, player_y;

void printDungeon();
void emptyDungeon();
int overlapCheck(struct Room r1, struct Room r2);
int createRooms(void);
void connectRooms(int countRooms);
void placeStairs(int countRooms);
void placePlayer(int countRooms);
void initializeHardness();
void printHardness();
void saveDungeon(char *filename);
void loadDungeon(char *filename);

#endif