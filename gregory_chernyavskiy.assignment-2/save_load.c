#include "dungeon_generation.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <endian.h>

char *dungeon_file = NULL;

void setupDungeonFile(const char *filename) {
    char *home = getenv("HOME");
    if (!home) {
        fprintf(stderr, "Error: HOME environment variable not set.\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the dungeon file path
    int dungeon_file_length = strlen(home) + strlen("/.rlg327/") + strlen(filename) + 1;
    dungeon_file = malloc(dungeon_file_length * sizeof(*dungeon_file));
    if (!dungeon_file) {
        perror("Memory allocation failed for dungeon_file");
        exit(EXIT_FAILURE);
    }

    // Construct the full path
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

    uint32_t size = htobe32(1708 + MAX_ROOMS * 4);
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
            dungeon[y][x] = (hardness[y][x] == 0) ? '.' : ' ';
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

    fclose(file);
    printf("Dungeon loaded from %s\n", dungeon_file);
}