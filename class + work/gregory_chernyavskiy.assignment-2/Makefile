CC = gcc
CFLAGS = -Wall -Wextra -g

all: dungeon

dungeon: main.o dungeon_generation.o dungeon_save_load.o
	$(CC) $(CFLAGS) -o dungeon main.o dungeon_generation.o dungeon_save_load.o

main.o: main.c dungeon_generation.h dungeon_save_load.h
	$(CC) $(CFLAGS) -c main.c

dungeon_generation.o: dungeon_generation.c dungeon_generation.h
	$(CC) $(CFLAGS) -c dungeon_generation.c

dungeon_save_load.o: dungeon_save_load.c dungeon_generation.h dungeon_save_load.h
	$(CC) $(CFLAGS) -c dungeon_save_load.c

clean:
	rm -f *.o dungeon