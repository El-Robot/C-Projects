/*********************
 * Tristan Larkin
 * Project 4
 * Roman numerals to ASCII with varification
 * 
 *********************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char currentRoman[15] = {' '};
int length = 0;

void checkValidity(char input[], int l)
{
  char str[15] = "";
  int result = 0;
  int i;
  int j;
  int repeatCount = 0;
  int smallestPrint = 1000;
  int hundreds = 0;
  int tens = 0;
  int ones = 0;

  /* If it is too large the number will just return an error */
  if (l > 15)
  {
    printf("[Unable to read character string]");
    return;
  }

  /* To uppercase */
  for (i = 0; i < l; i++)
  {
    str[i] = toupper(input[i]);
  }

  for (j = 0; j < l; j++)
  {
    int currentValue = 0;
    int nextValue = 0;

    switch (tolower(input[j]))
    {
    case 'm':
      currentValue = 1000;
      break;
    case 'd':
      currentValue = 500;
      break;
    case 'c':
      currentValue = 100;
      break;
    case 'l':
      currentValue = 50;
      break;
    case 'x':
      currentValue = 10;
      break;
    case 'v':
      currentValue = 5;
      break;
    case 'i':
      currentValue = 1;
      break;
    default:
      printf("[Error: %s is not a Roman numeral]", str);
      return;
      break;
    }

    if (j != l - 1)
    {
      switch (tolower(input[j + 1]))
      {
      case 'm':
        nextValue = 1000;
        break;
      case 'd':
        nextValue = 500;
        break;
      case 'c':
        nextValue = 100;
        break;
      case 'l':
        nextValue = 50;
        break;
      case 'x':
        nextValue = 10;
        break;
      case 'v':
        nextValue = 5;
        break;
      case 'i':
        nextValue = 1;
        break;
      default:
        printf("[Error: %s is not a Roman numeral]", str);
        return;
        break;
      }
    }
    else
    {
      nextValue = 0;
    }

    /****************************************************/
    /* testing if it is a valid roman numeral */

    /* If a V, L, or D comes up consecutively, throw error
    or if a character repeats 4 times throw error*/

    if (currentValue == nextValue)
    {
      if (currentValue == 5 || currentValue == 50 || currentValue == 500)
      {
        printf("[Error:Roman numeral %s does not exist]", str);
        return;
      }

      repeatCount++;
      if (repeatCount == 3)
      {
        printf("[Error:Roman numeral %s does not exist]", str);
        return;
      }
    }

    if (nextValue > currentValue)
    {
      currentValue = nextValue - currentValue;
      j++;

      if (currentValue == 5 || currentValue == 50 || currentValue == 500)
      {
        printf("[Error:Roman numeral %s does not exist]", str);
        return;
      }
    }

    else
    {
      repeatCount = 0;
    }

    /* keeps track of how large previous numerals were */
    if (smallestPrint > currentValue)
    {
      smallestPrint = currentValue;
    }

    /*if a numeral is larger than the last numeral, the whole thing is not valid*/
    if (currentValue > smallestPrint)
    {
      printf("[Error:Roman numeral %s does not exist]", str);
      return;
    }

    /* this next section basically does a manual regex to the roman characters
    it will throw an error if there is an repeated number in the group [9,4,(5,1,1,1)].
    the group (5,1,1,1) means that there can be a 5 then 1s or just 1s, but not a 9 then ones or a 5 and a 5
    if no if statement is triggered it means that the number cannot legally exist and will throw error */
    if (currentValue == 1000)
    {
    }

    else if (currentValue == 900 || currentValue == 400)
    {
      hundreds += 4;
      if (hundreds > 4)
      {
        printf("[Error:Roman numeral %s does not exist]", str);
        return;
      }
    }

    else if (currentValue == 500 || currentValue == 100)
    {
      hundreds++;
      if (hundreds > 4)
      {
        printf("[Error:Roman numeral %s does not exist]", str);
        return;
      }
    }

    else if (currentValue == 90 || currentValue == 40)
    {
      tens += 4;
      if (tens > 4)
      {
        printf("[Error:Roman numeral %s does not exist]", str);
        return;
      }
    }

    else if (currentValue == 50 || currentValue == 10)
    {
      tens++;
      if (tens > 4)
      {
        printf("[Error:Roman numeral %s does not exist]", str);
        return;
      }
    }

    else if (currentValue == 9 || currentValue == 4)
    {
      ones += 4;
      if (ones > 4)
      {
        printf("[Error:Roman numeral %s does not exist]", str);
        return;
      }
    }

    else if (currentValue == 5 || currentValue == 1)
    {
      ones++;
      if (ones > 4)
      {
        printf("[Error:Roman numeral %s does not exist]", str);
        return;
      }
    }
    else
    {
      printf("[Error:Roman numeral %s does not exist]", str);
      return;
    }

    result += currentValue; /* Adds curretn numeral to the total for this string */
  }
  /*********************************************************/
  /* testing if it is a printable ascii */

  if (result < 32 || result > 125)
  {
    printf("[Error: %d is not a printable ASCII character]", result);
    return;
  }
  /********************************************************/
  
  printf("%c", result);
}

void printStringToLength(char str[], int l)
{
  int i = 0;
  while (i < l)
  {
    printf("%c", str[i]);
    i++;
  }
}

int main()
{

  char currentC;

  for (currentC = getchar(); currentC != EOF; currentC = getchar())
  {

    if (currentC == '\n')
    {
      printf("\n");
      continue;
    }

    if (currentC == ' ')
    {
      checkValidity(currentRoman, length);
      length = 0;
      continue;
    }

    currentRoman[length] = currentC;
    length++;
  }

  return 0;
}