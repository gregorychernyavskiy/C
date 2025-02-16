#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>

#include "dungeon_generation.h"

char *dungeon_file = NULL;

void setupDungeonFile(const char *filename) {
    char *home = getenv("HOME");
    if (!home) {
        fprintf(stderr, "Error: HOME environment variable not set.\n");
        exit(EXIT_FAILURE);
    }

    int dungeon_file_length = strlen(home) + strlen("/.rlg327/") + strlen(filename) + 1;
    dungeon_file = malloc(dungeon_file_length);
    if (!dungeon_file) {
        perror("Memory allocation failed for dungeon_file");
        exit(EXIT_FAILURE);
    }

    strcpy(dungeon_file, home);
    strcat(dungeon_file, "/.rlg327/");
    strcat(dungeon_file, filename);
}

void saveDungeon() {
    setupDungeonFile("dungeon");

    FILE *file = fopen(dungeon_file, "wb");
    if (!file) {
        perror("Error opening file for saving");
        exit(EXIT_FAILURE);
    }

    fwrite("RLG327-S2025", 1, 12, file);

    uint32_t version = htobe32(0);
    fwrite(&version, 4, 1, file);

    uint32_t size = htobe32(1708 + num_rooms * 4);
    fwrite(&size, 4, 1, file);

    uint8_t pos[2] = {player_x, player_y};
    fwrite(pos, 2, 1, file);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fwrite(&hardness[y][x], 1, 1, file);
        }
    }

    uint16_t r = htobe16(num_rooms);
    fwrite(&r, 2, 1, file);

    for (int i = 0; i < num_rooms; i++) {
        uint8_t room[4] = {rooms[i].x, rooms[i].y, rooms[i].width, rooms[i].height};
        fwrite(room, 4, 1, file);
    }

    fclose(file);
    printf("Dungeon saved to %s\n", dungeon_file);
}

void loadDungeon() {
    setupDungeonFile("dungeon");

    FILE *file = fopen(dungeon_file, "rb");
    if (!file) {
        perror("Error opening file for loading");
        exit(EXIT_FAILURE);
    }

    char marker[12];
    fread(marker, 1, 12, file);

    uint32_t version;
    fread(&version, 4, 1, file);
    version = be32toh(version);

    uint32_t size;
    fread(&size, 4, 1, file);
    size = be32toh(size);

    uint8_t pos[2];
    fread(pos, 2, 1, file);
    player_x = pos[0];
    player_y = pos[1];

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fread(&hardness[y][x], 1, 1, file);
            if (hardness[y][x] == 0) {
                dungeon[y][x] = '.';
            } else {
                dungeon[y][x] = ' ';
            }
        }
    }

    uint16_t r;
    fread(&r, 2, 1, file);
    num_rooms = be16toh(r);

    for (int i = 0; i < num_rooms; i++) {
        fread(&rooms[i].x, 1, 1, file);
        fread(&rooms[i].y, 1, 1, file);
        fread(&rooms[i].width, 1, 1, file);
        fread(&rooms[i].height, 1, 1, file);
    }

    for (int i = 0; i < num_rooms; i++) {
        for (int y = rooms[i].y; y < rooms[i].y + rooms[i].height; y++) {
            for (int x = rooms[i].x; x < rooms[i].x + rooms[i].width; x++) {
                dungeon[y][x] = '.';
            }
        }
    }

    dungeon[player_y][player_x] = '@';

    fclose(file);
    printf("Dungeon loaded from %s\n", dungeon_file);
}