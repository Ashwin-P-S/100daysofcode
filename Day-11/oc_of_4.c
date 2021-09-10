#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
    printf("Enter No of TestCase: ");
	scanf("%d", &t);
	while(t--) 
	{
	    int n, count = 0, digit;
        printf("\n\nEnter the Integer: ");
	    scanf("%d", &n);
        int temp = n;
	    while(n > 0) {
	        digit = n % 10;
	        if(digit == 4)
	            count++;
	        n /= 10;
	    }
	    printf("\nThe Occurrences of 4 in %d is: %d", temp, count);
	}
	return 0;
}

