import java.util.*;
class sumOfFirstLastDigit
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scan = new Scanner(System.in);
		int n;
		System.out.print(" Enter a Number: ");
		n = scan.nextInt();
		if (n >= 1 && n <= 9)
		    System.out.println(" The Sum of First and Last Digit is: "+ (n+n));
		else {
		    int sum = n % 10;
		    while(n > 0) {
		        n /= 10;
		        if(n >= 1 && n <= 9)
	            	sum += n;
		    }
		    System.out.println(" The Sum of First and Last Digit is: " + sum);
		}
	}
}
