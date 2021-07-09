#include <stdio.h>
#include <stdlib.h>

int get_1st_weekday(int year);

int main() {

    system("Color 3F");
    int year, month, day, startingDay, weekDay = 0;

    printf("\nEnter your desired year: ");
    scanf("%d", &year);

    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        monthDays[1] = 29;

    /// First day of the year
    startingDay = get_1st_weekday(year);

    for (month = 0; month < 12; month++)
    {
        printf("\n\n----------------%s------------------", months[month]);
        printf("\n\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");

        for (weekDay = 0; weekDay < startingDay; ++weekDay)
        {
            printf("     ");
        }

        for (day = 1; day <= monthDays[month]; day++)
        {
            printf("%5d", day);

            if (++weekDay > 6)
            {
                printf("\n");
                weekDay = 0;
            }
            startingDay = weekDay;
        }
    }
    printf("\n\n");

    return 0;
}

int get_1st_weekday(int year)
{
    int day;
    day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400) + 1) % 7;

    return day;
}

