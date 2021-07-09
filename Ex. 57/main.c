#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    Let us work on the menu of a library. Create a structure
    containing book information like accession number, name of
    author, book title and flag to know whether book is issued
    or not.

Create a menu in which the following can be done.
1 - Display book information
2 - Add a new book
3 - Display all the books in the library of a particular author
4 - Display the number of books of a particular title
5 - Display the total number of books in the library
6 - Issue a book
(If we issue a book, then its number gets decreased by 1 and if
 we add a book, its number gets increased by 1)
*/

typedef struct {
    int accession_number;
    char author[30], title[30];
    int issued;
} book;

void printMenu();
void selectMenu();
void displayBookInfo(book b);
void addBook(book library[], int *n);
void displayAuthorBooks(book library[], int number_of_books, char autor[]);


int main()
{
    book library[300];
    int n = 0;
    selectMenu(library, n);
    return 0;
}

void displayBookInfo(book b)
{
    printf("Numarul de acces - %d\nCarte - %s\nAutor - %s\n",
            b.accession_number, b.title, b.author);
    if (b.issued == 0)
    {
        printf("Issued - No\n");
    }
    else
    {
        printf("Issued - Yes\n");
    }
}

void addBook(book library[], int *n)
{
    (*n)++;
    printf("\nIntrodu numarul de carti: ");
    scanf("%d", &library[*n].accession_number);
    printf("\nIntrodu autorul: ");
    fflush(stdin);
    gets(library[*n].author);
    printf("\nIntrodu cartea: ");
    fflush(stdin);
    gets(library[*n].title);
    library[*n].issued = 0;

}

void displayAuthorBooks(book library[], int number_of_books, char autor[])
{
    int n = number_of_books;
    for (int i = 1; i <= n; i++)
    {
        if (strcmp(library[i].author, autor) == 0)
        {
            displayBookInfo(library[i]);
            printf("\n");
        }
    }
}

void displayNrBooksTitle(book library[], int n, char titlu[])
{
    int total_title = 0;

    for (int i = 1; i <= n; i++)
    {
        if (strcmp(library[i].title, titlu) == 0)
        {
            total_title += library[i].accession_number;
        }
    }
    printf("\nNumarul de carti cu titlul %s din biblioteca este: %d\n",
           titlu, total_title);
}

void displayTotalBooks(book library[], int n)
{
    int total_number = 0;

    for (int i = 1; i <= n; i++)
    {
        total_number += library[i].accession_number;
    }
    printf("Numarul total de carti din biblioteca este: %d\n", total_number);
}

void issueBook(book *library[], int n, char titlu[], char autor[])
{
    int ok = 0;

    for(int i = 1; i <= n; i++)
    {
        if (strcmp((*library[i]).title, titlu) == 0 && strcmp((*library[i]).author, autor) == 0)
        {
            (*library[i]).issued++;
            (*library[i]).accession_number--;
        }
    }
}

void printMenu()
{
    printf("\n\t1 - Display book information"
           "\n\t2 - Add a new book"
           "\n\t3 - Display all the books in the library of a particular author"
           "\n\t4 - Display the number of books of a particular title"
           "\n\t5 - Display the total number of books in the library"
           "\n\t6 - Issue a book"
           "\n\t7 - Close the program\n");
}

void selectMenu(book library[], int n)
{
    char autor[30], titlu[30];
    int nr;
    do
    {
        system("cls");
        printMenu();
        switch(getch())
        {
        case '1':
            if (n == 0)
                printf("\nNu exista nicio carte in biblioteca!\n");
            else
            {
                printf("\nIntrodu numarul cartii cautate: ");
                scanf("%d", &nr);
                displayBookInfo(library[nr]);
            }

            printf("\nPress any key to continue!\n\n");
            getch();
            break;
        case '2':
            addBook(library, &n);
            printf("\nPress any key to continue!\n\n");
            getch();
            break;
        case '3':
            printf("\nIntrodu autorul cautat: ");
            fflush(stdin);
            gets(autor);
            displayAuthorBooks(library, n, autor);
            printf("\nPress any key to continue!\n\n");
            getch();
            break;
        case '4':
            printf("\nIntrodu titlul cartii cautate: ");
            fflush(stdin);
            gets(titlu);
            displayNrBooksTitle(library, n, titlu);
            printf("\nPress any key to continue!\n\n");
            getch();
            break;
        case '5':
            displayTotalBooks(library, n);
            printf("\nPress any key to continue!\n\n");
            getch();
            break;
        case '6':
            printf("\nIntrodu cartea pe care ai dori sa o imprumuti: ");
            fflush(stdin);
            gets(autor);
            printf("\nIntrodu autorul cartii: ");
            fflush(stdin);
            gets(titlu);
            issueBook(library, n, titlu, autor);
            printf("\nPress any key to continue!\n\n");
            getch();
            break;
        case '7':
            printf("\nAti ales sa parasiti programul! :D\n\n");
            exit(EXIT_SUCCESS);
        default:
            printf("\nComanda respectiva nu este disponibila!\n"
                   "Alegeti alta comanda!\n");
            printf("\nPress any key to continue!\n\n");
            getch();
            break;
        }

    }while(1);
}
