/*********************
 * Tristan Larkin
 * Project 5
 * Format and organize fields in an input
 * 
 *********************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* can be changed for a different number of riders */
#define NUMOFRIDERS 146

char addedUpTimes[NUMOFRIDERS][6][20];
int teamCount;
int numOfTeams;

/***********************************************
 * Bubble sorts everything by alphabetical order
 * Compares strings using the strcmp() method
 * and does it all in place except for a 
 * temp array
 **********************************************/
void sortAlphabet(int attribute, char unsorted[NUMOFRIDERS][6][20])
{
  int last = NUMOFRIDERS;
  while (last > 0)
  {
    int left = 0;
    int right = 1;
    while (right < last)
    {
      /* Use strcmp() to compare the strings and decide if they need to be swayed*/
      if (strcmp(unsorted[left][attribute], unsorted[right][attribute]) > 0)
      {
        int i = 0;
        for (i = 0; i < 6; i++)
        {
          /* swaps the entire row of the array so the information
          on any row is always consistant */
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

/********************************************* 
 * Buble sorts strings that can be converted to ints 
 * Same as above, but the comparison is done by
 * transforming the string to an integer 
 * (EX. char[]"45" becomes int 45) using atoi().
 * Then it uses < and >.
 *********************************************/
void sortNumerical(int attribute, char unsorted[NUMOFRIDERS][6][20])
{
  int last = NUMOFRIDERS;
  while (last > 0)
  {
    int left = 0;
    int right = 1;
    while (right < last)
    {
      /* compares using the inequality sign instead of the strcompare
      after changing the string to an int */
      if (atoi(unsorted[left][attribute]) > atoi(unsorted[right][attribute]))
      {
        int i = 0;
        for (i = 0; i < 6; i++)
        {
          /* same as above */
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

/************************************ 
 * Adds two times together 
 * Uses sscanf() to get the min, hours, and sec.
 * Then it adds them together to and uses sprintf()
 * to put the new time values into a string variable.
 *********************************************/
void timeAddition(char *time1, char time2[20])
{
  int hour1 = 0;
  int min1 = 0;
  int sec1 = 0;
  int hour2 = 0;
  int min2 = 0;
  int sec2 = 0;

  sscanf(time1, "%d:%d:%d", &hour1, &min1, &sec1);
  sscanf(time2, "%d:%d:%d", &hour2, &min2, &sec2);

  hour1 += hour2;
  min1 += min2;
  sec1 += sec2;

  if (sec1 >= 60)
  {
    min1 += 1;
    sec1 %= 60;
  }

  if (min1 >= 60)
  {
    hour1 += 1;
    min1 %= 60;
  }

  sprintf(time1, "%d:%02d:%02d", hour1, min1, sec1);
}

/*********************************************
 * Main() has all the different if staements based 
 * on what CMD line args are used.
 *********************************************/
int main(int argc, char *argv[])
{

  char fields[NUMOFRIDERS][6][20] = {0};
  /* what each item in the array is:
  0: Classification
  1: Rider
  2: Rider No.
  3: Country
  4: Team
  5: Time */

  /* copy the input loop */
  int index = 0;
  while (index < NUMOFRIDERS)
  {
    /*takes the input into the fields array in a way that 
    is easy to access later*/
    scanf("%s%s%s%s%s%s",
          fields[index][0],
          fields[index][1],
          fields[index][2],
          fields[index][3],
          fields[index][4],
          fields[index][5]);
    index += 1;
  }

  /* when the CL arg is "format" */
  if (strcmp(argv[1], "format") == 0)
  {
    index = 0;
    /* using "%-20s" to format the strings to be all the
    same length (20 characters) */
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

  /* when the CL arg is "country" */
  if (strcmp(argv[1], "country") == 0)
  {
    /* sorting twice will give a result that is sorted by the 
    second sort call, but ant ties in the second call are 
    sorted by the attrivute in the first call */
    sortAlphabet(1, fields); /* Rider */
    sortAlphabet(3, fields); /* Country */

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

  /* when the CL arg is "team" */
  if (strcmp(argv[1], "team") == 0)
  {

    sortNumerical(2, fields); /* Rider No. */

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

  /* when the CL arg is "extra" */
  if (strcmp(argv[1], "extra") == 0)
  {
    int i;
    char tempTime[] = "000:00:00";

    sortAlphabet(4, fields);

    index = 0;

    for (i = 0; i < NUMOFRIDERS; i++)
    {
      if (strcmp(addedUpTimes[index - 1][0], fields[i][4]) != 0)
      {
        teamCount = 0;
        strcpy(tempTime, "00:00:00");
      }

      if (teamCount == 0)
      {
        strcpy(addedUpTimes[index][0], fields[i][4]);
        index++;
      }

      if (teamCount < 2)
      {
        timeAddition(tempTime, fields[i][5]);
      }

      if (teamCount == 2)
      {
        strcpy(addedUpTimes[index - 1][1], tempTime);
        numOfTeams++;
      }

      teamCount++;
    }

    sortAlphabet(1, addedUpTimes);

    index = NUMOFRIDERS - numOfTeams;
    printf("%-20s%-20s\n",
           "Team",
           "Time (hh:mm:ss)");
    while (index < NUMOFRIDERS)
    {

      printf("%-20s%s\n",
             addedUpTimes[index][0],
             addedUpTimes[index][1]);
      index += 1;
    }
  }

  return 0;
}
