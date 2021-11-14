/******************************
 * Tristan Larkin
 * Project 2
 * Converting an ascii string into binary
 ****************************/

#include <stdio.h>
#include <string.h>

void asciiToBinary(char nextChar) /* uses the method of subtracting from the character value by decreasing powers of teo until it is at zero, 
                                     then the binary value is known */
{
  int power;

  if (nextChar == '\n') /* skips newlines */
  {
    printf("\n");
  }
  else
  {
    for (power = 7; power > -1; power--)
    {

      if (nextChar >= (1 << power)) /* uses 1 << power in place of pow() */
      {
        nextChar = nextChar - (1 << power);
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
  int c;
  for(c = getchar(); c != EOF; c = getchar()) /* loops through all the chars in the file given */
  {
    asciiToBinary(c);
  }

  return 0;
}