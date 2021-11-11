/******************************
 * Tristan Larkin
 * Project 8
 * Clinic Project
 ****************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

/* Main method. Takes in a number of arguments 
and an array of strings. Returns 0.
The method will read the files with readFileMakeList()
then print to a new file with printPeople()*/
int main(int argc, char *argv[])
{
  patient_t *patientList = readFileMakeList(argv[1]);

  printPeople(patientList, argv[2]);

  return 0;
}