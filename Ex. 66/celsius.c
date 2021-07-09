void citireGrade(float *grade)
{
    printf("\n * Introdu numarul de grade dat spre convertire: ");
    scanf("%f", grade);
}

void conversieDinCelsius(float *grade)
{
    printf("\n * How to convert Celsius to Fahrenheit\n\n"
            "  0 degrees Celsius is equal to 32 degrees Fahrenheit: \n\n\n"
            "  0 %cC = 32 %cF\n\n", 248, 248);

    float rezultat;
    rezultat = *grade * 9 / 5 + 32;
    printf(" * %.2f grade %cC in %cF sunt: %.2f.", *grade, 248, 248, rezultat);

}

void conversieDinFahrenheit(float *grade)
{
    printf("\n * How to convert Fahrenheit to Celsius\n\n"
            "  0 degrees Fahrenheit is equal to -17.77778 degrees Celsius: \n\n\n"
            "  0 %cF = -17.77778 %cC\n\n", 248, 248);

    float rezultat;
    rezultat = (*grade - 32) * 5 / 9;
    printf(" * %.2f grade %cF in %cC sunt: %.2f.", *grade, 248, 248, rezultat);

}
