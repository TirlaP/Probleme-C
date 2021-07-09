#include <stdio.h>
#include <stdlib.h>

/**
    Write a structure to store the roll no., name, age (between 11
    to 14) and address of students (more than 10). Store the
    information of the students.

1 - Write a function to print the names of all the students
    having age 14.
2 - Write another function to print the names of all the students
    having even roll no.
3 - Write another function to display the details of the student
    whose roll no is given (i.e. roll no. entered by the user).
*/

typedef struct
{
    int roll_no, age;
    char name[30], address[256];
} student;

void printAge14(student students[], int n);
void printEven(student students[], int n);
void detail(int roll, student students[], int n);
void printMenu();

int main()
{
    student students[20];
    int n, roll;
    printf("Introdu numarul de studenti: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\n\nIntrodu numarul studentului %d: ", i + 1);
        scanf("%d", &students[i].roll_no);
        printf("\nIntrodu numele studentului %d: ", i + 1);
        fflush(stdin);
        gets(students[i].name);
        printf("\nIntrodu adresa studentului %d: ", i + 1);
        fflush(stdin);
        gets(students[i].address);
        printf("\nIntrodu varsta studentului %d: ", i + 1);
        scanf("%d", &students[i].age);
    }

    do
    {
        system("cls");
        printMenu();
        switch(getch())
        {
        case '1':
            printAge14(students, n);
            printf("Press any key to continue!");
            getch();
            break;
        case '2':
            printEven(students, n);
            printf("Press any key to continue!");
            getch();
            break;
        case '3':
            printf("Introdu numarul studentului cautat: ");
            scanf("%d", &roll);
            detail(roll, students, n);
            printf("Press any key to continue!");
            getch();
            break;
        case '4':
            printf("Ati ales sa parasiti programul! :D");
            exit(EXIT_SUCCESS);
        }
    }while(1);

    return 0;
}

void printAge14(student students[], int n)
{
    printf("\nStudentii care au 14 ani sunt:\n");
    for(int i = 0; i < n; i++)
    {
        if (students[i].age == 14)
            printf("%s\n", students[i].name);
    }
}

void printEven(student students[], int n)
{
    printf("\nStudentii care au numarul par sunt:\n");
    for(int i = 0; i < n; i++)
    {
        if (students[i].roll_no % 2 == 0)
            printf("%s\n", students[i].name);
    }
}

void detail(int roll, student students[], int n)
{
    printf("\nDatele studentului cautat sunt:\n");
    for (int i = 0; i < n; i++)
    {
        if (students[i].roll_no == roll)
        {
            printf("Numele: %s\n"
                   "Adresa: %s\n"
                   "Varsta: %d\n",
                   students[i].name, students[i].address, students[i].age);
        }
    }

}

void printMenu()
{
    printf("1 -> Afisati studentii care au 14 ani\n"
           "2 -> Afisati studentii care au numarul par\n"
           "3 -> Afisati detaliile unui student cautat\n"
           "4 -> Iesiti din program\n");
}
