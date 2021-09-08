#include <iostream>
using namespace std;

int main() {
	int withdraw_amt;
	float balance = 0.00;
    cout << "Enter the Withdraw Amount and Balance: ";
	cin >> withdraw_amt >> balance;
	if(withdraw_amt + 0.5 > balance || withdraw_amt % 5 != 0)
	    printf("%.2f", balance);
	else
	    printf("%.2f", balance - withdraw_amt - 0.5);
	return 0;
}
