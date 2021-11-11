/******************************
 * Tristan Larkin
 * Project 8
 * Clinic Project
 ****************************/

#ifndef HEADER_H
#define HEADER_H

typedef struct patient
{
  int id;
  int time;
  int age;
  int pain;

  struct patient *next;

} patient_t;

int comparePatient(patient_t person1, patient_t person2);

patient_t *newPerson(int id, char *time, int age, int pain, patient_t *nextPatient);

patient_t *readFileMakeList(char *inputFileName);

void printPeople(patient_t *beginning, char *fileName);

#endif