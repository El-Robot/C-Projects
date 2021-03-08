#include <stdio.h>

int main()
{
  char test[] = "Hello";
  char d[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
  char loser[] = "loser";
  char e[5] = {'H', 'e', 'l', 'l', 'o'};
  char *c = "Hello";

  printf("%s\n", d);
  printf("%s\n", e);
  printf("%s\n", test);
  printf("%s\n", *c);
}