/*********************
 * Tristan Larkin
 * Project 4
 * Roman numerals to ASCII
 *********************/

#include <stdio.h>
#include <ctype.h>

void errorMsg(char roman[])
{
    
}


int main()
{

    int nextC;
    int currentC = getchar();
    int reultInAscii = 0;

    for (nextC = getchar(); currentC != EOF; nextC = getchar())
    {

        int currentValue = characterRomanValue(currentC);
        int nextValue = characterRomanValue(nextC);

        if (nextValue > 10 * currentValue)
        {
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