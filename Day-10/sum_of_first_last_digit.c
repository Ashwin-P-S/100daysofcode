#include <stdio.h>

void main() {
	int n, t;
	printf(" Enter a Number: ");
	scanf("%d", &n);
	if(n>=1 && n<=9)
	    printf("\n The Sum Of First and Last Digit is: %d\n", n+n);
	else
	{
	    int sum = n % 10;
	    while(n>0) {
            if (n >= 1 && n <= 9)
	            sum += n;
	        n /= 10;
	    }
	        printf("\n The Sum Of First and Last Digit is: %d\n", sum);
	}
}

