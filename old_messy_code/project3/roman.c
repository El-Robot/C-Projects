/*********************
 * Tristan Larkin
 * 
 * 
 *********************/

#include <stdio.h>

void asciiToRoman(char c)
{
  if (c == '\n')
  {
    printf("\n");
    return;
  }
  while (c > 0)
  {
    if (c >= 100)
    {
      printf("C");
      c = c - 100;
    }
    else if (c >= 90)
    {
      printf("XC");
      c = c - 90;
    }
    else if (c >= 50)
    {
      printf("L");
      c = c - 50;
    }
    else if (c >= 40)
    {
      printf("XL");
      c = c - 40;
    }
    else if (c >= 10)
    {
      printf("X");
      c = c - 10;
    }
    else if (c >= 9)
    {
      printf("IX");
      c = c - 9;
    }
    else if (c >= 5)
    {
      printf("V");
      c = c - 5;
    }
    else if (c >= 4)
    {
      printf("IV");
      c = c - 4;
    }
    else if (c >= 1)
    {
      printf("I");
      c = c - 1;
    }
  }
  printf(" ");
}

int main()
{

  int c;
  for (c = getchar(); c != EOF; c = getchar())
  {
    asciiToRoman(c);
  }

  return 0;
}