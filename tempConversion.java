import java.io.*;
import java.util.*;

class tempConversion {

    static float celcius, fahrenheit, kelvin;
    static boolean continueConversion = true;
    static Scanner scan = new Scanner(System.in);

    public static void main(String [] arg) {

        while (continueConversion) {

            System.out.print("\033[H\033[2J");
            System.out.flush();

            System.out.println("\n\t\t____________________________\n");
            System.out.println("\t\t    Temperature Conversion");
            System.out.println("\t\t____________________________\n");
            System.out.println("\t\t  1 - Celcius");
            System.out.println("\t\t  2 - Fahrenheit");
            System.out.println("\t\t  3 - Kelvin");
            System.out.println("\t\t  4 - Exit");
            System.out.println("\t\t____________________________");

            System.out.print("\n What do you want to Convert ? : ");
            int choice = scan.nextInt();

            switch (choice) {

                case 1:
                    System.out.print("\n Enter the Temperature in Celcius: ");
                    celcius = scan.nextFloat();
                    Celcius(celcius);
                    break;
                case 2:
                    System.out.print("\n Enter the Temperature in Fahrenheit: ");
                    fahrenheit = scan.nextFloat();
                    Fahrenheit(fahrenheit);
                    break;
                case 3:
                    System.out.print("\n Enter the Temperature in Kelvin: ");
                    kelvin = scan.nextFloat();
                    Kelvin(kelvin);
                    break;
                case 4:
                    System.out.print("\033[H\033[2J");
                    System.out.flush();
                    continueConversion = false;
                    break;
                default:
                    System.out.println("\n Invalid Choice! Try Again :(");
                    try{System.in.read();}
                        catch (Exception e) {}
            }
        }

    }

    static void Celcius(float celcius) {

        fahrenheit = (1.8f) * celcius + 32.0f;
        kelvin = celcius + 273.15f;

        System.out.printf("\n\n Fahrenheit: %.2f", fahrenheit );
        System.out.printf("\n\n Kelvin: %.2f", kelvin );

        System.out.print("\n\n Press Enter to Continue...");
        try {System.in.read();}
            catch(Exception e) {}
    }

    static void Fahrenheit(float fahrenheit) {

        celcius = 5 * (fahrenheit - 32) / 9;
        kelvin = celcius + 273.15f;

       System.out.printf("\n\n Celcius: %.2f", celcius );
        System.out.printf("\n\n Kelvin: %.2f", kelvin );

        System.out.print("\n\n Press Enter to Continue...");
        try {System.in.read();}
            catch(Exception e) {}
    }

    static void Kelvin(float kelvin) {

        celcius = kelvin - 273.15f;
        fahrenheit = (1.8f) * celcius + 32.0f;

        System.out.printf("\n\n Celcius: %.2f", celcius );
        System.out.printf("\n\n Fahrenheit: %.2f", fahrenheit );

        System.out.print("\n\n Press Enter to Continue...");
        try {System.in.read();}
            catch(Exception e) {}
    }

};