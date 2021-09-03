import time
import os
from datetime import date

def check_train_availability():
    os.system('cls')
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

def ticket_booking():
    
    fc_count = 0
    file = open("./Day-3, Day-4/reserved_tickets.txt", "a")

    while True:    
        os.system('cls')
        check_train_availability()
        train_id = int(input("\n Select Your Train Id: "))
        
        if(train_id == 1):
            train_no = 10001
            train_time = "09:00"
            train_name ="Vaigai SF Express"
            origin = "Madurai Junction"
            destination = "Chennai Egmore"
        elif(train_id):
            train_no = 10002
            train_time = "13:00"
            train_name ="Coimbatore Express"
            origin = "Chennai Central"
            destination = "Coimbatore Junction"
        elif(train_id):
            tr.train_no = 10003 
            tr.train_time = "08:00" 
            tr.train_name ="Coimbatore Express" 
            tr.origin = "Rameswaran Junction" 
            tr.destination = "Coimbatore Junction"        
        elif(train_id):
            tr.train_no = 10003 
            tr.train_time = "08:00" 
            tr.train_name ="Coimbatore Express" 
            tr.origin = "Rameswaran Junction" 
            tr.destination = "Coimbatore Junction" 
        elif(train_id):
            tr.train_no = 10005 
            tr.train_time = "18:00" 
            tr.train_name ="Vaigai SF Express" 
            tr.origin = "Chennai Egmore" 
            tr.destination = "Madurai Junction" 
        elif(train_id):
            tr.train_no = 10006 
            tr.train_time = "09:30" 
            tr.train_name ="Pune Indore Express" 
            tr.origin = "Pune Junction" 
            tr.destination = "Indore Junction Bg" 
        elif(train_id):
            tr.train_no = 10007 
            tr.train_time = "13:00" 
            tr.train_name ="Bangalore Express" 
            tr.origin = "Chennai Central" 
            tr.destination = "Bangalore Junction" 
        elif(train_id):
            tr.train_no = 10008
            tr.train_time = "16:00"
            tr.train_name ="Rajdhani Express"
            tr.origin = "Bangalore Junction"
            tr.destination = "New Delhi Junction"
        if(train_id not in range(1,9)):
            print("\n Please Choose the Valid Train Id! - Wait For a Second...")
            time.sleep(4)
        else:
            break

    date_of_jrny = input(" Enter Your Date of Journey [DD/MM/YYYY]: ")

    while True:
        os.system('cls')
        print("\n Classes Available:")
        print("\n\t1)Seater A/C")
        print("\n\t2)Seater Non A/C")
        print("\n\t3)Sleeper A/C")
        print("\n\t4)Sleeper Non A/C")
        train_class_type = int(input("\n\nPlease Select Your Class [1/2/3/4]: "))
        if(train_class_type not in [1,2,3,4]):
            print("\n Invalid Choice \n Please Choose [1/2/3/4] - Wait for a Second")
            time.sleep(3.5)
        else: break
    
    if(train_class_type == 1):
        train_class = "Seater A/C"
        no_of_passengers = int(input("\nEnter Number of Seats : ")) 
    elif(train_class_type == 2):
        train_class = "Seater Non A/C"
        no_of_passengers = int(input("\nEnter Number of Seats : "))
    elif(train_class_type == 3):
        train_class = "Sleeper A/C"
        no_of_passengers = int(input("\nEnter Number of Berths : "))
    elif(train_class_type == 4):
        train_class = "Sleeper Non A/C"
        no_of_passengers = int(input("\nEnter Number of Berths : "))
        
    for i in range(1, no_of_passengers + 1):
        os.system('cls')
        
        print("\n\nEnter the Details of Passenger {} :".format(i))
        f_name = input("\n First Name\t: ")
        l_name = input("\n Last Name\t: ")
        gender = input("\n Gender [M/F]\t: ")
        age = int(input("\n Age\t\t: "))

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
        else:
            fc_type = 0
            print("\n Fee Concession Type: None")
        wait = input("\n Press Enter to Continue...")
        if(fc_type == 1):fc_count += 1

        charges = (1000 * (no_of_passengers - fc_count) ) + (fc_count * 500) 
        details = [
            train_no,
            f_name,
            l_name,
            str(age),
            gender,
            date_of_jrny]
        for j in details:
            file.write(str(j))
            file.write("\t")
        file.write("\n")
        
        wait = ("\n Press Enter to Continue...")
    
    file.close()
   
    os.system('cls')
    print("\nCharges Per Ticket: 1000\t\tFee Concession[If Applicable]: 500")
    print("Train No: {}\t\t\t\tTrain Name: {}".format(train_no, train_name))
    print("Origin: {}\t\tDestination: {}".format(origin, destination))
    print("Total Charges: {}\t\t\tDate of Journey: {}".format(charges, date_of_jrny))
    print("Total No of Passengers: {}".format(no_of_passengers))
    print()
    print("\tYour Tickets are Confirmed! Please View Chart to Verify....")
    print("\t\t Thank You !  :)")
    wait = input("\n\nPress Enter to Continue...")

