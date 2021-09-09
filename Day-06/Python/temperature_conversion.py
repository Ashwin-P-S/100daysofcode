import os

def Celcius(celcius):

    fahrenheit = float((9 / 5) * celcius + 32)
    kelvin = float(celcius + 273.15)

    print("\n\n Fahrenheit: {:.2f}".format(fahrenheit))
    print("\n Kelvin: {:.2f}".format(kelvin))

    getch = input("\nPress Enter to Continue... ")

    return 0

def Fahrenheit(fahrenheit):

    celcius = float(5 * (fahrenheit - 32) / 9)
    kelvin = float(celcius + 273.15)

    print("\n\n Celcius: {:.2f}".format(celcius))
    print("\n Kelvin: {:.2f}".format(kelvin))

    getch = input("\n Press Enter to Continue... ")

    return 0

def Kelvin(kelvin):

    celcius = float(kelvin - 273.15)
    fahrenheit = float((9 / 5) * celcius + 32)

    print("\n\n Celcius: {:.2f}".format(celcius))
    print("\n Fahrenheit: {:.2f}".format(fahrenheit))

    getch = input("\nPress Enter to Continue... ")

    return 0

while True:
    os.system("cls")
    print("\n\n\t\t______________________________\n")
    print("\t\t    Temperature Conversion")
    print("\t\t______________________________")
    print()
    print("\t\t  1 - Celcius")
    print("\t\t  2 - Fahrenheit")
    print("\t\t  3 - Kelvin")
    print("\t\t  4 - Exit")
    print("\t\t______________________________\n")
    choice = input("\n\nWhat do you want to Convert ? : ")

    if(choice == '1'): 
        celcius = float(input("\nEnter the Temperature in Celcius: "))
        Celcius(celcius)
    elif(choice == '2'): 
        fahrenheit = float(input("\nEnter the Temperature in Fahrenheit: "))
        Fahrenheit(fahrenheit)
    elif(choice == '3'): 
        kelvin = float(input("\nEnter the Temperature in Kelvin: "))
        Kelvin(kelvin)
    elif(choice == '4'):
        os.system("cls") 
        break
    else:
        getch = input("\n\n Invalid Choice! Try Again :(")
