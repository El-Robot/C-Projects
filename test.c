#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

  int *foo;
  int *fug;

  foo = malloc(3 * sizeof(int));
  fug = malloc(10 * sizeof(int));

  foo[10] = 10;
  printf("%d", sizeof(malloc(10 * sizeof(int))));

  free(foo);
  return 0;
}