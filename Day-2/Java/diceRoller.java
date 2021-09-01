import java.io.*;
import java.util.*;

class diceRoller {

    static int number;
    static char choice;

    public static void main(String[] args){
    
        Scanner scan = new Scanner(System.in);
        System.out.println();
        System.out.println("\tRolling Dice!");

        do {
            rollDice();
            System.out.println();
            showDice();

            //Getting Choice
            System.out.print("\nRoll Again ? (y/n): ");
            choice = scan.next().charAt(0);
        }while(choice == 'y' || choice == 'Y');
        System.out.println("\n\tThank You for Playing! :)\n");
    }
    
    //Rolling Dice
    static void rollDice () {
        number = 1 + (int)(Math.random() * 6);
    }

    //Display Output
    static void showDice() {
        switch(number) {
            case 1:
                System.out.println("You Got "  + number + "!\t\t");
                System.out.println(" _______ ");
                System.out.println("|       |");
                System.out.println("|   0   |");
                System.out.println("|_______|");
                break;
            case 2:
                System.out.println("You Got "  + number + "!\t\t");
                System.out.println(" _______ ");
                System.out.println("|       |");
                System.out.println("| 0   0 |");
                System.out.println("|_______|");
                break;
            case 3:
                System.out.println("You Got "  + number + "!\t\t");
                System.out.println(" _______ ");
                System.out.println("|   0   |");
                System.out.println("| 0   0 |");
                System.out.println("|_______|");
                break;
            case 4:
                System.out.println("You Got "  + number + "!\t\t");
                System.out.println(" _______ ");
                System.out.println("| 0   0 |");
                System.out.println("|       |");
                System.out.println("|_0___0_|");
                break;
            case 5:
                System.out.println("You Got "  + number + "!\t\t");
                System.out.println(" _______ ");
                System.out.println("| 0   0 |");
                System.out.println("|   0   |");
                System.out.println("|_0___0_|");
                break;
            case 6:
                System.out.println("You Got "  + number + "!\t\t");
                System.out.println(" _______ ");
                System.out.println("| 0   0 |");
                System.out.println("| 0   0 |");
                System.out.println("|_0___0_|");
                break;
        }
    }
}