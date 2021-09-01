#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void showDice(int);

void main() 
{
    int number, choice = 1;
    printf("\n\tRolling Dice...");
    printf("\n\nPress any key to Continue...");
    getch();
    while(choice)
    {   
        //Rolling Dice - Generating Random Numbers
        number = (rand() % 6) + 1;
        showDice(number);

        //Choice
        printf("\n\nRoll Again ? (0/1) : ");
        scanf("%d", &choice);
	}
    
    printf("\n\tThank You for Playing! :)\n");
}

void showDice(int number)
{
    switch (number)
    {
        case 1:
            printf("\nYou Got %d !\n", number);
            printf("\n _______ ");
            printf("\n|       |");
            printf("\n|   0   |");
            printf("\n|_______|");
            break;
        case 2:
            printf("\nYou Got %d !\n", number);
            printf("\n _______ ");
            printf("\n|       |");
            printf("\n| 0   0 |");
            printf("\n|_______|");
            break;
        case 3:
            printf("\nYou Got %d !\n", number);
            printf("\n _______");
            printf("\n|   0   |");
            printf("\n| 0   0 |");
            printf("\n|_______|");
            break;
        case 4:
            printf("\nYou Got %d !\n", number);
            printf("\n _______ ");
            printf("\n| 0   0 |");
            printf("\n|       |");
            printf("\n|_0___0_|");
            break;
        case 5:
            printf("\nYou Got %d !\n", number);
            printf("\n _______ ");
            printf("\n| 0   0 |");
            printf("\n|   0   |");
            printf("\n|_0___0_|");
            break;
        case 6:
            printf("\nYou Got %d !\n", number);
            printf("\n _______ ");
            printf("\n| 0   0 |");
            printf("\n| 0   0 |");
            printf("\n|_0___0_|");
            break;
    }
}
