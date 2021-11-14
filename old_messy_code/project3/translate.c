/*********************
 * Tristan Larkin
 * 
 * 
 *********************/

#include <stdio.h>

int main()
{

  int nextC;
  int currentC = getchar();
  int reultInAscii = 0;

  for (nextC = getchar(); currentC != EOF; nextC = getchar())
  {

    int currentValue = 0;
    int nextValue = 0;

    switch (currentC)
    {
    case 67:
      currentValue = 100;
      break;

    case 76:
      currentValue = 50;
      break;

    case 88:
      currentValue = 10;
      break;

    case 86:
      currentValue = 5;
      break;

    case 73:
      currentValue = 1;
      break;

    case ' ':
      printf("%c", reultInAscii);
      reultInAscii = 0;
      break;

    case '\n':
      printf("\n");
      break;
    }

    switch (nextC)
    {
    case 67:
      nextValue = 100;
      break;

    case 76:
      nextValue = 50;
      break;

    case 88:
      nextValue = 10;
      break;

    case 86:
      nextValue = 5;
      break;

    case 73:
      nextValue = 1;
      break;

    default:
      break;
    }

    if (nextValue > currentValue)
    {
      currentValue *= -1;
    }

    reultInAscii += currentValue;
    currentC = nextC;
  }

  return 0;
}