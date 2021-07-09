#include <stdio.h>
#include <stdlib.h>

/**
    Create a structure named Date having day, month and year as
    its elements. Store the current date in the structure. Now
    add 45 days to the current date and display the final date.
*/

typedef struct {
    int day, month, year;
} Date;


int main()
{
    Date today;
    printf("\nIntrodu data de astazi: \n");
    printf("\nZiua: ");
    scanf("%d", &today.day);
    printf("\nLuna: ");
    scanf("%d", &today.month);
    printf("\nAnul: ");
    scanf("%d", &today.year);



    switch(today.month)
    {
    case 1:
        today.day = today.day + 45 - 31;
        if (today.day > 28)
        {
            today.day -= 28;
            today.month += 2;
        }
        else
            today.month++;
        break;
    case 2:
        today.day = today.day + 45 - 28;
        if (today.day > 31)
        {
            today.day -= 31;
            today.month += 2;
        }
        else
            today.month++;
        break;
    case 3:
        today.day = today.day + 45 - 31;
        if (today.day > 30)
        {
            today.day -= 30;
            today.month += 2;
        }
        else
            today.month++;
        break;
    case 4:
        today.day = today.day + 45 - 30;
        if (today.day > 31)
        {
            today.day -= 31;
            today.month += 2;
        }
        else
            today.month++;
        break;
    case 5:
        today.day = today.day + 45 - 31;
        if (today.day > 30)
        {
            today.day -= 30;
            today.month += 2;
        }
        else
            today.month++;
        break;
    case 6:
        today.day = today.day + 45 - 30;
        if (today.day > 31)
        {
            today.day -= 31;
            today.month += 2;
        }
        else
            today.month++;
        break;
    case 7:
        today.day = today.day + 45 - 31;
        if (today.day > 31)
        {
            today.day -= 31;
            today.month += 2;
        }
        else
            today.month++;
        break;
    case 8:
        today.day = today.day + 45 - 31;
        if (today.day > 30)
        {
            today.day -= 30;
            today.month += 2;
        }
        else
            today.month++;
        break;
    case 9:
        today.day = today.day + 45 - 30;
        if (today.day > 31)
        {
            today.day -= 31;
            today.month += 2;
        }
        else
            today.month++;
        break;
    case 10:
        today.day = today.day + 45 - 31;
        if (today.day > 30)
        {
            today.day -= 30;
            today.month += 2;
        }
        else
            today.month++;
        break;
    case 11:
        today.day = today.day + 45 - 30;
        if (today.day > 31)
        {
            today.day -= 31;
            today.month = 1;
            today.year++;
        }
        else
            today.month++;
        break;
    case 12:
        today.day = today.day + 45 - 31;
        if (today.day > 31)
        {
            today.day -= 31;
            today.month = 2;
            today.year++;
        }
        else
            {
                today.month = 1;
                today.year++;
            }
        break;
    }

    printf("\nData de peste 45 de zile va fi: %d.%d.%d\n",
            today.day, today.month, today.year);

    return 0;
}
