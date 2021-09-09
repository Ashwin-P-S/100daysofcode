#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void fahrenheit(float);
void celcius(float);
void kelvin(float);

int main() {

    int choice;
    float temperature;
    do {

        system("cls");
        cout<<"\t\t_____________________________";
        cout<<"\n\n\t\t    Temperature Conversion\n";
        cout<<"\t\t_____________________________\n\n";
        cout<<"\n\t\t  1 - Celcius";
        cout<<"\n\t\t  2 - Fahrenheit";
        cout<<"\n\t\t  3 - Kelvin";
        cout<<"\n\t\t  4 - Exit";
        cout<<"\n\t\t_____________________________";
        cout<<"\n\n What do you want to Convert to ?  : ";
        cin >> choice;
        
        switch (choice)
        {
        case 1:
            cout<<"\n Enter the Temperature in Celcius: ";
            cin >> temperature;
            celcius(temperature);
            break;
        case 2:
            cout<<"\n Enter the Temperature in Fahrenheit: ";
            cin >> temperature;
            fahrenheit(temperature);
            break;
        case 3:
            cout<<"\n Enter the Temperature in Kelvin: ";
            cin >> temperature;
            kelvin(temperature);
            break;
        case 4:
            system("cls");
            break;
        default:
            cout<<"\n Invalid Choice! Try Again :(";
            getch();
            break;
        }

    }while(choice != 4);

    return 0;
}

void celcius(float temperature) {

    float fahrenheit, kelvin;

    fahrenheit = 1.8 * (temperature) + 32;
    kelvin = temperature + 273.15;

    cout << "\n\n Fahrenheit: " << fahrenheit;
    cout << "\n\n Kelvin: " << kelvin;
    getch();
}

void fahrenheit(float temperature) {

    float celcius, kelvin;

    celcius = (5 * (temperature - 32)) / 9;
    kelvin = celcius + 273.15;

    cout << "\n\n Celcius: " << celcius;
    cout << "\n\n Kelvin: " << kelvin;
    getch();
}

void kelvin(float temperature) {

    float fahrenheit, celcius;

    celcius = temperature - 273.15;
    fahrenheit = (celcius) * (1.8) + 32;

    cout << "\n\n Celcius: " << celcius;
    cout << "\n\n Fahrenheit: " << fahrenheit;
    getch();
}