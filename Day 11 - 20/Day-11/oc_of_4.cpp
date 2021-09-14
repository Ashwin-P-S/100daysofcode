#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, digit, count = 0;
	    cin >> n;
	    while(n > 0) {
	        digit = n % 10;
	        if(digit == 4)
	            count++;
	        n /= 10;
	    }
	    cout << count << endl;
	}
	return 0;
}
