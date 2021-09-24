import java.util.Scanner;
import java.io.IOException;

class stackArray {

    static int Max = 10, Top = -1;
    static int stack[] = new int[Max];

    static Scanner scan = new Scanner(System.in);

    // Push Operation
    static void push()
    {
        if ( Top == Max - 1 )
        { System.out.printf("\n Stack OverFlow!\n\n"); return; }
        System.out.printf("\n Enter the Element: ");
        int data = scan.nextInt();
        stack[++Top] = data;
        System.out.printf("\n %d is Pushed !\n\n", data);
    }

    // Top Operation
    static void top()
    {
        if ( Top == -1 )
        { System.out.printf("\n Stack is Empty!\n\n"); return; }
        System.out.printf("\n Top Element is: %d\n\n", stack[Top]);
    }

    // Pop Operation
    static void pop()
    {
        if ( Top == -1 )
        { System.out.printf("\n Stack is Empty!\n\n"); return; }
        System.out.printf("\n Poped Element is: %d\n\n", stack[Top--]);
    }

    // Let's Print the Stack
    static void printStack()
    {
        if ( Top == -1 )
        { System.out.printf("\n Stack is Empty!\n\n"); return; }

        System.out.printf("\n Stack is:\n\n");
        for(int i=Top;i>=0;i--)
        {System.out.printf("\t %d \n", stack[i]);}
    }

    // Main Function
    public static void main(String args[]) throws IOException, InterruptedException {

        int choice = 0;
        while( choice != 5 )
        {
            // Clears Screen
            System.out.println("\033[H\033[2J");
            System.out.flush();

            System.out.println("\n\t Stack Operations");
            System.out.println("\n 1) Push");
            System.out.println(" 2) Top");
            System.out.println(" 3) Pop");
            System.out.println(" 4) Print Stack");
            System.out.println(" 5) Exit");
            System.out.print("\n Enter Your Choice: ");
            choice = scan.nextInt();
            switch (choice)
            {
            case 1: push(); break;
            case 2: top(); break;
            case 3: pop(); break;
            case 4: printStack(); break;
            case 5: System.exit(0);
            default: System.out.println("\n Invalid Choice... Try Again\n"); break;
            }
            new ProcessBuilder("cmd", "/c", "pause").inheritIO().start().waitFor();
        }

    }

}
