#include <stdio.h>
#include <stdlib.h>

/**
    Write a structure to store the name, account number and
    balance of customers (more than 10) and store their
    information.
1 - Write a function to print the names of all the customers
    having balance less than $200.
2 - Write a function to add $100 in the balance of all the
    customers having more than $1000 in their balance and then
    print the incremented value of their balance.
*/

typedef struct {
    char name[30], account_number[17];
    int balance;
} customer;

void afisareNume(customer customers[], int n);
void add(customer customers[], int n);
void printMenu();
void selectMenu(customer customers[], int n);

int main()
{
    customer customers[20];
    int n;
    printf("Introdu numarul de clienti: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nIntrodu datele clientului %d:\n", i + 1);
        printf("\nIntrodu numele: ");
        fflush(stdin);
        gets(customers[i].name);
        printf("\nIntrodu numarul de cont: ");
        fflush(stdin);
        gets(customers[i].account_number);
        printf("\nIntrodu bilantul clientului: ");
        scanf("%d", &customers[i].balance);
    }

    selectMenu(customers, n);

    return 0;
}

void afisareNume(customer customers[], int n)
{
    printf("Clientii cu un bilant mai mic de 200$ sunt:\n");
    for (int i = 0; i < n; i++)
    {
        if (customers[i].balance < 200)
        {
            printf("%s\n", customers[i].name);
        }
    }
}

void add(customer customers[], int n)
{
    printf("\nStatusul actualizat cu +100$ al clientilor cu peste 1000$:\n");
    for(int i = 0; i < n; i++)
    {
        if (customers[i].balance >= 1000)
        {
            printf("\nBilantul actual al clientului %s este: %d\n", customers[i].name, customers[i].balance);
            customers[i].balance += 100;
            printf("\nBilantul actualizat al clientului %s este: %d\n", customers[i].name, customers[i].balance);
        }
    }
}

void printMenu()
{
    printf("\n\t1 -> Afisati numele clientilor care au mai putin de 200$ in cont\n"
           "\t2 -> Adaugati 100$ clientilor care au peste 1000$ in cont si afisatii\n"
           "\t3 -> Iesiti din program\n\n");
}

void selectMenu(customer customers[], int n)
{
    do
    {
        system("cls");
        printMenu();
        switch(getch())
        {
        case '1':
            afisareNume(customers, n);
            printf("\nPress any key to continue!\n");
            getch();
            break;
        case '2':
            add(customers, n);
            printf("\nPress any key to continue!\n\n");
            getch();
            break;
        case '3':
            printf("\nAti ales sa parasiti programul! :D\n\n");
            exit(EXIT_SUCCESS);
        }
    }while(1);
}
