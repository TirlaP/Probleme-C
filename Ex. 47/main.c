#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    Write a program to store the roll no. (starting from 1), name
    and age of N students and then print the details of the student
    with roll no. K. (N, K are numbers entered from the keyboard)
*/

struct student
{
    int roll_no;
    char name[30];
    int age;
};


int main()
{
    int n, k;
    printf("Introdu numarul de studenti: ");
    scanf("%d", &n);

    struct student stud[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nIntrodu numarul pe care il are studentul: ");
        scanf("%d", &stud[i].roll_no);
        printf("Introdu numele studentului: ");
        gets(stud[i].name);
        gets(stud[i].name);
        printf("Introdu varsta studentului: ");
        scanf("%d", &stud[i].age);

    }




    printf("\nIntrodu numarul studentului cautat: ");
    scanf("%d", &k);

    printf("\nDatele studentului cu numarul %d sunt:\n\n", stud[k].roll_no);
    printf("%d. %s - %d ani.\n", stud[k - 1].roll_no,
               stud[k - 1].name, stud[k - 1].age);
    return 0;
}
