/******************************
 * Tristan Larkin
 * Project 7
 * Find Path Header File
 ****************************/

#ifndef HEADER_H
#define HEADER_H

extern int n; /* The width and height of the matrix */

/* Takes in a *char and returns void.
Will print an n x n grid. The grid will 
be printed with a zero in anly place that 
is not an 'x' in the given array.*/
void printArray(char *mazeSolution);

/* Takes in a *char and an int, and returns a 1 or 0.
Replaces the path from start to finish with 'x's 
takes a 1d char array and and integer as the inputs. */
int recursiveFindPath(char *maze, int index);

#endif