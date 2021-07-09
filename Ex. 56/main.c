#include <stdio.h>
#include <stdlib.h>

/**
    Write a structure to store the names, salary and hours of work
    per day of 10 employees in a company. Write a program to
    increase the salary depending on the number of hours of work
    per day as follows and then print the name of all the
    employees along with their final salaries.

Hours of work per day	8	10	>=12
Increase in salary	$50	$100	$150

*/

typedef struct {
    char name[30];
    int salary, work_hours;
} employee;

void increaseSalary(employee employees[], int n);
void printEmployees(employee employees[], int n);

int main()
{
    employee employees[20];
    int n;
    printf("Introdu numarul de angajati: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nIntrodu datele angajatului %d:\n", i + 1);
        printf("\nIntrodu numele: ");
        fflush(stdin);
        gets(employees[i].name);
        printf("\nIntrodu salariul: ");
        scanf("%d", &employees[i].salary);
        printf("\nIntrodu numarul orelor de munca zilnice: ");
        scanf("%d", &employees[i].work_hours);
    }

    increaseSalary(employees, n);
    printEmployees(employees, n);

    return 0;
}

void increaseSalary(employee employees[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (employees[i].work_hours >= 8 && employees[i].work_hours < 10)
        {
            employees[i].salary += 50;
        }
        else if (employees[i].work_hours >= 10 && employees[i].work_hours < 12)
        {
            employees[i].salary += 100;
        }
        else if (employees[i].work_hours >= 12)
        {
            employees[i].salary += 150;
        }
    }
}

void printEmployees(employee employees[], int n)
{
    printf("\nDatele angajatilor sunt:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s - salariu final -> %d\n", employees[i].name, employees[i].salary);

    }
    printf("\n");
}
