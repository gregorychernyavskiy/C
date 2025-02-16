#include <stdio.h>

#define MAX 10

int table[MAX][MAX];

void populate_table(int table[MAX][MAX]);

int main(int argc, char *argv[])
{
  int i, j;

  populate_table(table);

  for (j = 0; j < MAX; j++) {
    for (i = 0; i < MAX; i++) {
      printf("%3d ", table[j][i]);
    }
    printf("\n");
  }
}

void populate_table(int table[MAX][MAX])
{
  int i, j;

  for (j = 0; j < MAX; j++) {
    for (i = 0; i < MAX; i++) {
      table[j][i] = (i + 1) * (j + 1);
    }
  }
}