def ticket_cancellation():

    count = 0
    file = open("./Day-3, Day-4/reserved_tickets.txt", "r")
    for i in file:
        if(i != "\n"):
            count += 1
    file.close()
    file = open("./Day-3, Day-4/reserved_tickets.txt", "r")
    file_temp = open("./Day-3, Day-4/reserved_tickets_temp.txt", "a")
    

    os.system('cls')
    view_chart()
    cancel_fname, cancel_lname  = input("\n\tEnter the Name to Cancel: ").split()
    flag = 0
    for i in range(1, count + 1):
        train_no, f_name, l_name, age, gender, date_of_jrny = file.readline().split()
        details = [train_no, f_name, l_name, age, gender, date_of_jrny]
        if cancel_fname == f_name and cancel_lname == l_name:
            flag = 1
        else:
            for i in details:
                file_temp.write(i)
                file_temp.write("\t")
            file_temp.write("\n")
    file.close()
    file_temp.close()
    os.remove("./Day-3, Day-4/reserved_tickets.txt")
    os.rename("./Day-3, Day-4/reserved_tickets_temp.txt", "./Day-3, Day-4/reserved_tickets.txt")
    if(flag == 0):
        print("\n No Tickets Named : ", cancel_fname, cancel_lname)
    else:
        os.system('cls')
        view_chart()
        print("\n\n The Tickets Named {} {} was Cancelled!".format(cancel_fname, cancel_lname))
    wait = input("\n\n Press Enter to Continue...")

def view_chart():

    os.system('cls')
    file = open("./Day-3, Day-4/reserved_tickets.txt","r")
    word = file.readlines()
    print("\t___________________________________________________________________________")
    print("\t    Train No\tName\t\tAge\tGender\tDate Of Journey")
    print("\t___________________________________________________________________________")
    if(os.stat("./Day-3, Day-4/reserved_tickets.txt").st_size  == 0):
        print("\n\t No Tickets were Booked or Reserved!")
    else:
        for line in word:
            word = line.split()
            print("\t   {}\t{} {}\t{}\t{}\t{}".format(word[0], word[1], word[2], word[3], word[4], word[5]))
    print("\t___________________________________________________________________________")
    file.close()
    

def show_welcome_screen():
    os.system('cls')
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
    wait = input("\n\n Press Enter to GO...")

def show_menu():
    while(True):
        os.system('cls')
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
        if(user_choice == 1):
            check_train_availability()
            wait = input("\n Press Enter to Continue...")
        elif(user_choice == 2):
            ticket_booking()
        elif(user_choice == 3):
            ticket_cancellation()
        elif(user_choice == 4):
            view_chart()
            wait = input("\n Press Enter to Continue...")
        elif(user_choice == 5):
            break
            exit(0)
        else:
            print("\n Invalid Choice!\n Please Choose [1/2/3/4/5] - Wait for a Second...")
            time.sleep(3)

with open("./Day-3, Day-4/reserved_tickets.txt", "a") as file:
    pass
    

show_welcome_screen()
show_menu()
