void printMenu()
{
    system("cls");
    printf("\n\xB2 \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"
           "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \xB2\n|");
    printf("\t\t\t\t\t\t\t|\n");
    printf("|\t\t 1. Citeste numarul \t\t\t|\n");
    printf("|\t\t 2. Calculeaza suma cifrelor numarului \t|\n");
    printf("|\t\t 3. Iesiti din program \t\t\t|\n");
    printf("\xB2_______________________________________________________\xB2\n\n");

}

void selectMenu()
{
    systemColor();
    int nr, choice;

    do
    {
        system("cls");
        printMenu();
        printf("\t* Introduceti optiunea dumneavoastra: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            citireNumar(&nr);
            printf("\n\n Press any key to continue!\n\n");
            getch();
            break;
        case 2:
            sumCif(&nr);
            printf("\n\n Press any key to continue!\n\n");
            getch();
            break;
        case 3:
            printf("\n * Ati ales sa parasiti programul. La revedere!\n");
            exit(1);
        default:
            printf("\n\t\t ### WARNING! ###\n\n * Valoarea nu este valabila! Incercati din nou.\n");
            printf("\n\n Press any key to continue!\n\n");
            getch();
        }

    }while (choice != 3);
}

