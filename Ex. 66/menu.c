void printMenu()
{
    system("cls");
    printf("\n\xB2 \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"
           "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \xB2\n|");
    printf("\t\t\t\t\t\t\t|\n");
    printf("|\t\t 1. Citeste numarul de grade in C sau F |\n");
    printf("|\t\t 2. Converteste - Celsius in Fahrenheit\t|\n");
    printf("|\t\t 3. Converteste - Fahrenheit in Celsius\t|\n");
    printf("|\t\t 4. Iesiti din program \t\t\t|\n");
    printf("\xB2_______________________________________________________\xB2\n\n");

}

void selectMenu()
{
    systemColor();
    float grade;
    int choice;

    do
    {
        system("cls");
        printMenu();
        printf("\t* Introduceti optiunea dumneavoastra: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            citireGrade(&grade);
            printf("\n\n Press any key to continue!\n\n");
            getch();
            break;
        case 2:
            conversieDinCelsius(&grade);
            printf("\n\n Press any key to continue!\n\n");
            getch();
            break;
        case 3:
            conversieDinFahrenheit(&grade);
            printf("\n\n Press any key to continue!\n\n");
            getch();
            break;
        case 4:
            printf("\n * Ati ales sa parasiti programul. La revedere!\n");
            exit(1);
        default:
            printf("\n\t\t ### WARNING! ###\n\n * Valoarea nu este valabila! Incercati din nou.\n");
            printf("\n\n Press any key to continue!\n\n");
            getch();
        }

    }while (choice != 4);
}
