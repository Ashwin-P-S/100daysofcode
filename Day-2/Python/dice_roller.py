import random
import time

choice = 'y'

#Printing the Output
def show_Dice(random_number):

    def one(random_number):
    
        print("You Got {}!".format(random_number))
        print(" _______ ")
        print("|       |")
        print("|   0   |")
        print("|_______|")
        return 0
    
    def two(random_number):
    
        print("You Got {}!".format(random_number))
        print(" _______ ")
        print("|       |")
        print("| 0   0 |")
        print("|_______|")
        return 0

    def three(random_number):
    
        print("You Got {}!".format(random_number))
        print(" _______ ")
        print("|   0   |")
        print("| 0   0 |")
        print("|_______|")
        return 0
    
    def four(random_number):
    
        print("You Got {}!".format(random_number))
        print(" _______ ")
        print("| 0   0 |")
        print("| 0   0 |")
        print("|_______|")
        return 0

    def five(random_number):
    
        print("You Got {}!".format(random_number))
        print(" _______ ")
        print("| 0   0 |")
        print("|   0   |")
        print("|_0___0_|")
        return 0

    def six(random_number):
    
        print("You Got {}!".format(random_number))
        print(" _______ ")
        print("| 0   0 |")
        print("| 0   0 |")
        print("|_0___0_|")
        return 0

    if(random_number == 1):    one(random_number)
    elif(random_number == 2):  two(random_number)
    elif(random_number == 3):  three(random_number)
    elif(random_number == 4):  four(random_number)
    elif(random_number == 5):  five(random_number)
    else:   six(random_number)

    return 0

#Welcome screen!
print()
print("\tRolling Dice!")
print("\n\t ....")
print()
time.sleep(3)

#Rolling a Dice!
while(choice == 'y' or choice =='Y'):
    random_number = random.randint(1,6)
    show_Dice(random_number)
    choice = input("\nRoll Again ? (y/n) :")
    if(choice == 'y'or choice == 'Y'):
        print("\nRolling...")
        time.sleep(3)
    
print("\n\tThank You for Playing! :)\n")