# Program to Print the Array in to-and-fro motion

def pendulum_array(array, size):
    array.sort()
    simple_pendulum = [0] * size

    # Midlle Term
    mid_term = (size - 1) // 2
    i = 1
    j = 1

    # Sorting as Pendulum Motion
    simple_pendulum[mid_term] = array[0]
    for _ in range(1, mid_term + 1):

        simple_pendulum[mid_term + i] = array[j]
        j += 1

        simple_pendulum[mid_term - i] = array[j]
        j += 1

        i += 1

    # Correction if Size of the Array is Even
    if size % 2 == 0:
        simple_pendulum[mid_term + i] = array[j]

    return simple_pendulum

def main():
    import os
    os.system("cls")

    print("\n\n\t\t Simple Pendulum Motion !")
    size =int(input("\n\n Enter the Size of the Array: "))
    print("\n Enter Element One-by-One: \n")
    
    array = [int(input()) for _ in range(size)]
    result = pendulum_array(array, size)
    print("\n\n Simple Pendulum motion:\n")
    print(*result)

if __name__ == "__main__":
    main()