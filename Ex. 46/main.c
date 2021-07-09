#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    Write a program to store and print the roll no., name , age
    and marks of a student using structures.
*/

struct student {
    int roll_no;
    char name[30];
    int age;
    int marks;
};

int main()
{
    struct student p1;
    printf("Introdu numarul pe care il are studentul: ");
    scanf("%d", &p1.roll_no);
    printf("Introdu numele studentului: ");
    gets(p1.name);
    gets(p1.name);
    printf("Introdu varsta studentului: ");
    scanf("%d", &p1.age);
    printf("Introdu nota studentului: ");
    scanf("%d", &p1.marks);

    printf("Datele studentului sunt:\n%d. %s - %d ani - nota %d.", p1.roll_no,
           p1.name, p1.age, p1.marks);


    return 0;
}
