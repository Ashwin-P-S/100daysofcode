#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void fahrenheit(float);
void celcius(float);
void kelvin(float);

void main() {

    int choice;
    float temperature;
    do {

        system("CLS");
        printf("\t\t_____________________________");
        printf("\n\n\t\t    Temperature Conversion\n");
        printf("\t\t_____________________________\n\n");
        printf("\n\t\t  1 - Celcius");
        printf("\n\t\t  2 - Fahrenheit");
        printf("\n\t\t  3 - Kelvin");
        printf("\n\t\t  4 - Exit");
        printf("\n\t\t_____________________________");
        printf("\n\n What do you want to Convert to ?  : ");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            printf("\n Enter the Temperature in Celcius: ");
            scanf("%f", &temperature);
            celcius(temperature);
            break;
        case 2:
            printf("\n Enter the Temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            fahrenheit(temperature);
            break;
        case 3:
            printf("\n Enter the Temperature in Kelvin: ");
            scanf("%f", &temperature);
            kelvin(temperature);
            break;
        case 4:
            system("CLS");
            break;
        default:
            printf("\n Invalid Choice! Try Again :(");
            getch();
            break;
        }

    }while(choice != 4);

}

void celcius(float temperature) {

    float fahrenheit, kelvin;

    fahrenheit = 1.8 * (temperature) + 32;
    kelvin = temperature + 273.15;

    printf("\n\n Fahrenheit: %.2f", fahrenheit);
    printf("\n\n Kelvin: %.2f", kelvin);
    getch();
}

void fahrenheit(float temperature) {

    float celcius, kelvin;

    celcius = (5 * (temperature - 32)) / 9;
    kelvin = celcius + 273.15;

    printf("\n\n Celcius: %.2f", celcius);
    printf("\n\n Kelvin: %.2f", kelvin);
    getch();
}

void kelvin(float temperature) {

    float fahrenheit, celcius;

    celcius = temperature - 273.15;
    fahrenheit = (celcius) * (1.8) + 32;

    printf("\n\n Celcius: %.2f", celcius);
    printf("\n\n Fahrenheit: %.2f", fahrenheit);
    getch();
}