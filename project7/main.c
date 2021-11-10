/******************************
 * Tristan Larkin
 * Project 7
 * Given an n x n matrix of 1s and 0s, 
 * this prgram will output a path that uses 
 * 1s to get from (0,0) to (n - 1, n - 1)
 ****************************/

#include <stdlib.h>
#include <stdio.h>

#include "header.h"

/* Main() takes in argc and *argv[] andr returns 0
*/
int main(int argc, char *argv[])
{
  char c = 0;
  int count = 0;
  /* arraySize starts at 2, 
  but will get larger as needed. */
  int arraySize = 2;
  char *mazeArr = (char *)calloc((arraySize), sizeof(char));
  /* finds n be counting characters until there is 
  a newline */
  for (c = getchar(); c != '\n'; c = getchar()) 
  {
    if (count == arraySize)
    {
      /* by squaring the size we ensure that  */
      arraySize *= 2;
      mazeArr = (char *)realloc(mazeArr, (arraySize) * sizeof(char));
    }

    mazeArr[count] = c;
    count++;
  }
  /* sets n to be the width/height */
  n = count;
  mazeArr = (char *)realloc(mazeArr, (n * n) * sizeof(char));
  /* gets all the rest of the characters in the matrix. 
  Converts them into a 1d array */
  for (c = getchar(); c != EOF; c = getchar())
  {
    if (c != '\n')
    {
      mazeArr[count] = c;
      count++;
    }
  }

  /* if the algorithm returns a 1, then it worked */
  if (recursiveFindPath(mazeArr, 0) == 1)
  {
    printf("PATH FOUND!\n");
    printArray(mazeArr);
  }
  /* if the algorithm returns a 0, there was no path */
  else
  {
    printf("no path found.\n");
  }

  /* frees the memory of the 1 allocated array. */
  free(mazeArr);

  return 0;
}