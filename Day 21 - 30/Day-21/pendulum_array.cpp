#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

void pendulum_array(int [], int);
int main(void)
{
    int size;
    system("cls");
    cout << "\n\n\t\t Simple Pendulum Motion !";
    cout << "\n\n Enter the Size of the Array: ";
    cin >> size;
    int array[size];
    cout << "\n\n Enter the Elements One-by-one:\n\n";
    for(int i = 0; i < size; i++) cin >> array[i];
    pendulum_array(array, size);
}

void pendulum_array(int array[], int size)
{
    int sp[size], i, j, temp = 0, mid = (size-1)/2;

    // Create an Simple Pendulum Array !
    for(i = 0; i < size; i++) sp[i] = 0;

    // Let's Sort the Arrat
    for(i = 0; i < size; i++)
    {
        for(j = i + 1; j < size; j++)
        {
            if(array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    // Sorting as Pendulum Motion
    sp[mid] = array[0];
    j = 1;
    for(i = 1; i <= mid; i++)
    {
        sp[mid + i] = array[j++];
        sp[mid - i] = array[j++];
    }

    // Correction if Size of the Array is Even
    if(size % 2 == 0) sp[mid + i] = array[j];

    cout << "\n\n Pendulum Motion:\n\n";
    for(i = 0; i < size; i++) cout << sp[i] << " ";
    getch();
}