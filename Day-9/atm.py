withdraw_amt, balance = map(float, input("Enter the Withdraw Amount and Balance: ").split())
if (withdraw_amt + 0.5 > balance) or (withdraw_amt % 5 != 0):
    print("{:.2f}".format(balance))
else:
    print("{:.2f}".format(balance - withdraw_amt - 0.50))