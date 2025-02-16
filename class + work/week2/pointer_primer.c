#include <stdio.h>
#include <stdlib.h>

struct foo {
  int x;
  float y;
  char *s;
};
void populate_foo(struct foo *f)
{
  f->x = 42;
  f->y = 3.1415;

  printf("i = %d, f = %f\n", f->x, f->y);
}

void swap(int *i, int *j) {

  int tmp;
  
  tmp = *i;
  *i = *j;
  *j = tmp;
}

int main(int argc, char *argv[])
{
  struct foo f;

  int i = 0;
  int j = 1;

  int *p;

  swap(&i, &j);
  printf("%d %d\n", i, j);

  p = &i;
  printf("%d\n", *p);



  p = malloc(sizeof (*p)); // sizeof is a static operator
  printf("%d\n", *p); // Error: *p hasn't been initialized

  *p = 5;
  printf("%d\n", *p);
  
  free(p);

  printf("%d\n", *p); // Error, the data address of p no longer belongs to this program.
  printf("\n");

  p = malloc(10 * sizeof (*p));
  for(int i = 0; i < 10; i++) {
    p[i] = i;
  }

  for(int i = 0; i < 10; i++) {
                // pointer arithmetic
    printf("%d\n", *(p + i)); // or p[i]
  }

  free(p);



  f.x = 0;
  f.y = 0;
  // populate_foo(&f);
  // printf("i = %d, f = %f\n", f.x, f.y);

  return 0;

  //check the difference between alocating it dynamically vs statically
}
