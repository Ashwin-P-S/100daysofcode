n = int(input(" Enter a Number: "))
if n >= 1 and n <= 9:
    print(" The Sum of First and Last Digit is: ", n+n)
else:
    sum = n % 10
    while n > 0:
        if n >= 1 and n <= 9:
           sum += n
        n //= 10
    print(" The Sum of First and Last Digit is: ", sum)