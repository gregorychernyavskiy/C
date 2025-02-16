CC = gcc
CFLAGS = -Wall -Werror

dungeon: main.o dungeon_generation.o
	$(CC) main.o dungeon_generation.o -o dungeon $(CFLAGS) -lm

main.o: main.c dungeon_generation.h
	$(CC) -c main.c -o main.o $(CFLAGS)

dungeon_generation.o: dungeon_generation.c dungeon_generation.h
	$(CC) -c dungeon_generation.c -o dungeon_generation.o $(CFLAGS)

clean:
	rm -f dungeon *.o *~
