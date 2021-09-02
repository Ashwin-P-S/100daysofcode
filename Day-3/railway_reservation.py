import time
import getpass
from os import system
from datetime import date

train = [    
    ["f_name", ""],
    ["l_name", ""],
    ["gender", ""],
    ["date_of_jrny", ""],
    ["train_class", ""],
    ["train_name", ""],
    ["train_time", ""],
    ["origin", ""],
    ["destination", ""],
    ["train_id", 0],
    ["train_no", 0],
    ["no_of_passengers", 0],
    ["age", 0]
]
# f_name, l_name, gender , date_of_jrny, train_class, train_name, train_time, origin, destination = "","","","","","","","",""
# train_id, train_no, no_of_passengers, age  = 0, 0, 0, 0

def check_train_availability():
    system('cls')
    print("\n--------------------------------AVAILABLE TRAINS--------------------------------\n")
    print("________________________________________________________________________________")
    print("\n Tr.Id\tTr.No\tTrain Name\t\tOrigin     Destination\tTime\tCharges\n")
    print("________________________________________________________________________________")
    print("\n  1\t10001\tVaigai SF Express\tMadurai     Chennai\t09:00\t1000")
    print("\n  2\t10002\tCoimbatore Express\tChennai     Coimbatore\t13:00\t1000")
    print("\n  3\t10003\tCoimbatore Express\tRameswaram  Coimbatore\t08:00\t1000")
    print("\n  4\t10004\tCoimbatore Express\tNagercoil   Coimbatore\t23:00\t1000")
    print("\n  5\t10005\tVaigai SF Express\tChennai     Madurai\t18:00\t1000")
    print("\n  6\t10006\tPune Indore Express\tPune        Indore\t09:30\t1000")
    print("\n  7\t10007\tBangalore Express\tChennai     Bangalore\t13:00\t1000")
    print("\n  8\t10008\tRajdhani Express\tBanglore    New Delhi\t16:00\t1000")
    getpass.getpass("\n Press Enter to Continue...")

def ticket_booking():
    
    i, change_tkt, charges, train_class_type, fc_type, fc_count = 0,0,0,0,0,0

    while True:
        system('cls')
        print("\n\tClasses Available:")
        print("\n\t1)Seater A/C")
        print("\n\t2)Seater Non A/C")
        print("\n\t3)Sleeper A/C")
        print("\n\t4)Sleeper Non A/C")
        train["train_class_type"] = int(input("\n\nPlease Select Your Class [1/2/3/4]: "))
        if(train["train_class_type"] not in [1,2,3,4]):
            print("\n Invalid Choice \n Please Choose [1/2/3/4] - Wait for a Second")
            time.sleep(3.5)
        else: break

    if(train_class_type == 1):
        train_class = "Seater A/C"
        train[no_of_passengers] = int(input("\nEnter Number of Seats : ")) 
    elif(train_class_type == 2):
        train_class = "Seater Non A/C"
        train[no_of_passengers] = int(input("\nEnter Number of Seats : "))
    elif(train_class_type == 3):
        train_class = "Sleeper A/C"
        train[no_of_passengers] = int(input("\nEnter Number of Berths : "))
    elif(train_class_type == 4):
        train_class = "Sleeper Non A/C"
        train[no_of_passengers] = int(input("\nEnter Number of Berths : "))
    #print("Train Class : {}\nNo Of Pass: {}".format(train_class_type, no_of_passengers))
    for i in range(0, no_of_passengers + 1):
        system('cls')
        print("\n\nEnter the Details of Passenger {} :".format(i+1))
        f_name = input("\n First Name\t: ")
        l_name = input("\n Last Name\t: ")
        gender = input("\n Gender [M/F]\t: ")
        age = int(input("\n Age  \t:"))
        print()
        print(" Fee Concession :")
        print(" 1) Senior Citizen")
        print(" 2) Age Below 5 Years")
        print(" 3) None\n")
        if(age <= 5):
            fc_type = 1
            print("\n Fee Concession Type: Age Below 5 Years")
        elif(age > 60):
            fc_type = 1
            print("\n Fee Concession Type: Senior Citizen")
        else:print("\n Fee Concession Type: None")
        if(fc_type == 1):fc_count += 1
        getpass.getpass("Press Enter to Continue...")

    getpass.getpass("Press Enter to Continue...")

def ticket_cancellation():
    print("Inside Cancellation")
    getpass.getpass("Press Enter to Continue")

def view_chart():
    print("Inside Chart")
    getpass.getpass("Press Enter to Continue")

def show_welcome_screen():
    system('cls')
    print()
    print("\t\t______________________________________")
    print()
    print("\t\tWelcome to Railway Reservation System")
    print("\t\t______________________________________")
    print()
    print("\t\t     Copyrights Reserved @ ", date.today().year)
    print("\t\t______________________________________")
    print()
    time.sleep(1)
    getpass.getpass("\n\nPress Enter to GO...")

def show_menu():
    while(True):
        system('cls')
        print("\n\t-----------------------------")
        print("\t     RESERVATION SYSTEM")
        print("\t-----------------------------")
        print("\t1) Check Train Availability")
        print("\t-----------------------------")
        print("\t2) Book or Reserve a Ticket")
        print("\t-----------------------------")
        print("\t3) Ticket Cancellation")
        print("\t-----------------------------")
        print("\t4) View Chart [All Tickets]")
        print("\t-----------------------------")
        print("\t5) Exit from System")
        print("\t-----------------------------")
        print()
        user_choice = int(input("\n Enter Your Choice (1/2/3/4/5): "))
        if(user_choice == 1):check_train_availability()
        elif(user_choice == 2):ticket_booking()
        elif(user_choice == 3):ticket_cancellation()
        elif(user_choice == 4):view_chart()
        elif(user_choice == 5):
            break
            exit(0)
        else:
            print("\n Invalid Choice!\n Please Choose [1/2/3/4/5] - Wait for a Second...")
            time.sleep(3)

show_welcome_screen()
show_menu()