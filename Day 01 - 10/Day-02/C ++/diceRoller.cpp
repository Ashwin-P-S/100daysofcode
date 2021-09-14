#include<iostream>
#include<conio.h>
int rollDice();
void showDice(int);
using namespace std;

int main() 
{
    int number;
    char choice;
    cout<<"\n\tRolling Dice..."<<endl<<"\nPress Any Key to Continue..."<<endl;
    getch();
    do 
    {
        number = rollDice();
        showDice(number);

        cout<<"\n\nRoll Again ? (y/n) : ";
        cin>>choice;
    }while(choice == 'y' || choice == 'Y');
    cout<<"\n\tThank You for Playing! :)";
    return 0;
}

int rollDice()
{
    int number;
    number = (rand() % 6) + 1;
    return number;
}

void showDice(int number)
{
    switch (number)
    {
        case 1:
            cout<<"\nYou Got "<<number<<"!"<<endl;
            cout<<"\n _______ ";
            cout<<"\n|       |";
            cout<<"\n|   0   |";
            cout<<"\n|_______|";
            break;
        case 2:
            cout<<"\nYou Got "<<number<<"!"<<endl;
            cout<<"\n _______ ";
            cout<<"\n|       |";
            cout<<"\n| 0   0 |";
            cout<<"\n|_______|";
            break;
        case 3:
            cout<<"\nYou Got "<<number<<"!"<<endl;
            cout<<"\n _______";
            cout<<"\n|   0   |";
            cout<<"\n| 0   0 |";
            cout<<"\n|_______|";
            break;
        case 4:
            cout<<"\nYou Got "<<number<<"!"<<endl;
            cout<<"\n _______ ";
            cout<<"\n| 0   0 |";
            cout<<"\n|       |";
            cout<<"\n|_0___0_|";
            break;
        case 5:
            cout<<"\nYou Got "<<number<<"!"<<endl;
            cout<<"\n _______ ";
            cout<<"\n| 0   0 |";
            cout<<"\n|   0   |";
            cout<<"\n|_0___0_|";
            break;
        case 6:
            cout<<"\nYou Got "<<number<<"!"<<endl;
            cout<<"\n _______ ";
            cout<<"\n| 0   0 |";
            cout<<"\n| 0   0 |";
            cout<<"\n|_0___0_|";
            break;
    }
}