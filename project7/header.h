/******************************
 * Tristan Larkin
 * Project 7
 * Find Path Header File
 ****************************/

#ifndef HEADER_H
#define HEADER_H

extern int n; /* The width and height of the matrix */

void printArray(char *mazeSolution);

int recursiveFindPath(char *maze, int index);

#endif