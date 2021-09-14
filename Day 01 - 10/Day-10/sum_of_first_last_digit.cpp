#include <iostream>
using namespace std;

int main() {
	int n;
    cout << " Enter a Number: ";
	cin >> n;
	if(n>=1 && n<=9)
	    cout << " The Sum of First and Last Digit is: " << n+n << endl;
	else {
	    int sum = n % 10;
	    while(n>0){
	        if(n >= 1 && n <= 9)
	            sum += n;
	        n /= 10;
	    }
	    cout << " The Sum of First and Last Digit is: " << sum << endl;
	}
	return 0;
}
