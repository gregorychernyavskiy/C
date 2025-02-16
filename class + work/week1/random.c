#include <stdlib.h>  // Includes functions for random number generation (rand() and srand()).
#include <stdio.h>   // Includes standard input/output functions (printf()).
#include <time.h>    // Provides time-related functions for seeding random number generators.

int main(int argc, char *argv[]) {
    // Seed the random number generator with the current time.
    // This ensures different random sequences on each program run and can only be used once in the program.
    srand(time(NULL));

    printf("%d\n", rand());
    printf("%d\n", rand());
    printf("%d\n", rand());

    printf("%c\n", 'a' + (rand() % 26));
    printf("%c\n", 'a' + (rand() % 26));
    printf("%c\n", 'a' + (rand() % 26));

    return 0;
}