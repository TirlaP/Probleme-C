#include <stdio.h>
#include <stdlib.h>

/**
    Write a program to store and print the roll no., name, age,
    address and marks of N students using structure.
    (N is a number entered from the keyboard)
*/

struct student {
    int roll_no;
    char name[30];
    int age;
    char address[256];
    int marks;
};

int main()
{
    int n;
    printf("Introdu numarul de studenti: ");
    scanf("%d", &n);

    struct student stud[n];

    for (int i = 0; i < n; i++)
    {
        stud[i].roll_no = i + 1;
        printf("\nIntrodu numele studentului %d: ", stud[i].roll_no);
        gets(stud[i].name);
        gets(stud[i].name);
        printf("Introdu varsta studentului %d: ", stud[i].roll_no);
        scanf("%d", &stud[i].age);
        printf("Introdu adresa studentului %d: ", stud[i].roll_no);
        gets(stud[i].address);
        gets(stud[i].address);
        printf("Introdu nota studentului %d: ", stud[i].roll_no);
        scanf("%d", &stud[i].marks);
    }

    printf("\nDatele studentilor sunt:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d. %s - %d ani - adresa %s - nota %d\n",
               stud[i].roll_no, stud[i].name, stud[i].age,
               stud[i].address, stud[i].marks);
    }

    return 0;
}
