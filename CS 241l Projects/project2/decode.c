/******************************
 * Tristan Larkin
 * Project 2
 * Converting an binary string into ascii
 ****************************/

#include <stdio.h>
#include <string.h>

int currentWorkingChar; /* keeps track of important information */
int lines = 1;
int lineChar = 0;
int totalChar = 0;
int words = 1;
int power = 7;

int main()
{
  int c = 0;
  for(;c != EOF; c = getchar()) /* loops through all the input chars */
  {

    if (c == '\n') /* ignore newlines as part of the conversion process */
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
    else /* if it is not a newline the program will add up avery 8 didgits in the way a human would count in binary, 
            that information is saved and printed every 8 characters */
    {
      if (c == '1')
      {
        currentWorkingChar = currentWorkingChar + (1 << power); /* 1 << power acts as 2^power */
        power--;
      }
      if (c == '0')
      {
        power--;
      }

      if (power < 0)
      {
        if (currentWorkingChar == ' ') /* adds words to counts when it comes across spaces */
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