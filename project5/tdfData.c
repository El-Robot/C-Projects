/*********************
 * Tristan Larkin
 * Project 5
 * Format and organize fields in an input
 * 
 *********************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMOFRIDERS 146
#define MAXLENGTH 20

void sortAlphabet(int attribute, char unsorted[NUMOFRIDERS][6][20])
{
  int last = NUMOFRIDERS;
  while (last > 0)
  {
    int left = 0;
    int right = 1;
    while (right < last)
    {
      if (strcmp(unsorted[left][attribute], unsorted[right][attribute]) > 0)
      {
        int i = 0;
        for (i = 0; i < 6; i++)
        {
          char temp[20] = {0};
          strcpy(temp, unsorted[left][i]);
          strcpy(unsorted[left][i], unsorted[right][i]);
          strcpy(unsorted[right][i], temp);
        }
      }

      right++;
      left++;
    }
    last--;
  }
}

void sortNumerical(int attribute, char unsorted[NUMOFRIDERS][6][20])
{
  int last = NUMOFRIDERS;
  while (last > 0)
  {
    int left = 0;
    int right = 1;
    while (right < last)
    {
      if (atoi(unsorted[left][attribute]) > atoi(unsorted[right][attribute]))
      {
        int i = 0;
        for (i = 0; i < 6; i++)
        {
          char temp[20] = {0};
          strcpy(temp, unsorted[left][i]);
          strcpy(unsorted[left][i], unsorted[right][i]);
          strcpy(unsorted[right][i], temp);
        }
      }

      right++;
      left++;
    }
    last--;
  }
}


int main(int argc, char *argv[])
{

  char fields[NUMOFRIDERS][6][MAXLENGTH] = {0};
  /* 
  0: Classification,
  1: Rider, 
  2: Rider No., 
  3: Country, 
  4: Team, 
  5: Time */

  int index = 0;
  while (index < NUMOFRIDERS)
  {
    scanf("%s%s%s%s%s%s",
          fields[index][0],
          fields[index][1],
          fields[index][2],
          fields[index][3],
          fields[index][4],
          fields[index][5]);
    index += 1;
  }

  if (strcmp(argv[1], "format") == 0)
  {
    index = 0;
    printf("%-20s%-20s%-20s%-20s%-20s%-20s\n",
           "Classification",
           "Rider",
           "Rider No.",
           "Country",
           "Team",
           "Time (hh:mm:ss)");
    while (index < NUMOFRIDERS)
    {
      printf("%-20s%-20s%-20s%-20s%-20s%s\n",
             fields[index][0],
             fields[index][1],
             fields[index][2],
             fields[index][3],
             fields[index][4],
             fields[index][5]);
      index += 1;
    }
  }

  if (strcmp(argv[1], "country") == 0)
  {
    sortAlphabet(1, fields);
    sortAlphabet(3, fields);

    index = 0;
    printf("%-20s%-20s%-20s%-20s\n",
           "Country",
           "Rider",
           "Classification",
           "Time (hh:mm:ss)");
    while (index < NUMOFRIDERS)
    {
      printf("%-20s%-20s%-20s%s\n",
             fields[index][3],
             fields[index][1],
             fields[index][0],
             fields[index][5]);
      index += 1;
    }
  }

  if (strcmp(argv[1], "team") == 0)
  {

    sortNumerical(2, fields);

    index = 0;
    printf("%-20s%-20s%-20s%-20s\n",
           "Team",
           "Rider No.",
           "Rider",
           "Time (hh:mm:ss)");
    while (index < NUMOFRIDERS)
    {
      printf("%-20s%-20s%-20s%s\n",
             fields[index][4],
             fields[index][2],
             fields[index][1],
             fields[index][5]);
      index += 1;
    }
  }

  if (strcmp(argv[1], "extra") == 0)
  {

    sortAlphabet(3, fields);

    

    index = 0;
    printf("%-20s%-20s\n",
           "Team",
           "Time (hh:mm:ss)");
    while (index < NUMOFRIDERS)
    {
      printf("%-20s%s\n",
             fields[index][4],
             fields[index][5]);
      index += 1;
    }
  }

  return 0;
}
