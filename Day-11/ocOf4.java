import java.util.*;
class ocOf4
{
	public static void main (String[] args)
	{
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int i = 0; i < t; i++) {
		    int n = in.nextInt();
		    int digit, count = 0;
		    while(n > 0) {
		        digit = n % 10;
		        if(digit == 4)
		            count++;
		        n /= 10;
		    }
		    System.out.println(count);
		}
	}
}
