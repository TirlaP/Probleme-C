#include <stdio.h>
#include <stdlib.h>

/**
    Write a program to compare two dates entered by user. Make a
    structure named Date to store the elements day, month and
    year to store the dates. If the dates are equal, display
    "Dates are equal" otherwise display "Dates are not equal".
*/

typedef struct {
    int day, month, year;
} Date;


int main()
{
    Date dates[2];

    for (int i = 0; i < 2; i++)
    {
        printf("\nIntrodu datele calendaristice pentru data %d:\n", i + 1);
        printf("\nIntrodu ziua: ");
        scanf("%d", &dates[i].day);
        printf("\nIntrodu luna: ");
        scanf("%d", &dates[i].month);
        printf("\nIntrodu anul: ");
        scanf("%d", &dates[i].year);
    }


    if (dates[0].day == dates[1].day && dates[0].month == dates[1].month && dates[0].year == dates[1].year)
    {
        printf("\nCele 2 date introduse sunt egale\n");
    }
    else
    {
        printf("\nCele 2 date introduse nu sunt egale\n");
    }

    return 0;
}
