/******************************
 * Tristan Larkin
 * Project 2
 * Converting an binary string into ascii
 ****************************/

#include <stdio.h>
#include <string.h>

int currentWorkingChar;
int lines = 1;
int lineChar = 0;
int totalChar = 0;
int words = 1;
int power = 7;

int main()
{
  int c = 0;
  for(;c != EOF; c = getchar())
  {

    if (c == '\n')
    {
      if (lineChar > 0)
      {
        words++;
      }
      printf(" (%i,%i)", lines, lineChar);
      printf("\n");
      lineChar = 0;
      lines++;
    }
    else
    {
      if (c == '1')
      {
        currentWorkingChar = currentWorkingChar + (1 << power);
        power--;
      }
      if (c == '0')
      {
        power--;
      }

      if (power < 0)
      {
        if (currentWorkingChar == ' ')
        {
          words++;
        }

        power = 7;
        printf("%c", currentWorkingChar);
        currentWorkingChar = 0;
        lineChar++;
        totalChar++;
      }
    }
  }
  printf(" (%i,%i)", lines, lineChar);
  printf("\n\nThere are %i characters, %i words, %i lines\n", totalChar, words, lines);

  return 0;
}