/*********************
 * Tristan Larkin
 * Project 4
 * Roman numerals to ASCII
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

    /***************************************************************************************/

    /* testing if it is a valid roman numeral */
    if (nextValue == currentValue)
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
    else
    {
      repeatCount = 0;
    }

    if (nextValue > currentValue)
    {
      if (nextValue / currentValue > 10)
      {
        printf("[Error:Roman numeral %s does not exist]", str);
        return;
      }

      if (currentValue == 5 || currentValue == 50 || currentValue == 500)
      {
        printf("[Error:Roman numeral %s does not exist]", str);
        return;
      }

      currentValue = nextValue - currentValue;
      j++;
    }

    if (smallestPrint > currentValue)
    {
      smallestPrint = currentValue;
    }

    if (currentValue > smallestPrint)
    {
      printf("[Error:Roman numeral %s does not exist]", str);
      return;
    }

    if (currentValue == 900 || currentValue == 400)
    {
      hundreds += 4;
      if (hundreds > 4)
      {
        printf("[Error:Roman numeral %s does not exist]", str);
        return;
      }
    }

    if (currentValue == 500 || currentValue == 100)
    {
      hundreds++;
      if (hundreds > 4)
      {
        printf("[Error:Roman numeral %s does not exist]", str);
        return;
      }
    }

    if (currentValue == 90 || currentValue == 40)
    {
      tens += 4;
      if (tens > 4)
      {
        printf("[Error:Roman numeral %s does not exist]", str);
        return;
      }
    }

    if (currentValue == 50 || currentValue == 10)
    {
      tens++;
      if (tens > 4)
      {
        printf("[Error:Roman numeral %s does not exist]", str);
        return;
      }
    }

    if (currentValue == 9 || currentValue == 4)
    {
      ones += 4;
      if (ones > 4)
      {
        printf("[Error:Roman numeral %s does not exist]", str);
        return;
      }
    }

    if (currentValue == 5 || currentValue == 1)
    {
      ones++;
      if (ones > 4)
      {
        printf("[Error:Roman numeral %s does not exist]", str);
        return;
      }
    }

    

    result += currentValue;
  }
  /***************************************************************************************/

  /* testing if it is a printable ascii */
  if (result < 32 || result > 125)
  {
    printf("[Error: %d is not a printable ASCII character]", result);
    return;
  }
  /***************************************************************************************/
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
  /* 
  char currentC = getchar(); 
  */

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