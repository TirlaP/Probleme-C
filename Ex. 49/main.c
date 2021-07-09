#include <stdio.h>
#include <stdlib.h>

/**
    Enter the marks of N students in Chemistry, Mathematics and
    Physics (each out of 100) using a structure named Marks having
    elements roll no., name, chem_marks, maths_marks and phy_marks
    and then display the percentage of each student.
*/

struct Marks {
    int roll_no;
    char name[30];
    float chem_marks, math_marks, phy_marks;
};

int main()
{
    int n;
    printf("Introdu numarul de studenti: ");
    scanf("%d", &n);

    struct Marks marks[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nStudentul %d\n", i + 1);
        marks[i].roll_no = i + 1;
        printf("\nIntrodu numele: ");
        scanf("%s", &marks[i].name);
        printf("Introdu nota la Chimie: ");
        scanf("%f", &marks[i].chem_marks);
        printf("Introdu nota la Matematica: ");
        scanf("%f", &marks[i].math_marks);
        printf("Introdu nota la Fizica: ");
        scanf("%f", &marks[i].phy_marks);
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nStudentul %d\n", i + 1);
        float procent = (marks[i].chem_marks + marks[i].math_marks + marks[i].phy_marks) / 3.0;
        printf("Media notelor: %.3f\n", procent);
    }
    return 0;
}
