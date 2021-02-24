/******************************
 * Tristan Larkin
 * Project 2
 * Converting an ascii string into binary
 ****************************/

#include <stdio.h>
#include <string.h>
#include <math.h>

void asciiToBinary(char nextChar)
{
  int power;

  if (nextChar == '\n')
  {
    printf("\n");
  }
  else
  {
    for (power = 7; power > -1; power--)
    {

      if (nextChar >= pow(2, power))
      {
        nextChar = nextChar - pow(2, power);
        printf("1");
      }
      else
      {
        printf("0");
      }
    }
  }
}

int main()
{
  int c = 0;
  while (c != EOF)
  {
    c = getchar();
    asciiToBinary(c);
  }

  return 0;
}