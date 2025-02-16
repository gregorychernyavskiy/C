#include <stdio.h>

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

  f.x = 0;
  f.y = 0;

  populate_foo(&f);
  printf("x = %d, y = %f\n", f.x, f.y);

  return 0;
}