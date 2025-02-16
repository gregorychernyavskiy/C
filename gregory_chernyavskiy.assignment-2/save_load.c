#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>

#include "dungeon_generation.h"

char *dungeon_file;

void setupDungeonFile(char *filename) {
    char *home = getenv("HOME");
    int dungeon_file_length = strlen(home) + strlen("/.rlg327/") + strlen(filename) + 1;

    dungeon_file = malloc(dungeon_file_length * sizeof(*dungeon_file));
    if (!dungeon_file) {
        perror("Memory allocation failed for dungeon_file");
        exit(EXIT_FAILURE);
    }

    strcpy(dungeon_file, home);
    strcat(dungeon_file, "/.rlg327/");
    strcat(dungeon_file, filename);
}

void saveDungeon(char *filename) {
    setupDungeonFile(filename);
    FILE *file = fopen(dungeon_file, "w");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fwrite("RLG327-S2025", 1, 12, file);

    uint32_t version = htobe32(0);
    fwrite(&version, 4, 1, file);

    uint32_t size = htobe32(1712 + num_rooms * 4);
    fwrite(&size, 4, 1, file);

    uint8_t pos[2] = {(uint8_t) player_x, (uint8_t) player_y};
    fwrite(pos, 2, 1, file);

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fwrite(&hardness[i][j], 1, 1, file);
        }
    }

    uint16_t r = htobe16(num_rooms);
    fwrite(&r, 2, 1, file);

    for (int i = 0; i < num_rooms; i++) {
        uint8_t room[4] = {rooms[i].x, rooms[i].y, rooms[i].width, rooms[i].height};
        fwrite(room, 4, 1, file);
    }

    printf("Dungeon saved to %s\n", dungeon_file);
    fclose(file);
    free(dungeon_file);
}

void loadDungeon(char *filename) {
    setupDungeonFile(filename);
    FILE *file = fopen(dungeon_file, "r");
    if (!file) {
        perror("Error opening file");
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
    player_x = (int) pos[0];
    player_y = (int) pos[1];

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fread(&hardness[i][j], 1, 1, file);
        }
    }

    uint16_t r = 0;
    fread(&r, 2, 1, file);
    r = be16toh(r);
    num_rooms = r;

    struct Room *rooms = malloc(r * sizeof(struct Room));
    if (!rooms) {
        fprintf(stderr, "Memory allocation failed for rooms\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < r; i++) {
        fread(&rooms[i].x, 1, 1, file);
        fread(&rooms[i].y, 1, 1, file);
        fread(&rooms[i].width, 1, 1, file);
        fread(&rooms[i].height, 1, 1, file);
    }
    for (int i = 0; i < r; i++) {
        for (int j = rooms[i].y; j < rooms[i].y + rooms[i].height; j++) {
            for (int k = rooms[i].x; k < rooms[i].x + rooms[i].width; k++) {
                dungeon[j][k] = FLOOR;
            }
        }
    }

    uint16_t u;
    fread(&u, 2, 1, file);
    u = be16toh(u);

    uint16_t d;
    fread(&d, 2, 1, file);
    d = be16toh(d);

    printf("Dungeon loaded from %s\n", dungeon_file);
    fclose(file);
    free(dungeon_file);
}