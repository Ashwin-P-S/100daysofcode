import java.io.*;
import java.util.*;

class noGuessGame {

    public static void main(String[] args) {

        //Generating Random Numbers
        int randomNumber = 1 + (int)(Math.random() * 50);
        int guessNumber, count;
        Scanner scan = new Scanner(System.in);

        //Welcome Screen
        System.out.println();
        System.out.println("\n\t\tNumber Guessing Game!");
        System.out.println();
        System.out.println("\nNOTE: You have only 20 Attempts to Guess. After 20 Attempts, the Game will be Ended!");
        System.out.println();
        System.out.println("\n\tGuess a Number between 1 and 50");
        System.out.print("\nEnter the guessed number: ");
        guessNumber = scan.nextInt();

        //Looping through the Guessed Number
        for(count = 1; randomNumber != guessNumber; count++) {
            if (randomNumber < guessNumber  && guessNumber <= 50) {
                System.out.println("NO! The Number is Less than " + guessNumber);
            } else if (randomNumber > guessNumber && guessNumber <= 50) {
                System.out.println("NO! The Number is Greater than " + guessNumber);
            } else {
                System.out.println("Sorry, Please Guess a Number Between 1 and 50");
            }
            //20 Attempts - Fail!
            if (count == 20) {
                System.out.println("Sorry, You Lost 20 Attempts! Try Again :(");
                break;
            }
            System.out.println();
            System.out.print("Enter the guessed number: ");
            guessNumber = scan.nextInt();
        }

        //If Won the Game:
        if (randomNumber == guessNumber){
                System.out.println();
                System.out.println("Great! The Number is " + randomNumber);
                System.out.println("You Won the Game in " + count + " attempt, Thank You! :)");
                System.out.println();
        }
    }

}