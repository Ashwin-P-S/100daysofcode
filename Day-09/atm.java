import java.util.*;
import java.io.*;

class atm
{
	public static void main (String[] args)
	{
		Scanner scan = new Scanner(System.in);
        System.out.print("Enter Withdraw Amount and Balance: ");
		float withDraw = scan.nextFloat();
		float balance = scan.nextFloat();
		if(withDraw + 0.5f > balance || withDraw % 5 != 0) {
		    System.out.printf("%.2f", balance);
		} else {
		    System.out.printf("%.2f", balance - withDraw - 0.5f);
		}
	}
}
