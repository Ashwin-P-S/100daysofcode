import os

def contact_list():

    os.system('cls')
    print()
    print("\n\t__________________________")
    print("\n\t    List of Contacts")
    print("\t__________________________")
    print()
    
    if(os.stat("./Day-5/Python/phonebook_directory.txt").st_size == 0):
        print("\t No Contacts are there!")
    else:
        no = 1
        file = open("./Day-5/Python/phonebook_directory.txt", "r")
        contacts = file.readlines()
        for line in contacts:
            contact_list = line.split()
            print("\t {}) {} - {}".format(no, contact_list[0], contact_list[1]))
            no += 1
        file.close()
    print("\t__________________________")
        
def add_contact():

    os.system('cls')
    print()
    print("\t\tAdd Contact")
    contact_name = input("\n Enter Name of the Contact: ")
    contact_no = int(input("\n Enter the Mobile Number: "))

    file = open("./Day-5/Python/phonebook_directory.txt", "a")
    for contact_list in [contact_name, str(contact_no)]:
        file.write(contact_list)
        file.write("\t")
    file.write("\n")
    file.close()

def delete_contact():
    
    contact_list()
    if(os.stat("./Day-5/Python/phonebook_directory.txt").st_size == 0):
        pass
    else:
        print()
        name = input("\n Enter the Contact Name to Delete: ")

        flag = 0
        file = open("./Day-5/Python/phonebook_directory.txt", "r")
        file_temp = open("./Day-5/Python/temp_details.txt", "a")
        contacts = file.readlines()
        for line in contacts:
            contact_details = line.split()
            if(name == contact_details[0]):
                flag = 1
            else:
                for details in contact_details:
                    file_temp.write(details)
                    file_temp.write("\t")
                file_temp.write("\n")
                
        file.close()
        file_temp.close()
        os.remove("./Day-5/Python/phonebook_directory.txt")
        os.rename("./Day-5/Python/temp_details.txt", "./Day-5/Python/phonebook_directory.txt")
        
        if(flag == 0):
            print("\n No Contact named {}!".format(name) )
        else:
            contact_list()
            print("\n The Contact named {} was Deleted!".format(name))
        
    get_exit = input("\n Press Enter to Go Menu...")

def modify_contact():

    os.system("cls")
    if(os.stat("./Day-5/Python/phonebook_directory.txt").st_size == 0):
        contact_list()
        pass
    else:
        print()
        print(" What do you want to Modify?")
        print()
        print(" 1 - Name")
        print(" 2 - Mobile Number")
        get_input = input("\n Select Your Option: ")
        os.system("cls")
        contact_list()
        flag = 0
        file = open("./Day-5/Python/phonebook_directory.txt", "r")
        file_temp = open("./Day-5/Python/temp_details.txt", "a")
        contacts = file.readlines()
        if(get_input == '1' ):
            name = input(" Enter the Name to modify: ")
            m_name = input(" Enter the Modified Name: ")
            for line in contacts:
                contact_details = line.split()
                if(name == contact_details[0]):
                    flag = 1
                    file_temp.write(m_name)
                    file_temp.write("\t")
                    file_temp.write(contact_details[1])
                    file_temp.write("\n")
                else:
                    for details in contact_details:
                        file_temp.write(details)
                        file_temp.write("\t")
                    file_temp.write("\n")
            if(flag == 0):
                print("\n\n No Contact named {}!".format(name))
            else:
                print("\n\n The Contact named {} is modified to {}".format(name, m_name))
                print(" Please Open Contact List to Verify!")
        elif(get_input == '2'):
            no = int(input(" Enter the Number to Modify: "))
            m_no = int(input(" Enter the Modified Number: "))
            for line in contacts:
                contact_details = line.split()
                if(str(no) == contact_details[1]):
                    flag = 1
                    file_temp.write(contact_details[0])
                    file_temp.write("\t")
                    file_temp.write(str(m_no))
                    file_temp.write("\n")
                else:
                    for details in contact_details:
                        file_temp.write(details)
                        file_temp.write("\t")
                    file_temp.write("\n")
            if(flag == 0):
                print("\n\n No Contacts with Number {}".format(no))
            else:
                print("\n\n The Contact with Number {} is modified to {}".format(no, m_no))
                print(" Please Open Contact List to Verify!")
                
        file.close()
        file_temp.close()
        os.remove("./Day-5/Python/phonebook_directory.txt")
        os.rename("./Day-5/Python/temp_details.txt", "./Day-5/Python/phonebook_directory.txt")
        
    get_exit = input("\n Press Enter to Go Menu...")


def show_menu():

    os.system('cls')
    print()
    print("\tWelcome to Telephone Directory!")
    print()
    get_input = input("\n\n Press Enter to Continue...")
    
    while True:
        os.system("cls")
        print("\t__________________________")
        print("\n\t    Directory - Menu")
        print("\t__________________________")
        print()
        print("\t1 - Add Contact")
        print("\t2 - Delete Contact ")
        print("\t3 - Modify Contact")
        print("\t4 - Contact List")
        print("\t5 - Exit from Menu")
        print()
        print("\t__________________________")
        print()
    
        option = input(" Enter Your Option: ")
        if(option == '1'):  
            add_contact()
            contact_list()
            print()
            print(" Contact Added Successfully!")
            get_exit = input("\n Press Enter to Go Menu...")
        elif(option == '2'): delete_contact()
        elif(option == '3'): modify_contact()            
        elif(option == '4'):     
            contact_list()
            get_exit = input("\n Press Enter to Go Menu...")  
        elif(option == '5'):       
            break
            exit(0)           
        elif(option not in ['1','2','3','4','5']):
            print("\n Invalid Option! :(")
            try_again = ("Press Enter to Try Again...")           
        else:
            break

#Execution Starts Here
with open("./Day-5/Python/phonebook_directory.txt", "a") as file:
    pass
show_menu()
