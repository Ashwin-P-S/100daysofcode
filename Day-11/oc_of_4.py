t = int(input("\n Enter No of TestCases: "))
for _ in range(t):
    print("\n\n TestCase {}:".format(_+1))
    n = int(input("\n Enter an Integer: "))
    temp = n
    count = 0
    while n > 0:
        digit = n % 10
        if digit == 4:
            count += 1
        n //= 10
    print(" Occurrences of 4 in {} is: {}".format(temp, count))