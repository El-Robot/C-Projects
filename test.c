#include <stdio.h>
#include <string.h>

void sort(int primary, int secondary, int numberOfRiders, char unsorted[4][3][20])
{
  int last = numberOfRiders;
  while (last > 0)
  {
    int left = 0;
    int right = 1;
    while (right < last)
    {
      if (strcmp(unsorted[left][primary], unsorted[right][primary]) > 0)
      {
        int i = 0;
        for (i = 0; i < 3; i++)
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

  last = numberOfRiders;
  while (last > 0)
  {
    int left = 0;
    int right = 1;
    while (right < last)
    {
      if (strcmp(unsorted[left][primary], unsorted[right][primary]) == 0 &&
          strcmp(unsorted[left][secondary], unsorted[right][secondary]) > 0)
      {
        int i = 0;
        for (i = 0; i < 3; i++)
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

int main()
{

  int *foo;
}