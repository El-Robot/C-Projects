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

/* extern variable that will keep track of
the length n of the n x n array';lkjhg */
int n = 0;

/* Takes in a *char and returns void.
Will print an n x n grid. The grid will 
be printed with a zero in anly place that 
is not an 'x' in the given array.*/
void printArray(char *mazeSolution)
{
  int i;

  for (i = 0; i < n * n; i++)
  {
    if (mazeSolution[i] == 'x')
    {
      printf("%c", '1');
    }
    else
    {
      printf("%c", '0');
    }

    if ((i + 1) % n == 0)
    {
      printf("\n");
    }
  }
}

/* Takes in a *char and an int, and returns a 1 or 0.
Replaces the path from start to finish with 'x's 
takes a 1d char array and and integer as the inputs. */
int recursiveFindPath(char *maze, int index)
{
  /* Base case. If the index is at the end of the array, it returns 1,
  which will tell past iterations that this is the correct path.*/
  if (index == n * n - 1)
  {
    maze[index] = 'x';
    return 1;
  }
  /* Going right
  if in bounds and is a '1', then call recursiveFindPath()
  of the index to the right. If it is true, then change the 
  current indexed item to an 'x' to mark it is correct.*/
  if (((index + 1) % n != 0) && (maze[index + 1] == '1'))
  {
    int r = recursiveFindPath(maze, index + 1);
    if (r == 1)
    {
      maze[index] = 'x';
      return 1;
    }
  }
  /* Going right
  if in bounds and is a '1', then call recursiveFindPath()
  of the index of the element down. If it is true, then change the 
  current indexed item to an 'x' to mark it is correct.*/
  if (((index + n) < n * n) && (maze[index + n] == '1'))
  {
    int d = recursiveFindPath(maze, index + n);
    if (d == 1)
    {
      maze[index] = 'x';
      return 1;
    }
  }

  /* If it all fails
  then change the current item to '0' because
  it might as well be a wall, that way the program does 
  not confuse it to be a possible path in the
  future. */
  maze[index] = '0';
  return 0;
}
