/******************************
 * Tristan Larkin
 * Project 8
 * Clinic Project
 ****************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

/* head of the linked list.
Will not work in main.c. */
patient_t *head;

/* Takes two patitent_t as input
returns 1 or -1 .
1 means person1 comes before person2.
-1 means person2 comes before person1.
Copmarisons are made between pain first,
then if pain ties, age,
and if age ties, arrival time.
*/
int comparePatient(patient_t person1, patient_t person2)
{
  if (person1.pain > person2.pain)
  {
    return 1;
  }
  if (person1.pain < person2.pain)
  {
    return -1;
  }
  if (person1.pain == person2.pain)
  {
    if (person1.age > person2.age)
    {
      return 1;
    }
    if (person1.age < person2.age)
    {
      return -1;
    }
    if (person1.age == person2.age)
    {
      if (person1.time < person2.time)
      {
        return 1;
      }
      if (person1.time > person2.time)
      {
        return -1;
      }
    }
  }
  return -1;
}

/* Takes an int id, char *time, int age, int pain, 
and a pointer to another patient_t.
It returns a newly allocated patient_t that points to 
the given patient_t.
The time is converted into a number of seconds
*/
patient_t *newPerson(int id, char *time,
                     int age, int pain, patient_t *nextPatient)
{
  patient_t *person = (patient_t *)malloc(sizeof(patient_t));
  int hr = 0, min = 0, sec = 0;

  person->id = id;
  sscanf(time, "%d:%d:%d:", &hr, &min, &sec);
  person->time = sec + min * 60 + hr * 3600;
  person->age = age;
  person->pain = pain;
  person->next = nextPatient;

  return person;
}

/* takes in a patient_t *personToInsert
returns void
It will loop through the linked list of patient_ts until 
it finds a patient that should go after the given patient_t.
If it reached the end, it will insert it there.
*/
void insertPerson(patient_t *personToInsert)
{
  patient_t *current = head;
  patient_t *prev = head;
  while (comparePatient(*personToInsert, *current) < 0)
  {
    prev = current;
    current = current->next;
  }

  if (current == head)
  {
    personToInsert->next = head;
    head = personToInsert;
  }

  else
  {
    prev->next = personToInsert;
    personToInsert->next = current;
  }
}

/* takes in a filename as a char*
returns a patient_t* that is the head of the linked list.
Goes through the given file, looking for information
in the correct format. */
patient_t *readFileMakeList(char *inputFileName)
{
  int tempId = 0, tempAge = 0, tempPain = 0;
  char tempTime[8];
  FILE *inputFile;

  /* Initial person that will always compare as lower
  priority. */
  head = newPerson(-1, "00:00:00", -1, -1, NULL);

  inputFile = fopen(inputFileName, "r");

  while (fscanf(inputFile, "%d %s %d %d\n",
                &tempId, tempTime, &tempAge, &tempPain) > 0)
  {
    patient_t *tempPerson = newPerson(
        tempId, tempTime, tempAge, tempPain, NULL);
    insertPerson(tempPerson);
  }

  fclose(inputFile);

  return head;
}

/* takes in the head of a linked list of patient_t
and a name of a file.
Will append all of the information of each of the patients
in the linked list to the file given. It loops until the 
head is the person with -1 pain. The loop will repeat looking 
for the next person to treat. After it finds someone and prints them
it will remove them from the linked list.
It will immediately find the first pain = 10
If there are no paint = 10 patients, then it will find the person who
has waited the longest if they are over 2 hrs.
If there are none of them, it will find the next person
who has already arrived.
The clock is moved up by 60 * 15 seconds each loop. */
void printPeople(patient_t *beginning, char *fileName)
{
  FILE *outputFile;
  int currentTime = 7 * 3600 + 45 * 60;
  int counter = 0;
  patient_t *chosen = beginning;
  patient_t *current = beginning;
  patient_t *prev = beginning;

  outputFile = fopen(fileName, "w");

  while (beginning->pain != -1)
  {
    int override = 0;
    patient_t *beforeChosen = NULL;
    counter = 0;
    chosen = NULL;
    current = beginning;
    prev = beginning;

    while (current->pain != -1)
    {
      counter++;
      if (override < 1 && currentTime >= current->time)
      {
        beforeChosen = prev;
        chosen = current;
        override = 1;
      }

      if (current->pain == 10 && currentTime >= current->time)
      {
        beforeChosen = prev;
        chosen = current;
        break;
      }

      if (currentTime - current->time > override && currentTime - 7200 >= current->time)
      {
        beforeChosen = prev;
        chosen = current;
        override = currentTime - current->time;
      }

      prev = current;
      current = current->next;
    }

    fprintf(outputFile, "%02d:%02d:00 Patient: ID = %d, Pain Level (1-10) = %d, \
Age = %d years, Time waiting = %02dh%02dm%02ds\n",
           (currentTime) / 3600,
           ((currentTime) % 3600) / 60,
           chosen->id,
           chosen->pain,
           chosen->age,
           (currentTime - chosen->time) / 3600,
           ((currentTime - chosen->time) % 3600) / 60,
           ((currentTime - chosen->time) % 60));

    if (chosen == beginning)
    {
      beginning = beginning->next;
    }
    else
    {
      beforeChosen->next = chosen->next;
    }
    free(chosen);

    currentTime += 15 * 60;
  }
  free(beginning);
  fclose(outputFile);
}