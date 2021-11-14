/**************************************
* Tristan Larkin
* New Shapes 
* Prits out the shapes with characters shifted down 9 ascii numbers
**************************************/

#include <stdio.h>
#include <string.h>
#define SHIFT -9

int main()
{
  char shapes[] = "\
______________       ****            +\n\
:            :    ****  ****        / \\\n\
:            :   ****    ****      /   \\\n\
:            :  ****      ****    /     \\\n\
:            :  ****      ****   /       \\\n\
:            :   ****    ****   /         \\\n\
:            :    ****  ****   /           \\\n\
--------------       ****     /_____________\\\n";

  int i;

  for(i = 0; i < strlen(shapes); i = i + 1) /* loops through eachcharacter in the char[] */
    {
      char temp = shapes[i];

      switch(temp) /* only replaces the characters that are supposed to be changed */
      {
        case '-':
        case '_':
        case '/':
	case '\\':
        case ':':
        case '+':
	case '*':
	  printf("%c",temp + SHIFT);
	  break;
        default:
	  printf("%c",temp);
	  break;
      }

    }

  return 0;
}
