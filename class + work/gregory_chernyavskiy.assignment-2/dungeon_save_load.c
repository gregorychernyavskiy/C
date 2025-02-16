#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <string.h>
#include "dungeon_generation.h"

extern char dungeon[HEIGHT][WIDTH];
extern int hardness[HEIGHT][WIDTH];
extern struct Room rooms[MAX_ROOMS];
extern int player_x, player_y;

void saveDungeon(const char *filename) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        perror("ERROR: Could not open dungeon file for saving");
        return;
    }

    fwrite("RLG327-S2025", 1, 12, f);
    uint32_t version = htonl(0);
    uint32_t file_size = htonl(1708 + MAX_ROOMS * 4);
    fwrite(&version, sizeof(version), 1, f);
    fwrite(&file_size, sizeof(file_size), 1, f);

    // Save player position
    uint8_t pc_position[2] = {player_x, player_y};
    fwrite(pc_position, sizeof(uint8_t), 2, f);

    // Save hardness values
    for (int y = 0; y < HEIGHT; y++) {
        fwrite(hardness[y], sizeof(uint8_t), WIDTH, f);
    }

    // Save rooms
    uint16_t room_count = htons(MAX_ROOMS);
    fwrite(&room_count, sizeof(uint16_t), 1, f);

    for (int i = 0; i < MAX_ROOMS; i++) {
        uint8_t room_data[4] = {rooms[i].x, rooms[i].y, rooms[i].width, rooms[i].height};
        fwrite(room_data, sizeof(uint8_t), 4, f);
    }

    fclose(f);
}

void loadDungeon(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("ERROR: Could not open dungeon file for loading.");
        return;
    }

    char magic[12];
    fread(magic, 1, 12, f);
    if (strncmp(magic, "RLG327-S2025", 12)) {
        fclose(f);
        return;
    }

    uint32_t version, file_size;
    fread(&version, sizeof(version), 1, f);
    fread(&file_size, sizeof(file_size), 1, f);

    // Load player position
    uint8_t pc_position[2];
    fread(pc_position, sizeof(uint8_t), 2, f);
    player_x = pc_position[0];
    player_y = pc_position[1];

    // Load hardness values
    for (int y = 0; y < HEIGHT; y++) {
        fread(hardness[y], sizeof(uint8_t), WIDTH, f);
    }

    // Load rooms
    uint16_t room_count;
    fread(&room_count, sizeof(uint16_t), 1, f);
    room_count = ntohs(room_count);

    for (int i = 0; i < room_count; i++) {
        uint8_t room_data[4];
        fread(room_data, sizeof(uint8_t), 4, f);
        rooms[i].x = room_data[0];
        rooms[i].y = room_data[1];
        rooms[i].width = room_data[2];
        rooms[i].height = room_data[3];
    }

    fclose(f);

    // ✅ Rebuild Dungeon Grid
    emptyDungeon();  // Reset dungeon

    // ✅ Restore rooms
    for (int i = 0; i < room_count; i++) {
        for (int y = rooms[i].y; y < rooms[i].y + rooms[i].height; y++) {
            for (int x = rooms[i].x; x < rooms[i].x + rooms[i].width; x++) {
                dungeon[y][x] = '.';
            }
        }
    }

    // ✅ Restore hallways
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (hardness[y][x] == 0 && dungeon[y][x] != '.') {
                dungeon[y][x] = '#';  // Convert empty spaces into hallways
            }
        }
    }

    // ✅ Place Player
    if (dungeon[player_y][player_x] != '.' && dungeon[player_y][player_x] != '#') {
        player_x = rooms[0].x + 1;
        player_y = rooms[0].y + 1;
    }
    dungeon[player_y][player_x] = '@';

    printDungeon();
    
}
