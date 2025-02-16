#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <time.h>   

#define MAX 20

char puzzle[MAX][MAX];

void createPuzzle(int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            puzzle[i][j] = '.';
        }
    }
}

void printPuzzle(int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            printf(" %c", puzzle[i][j]);
        }
        printf("\n");
    }
}

void randomLetters(int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (puzzle[i][j] == '.') {
                puzzle[i][j] = 'A' + (rand() % 26);
            }
        }
    }
}


void placeWord(char *word, int row, int col, int direction) {
    int word_len = strlen(word);
    //Horizontal
    if (direction == 0) {
        for (int i = 0; i < word_len; i++) {
            puzzle[row][col + i] = word[i];
        }
      // Vertical
    } else if (direction == 1) {
        for (int i = 0; i < word_len; i++) {
            puzzle[row + i][col] = word[i];
        }
      // Diagonal Down
    } else if (direction == 2) {
        for (int i = 0; i < word_len; i++) {
            puzzle[row + i][col + i] = word[i];
        }
      // Diagonal U p
    } else if (direction == 3) {
        for (int i = 0; i < word_len; i++) {
            puzzle[row - i][col + i] = word[i];
        }
    }
}


int canPlace(int len, char *word, int row, int col) {
    int wordlen = strlen(word);
    int directions[4];
    int count = 0;

    if (col + wordlen <= len) {
        int fits = 1;
        for (int i = 0; i < wordlen; i++) {
            if (puzzle[row][col + i] != '.' && puzzle[row][col + i] != word[i]) {
                fits = 0;
                break;
            }
        }
        if (fits) {
            directions[count++] = 0;
        }
    }
    if (row + wordlen <= len) {
        int fits = 1;
        for (int i = 0; i < wordlen; i++) {
            if (puzzle[row + i][col] != '.' && puzzle[row + i][col] != word[i]) {
                fits = 0;
                break;
            }
        }
        if (fits) {
            directions[count++] = 1;
        }
    }
    if (row + wordlen <= len && col + wordlen <= len) {
        int fits = 1;
        for (int i = 0; i < wordlen; i++) {
            if (puzzle[row + i][col + i] != '.' && puzzle[row + i][col + i] != word[i]) {
                fits = 0;
                break;
            }
        }
        if (fits) {
            directions[count++] = 2;
        }
    }
    if (row - wordlen + 1 >= 0 && col + wordlen <= len) {
        int fits = 1;
        for (int i = 0; i < wordlen; i++) {
            if (puzzle[row - i][col + i] != '.' && puzzle[row - i][col + i] != word[i]) {
                fits = 0;
                break;
            }
        }
        if (fits) {
            directions[count++] = 3;
        }
    }

    if (count == 0) {
        return -1;
    }

    return directions[rand() % count]; 
}


int main(int argc, char *argv[]) {

    int len = atoi(argv[1]);


    srand(time(NULL));
    createPuzzle(len);


    for (int w = 2; w < argc; w++) {
        char *word = argv[w];
        int placed = 0;

        for (int attempts = 0; attempts < 400 && !placed; attempts++) {
            int row = rand() % len;
            int col = rand() % len;

            int direction = canPlace(len, word, row, col);
            if (direction != -1) {
                placeWord(word, row, col, direction);
                placed = 1;
            }
        }

        if (!placed) {
            printf("Couldn't place the word: %s\n", word);
            return 1;
        }
    }


    randomLetters(len);
    printPuzzle(len);

    printf("\nWord List:\n");
    for (int w = 2; w < argc; w++) {
        printf("%s\n", argv[w]);
    }

    return 0;
}