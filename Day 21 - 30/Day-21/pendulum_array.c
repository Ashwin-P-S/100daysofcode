#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void pendulum_array(int[], int);

int main(void)
{
    int size;
    system("cls");

    printf("\n\n\t\t Simple Pendulum Motion !");
    printf("\n\n Enter the Size of the Array: ");
    scanf("%d", &size);

    int array[size], result[size];
    printf("\n Enter Element One-by-one:\n\n");
    for(int i = 0; i < size; i++) scanf("%d", &array[i]);

    pendulum_array(array, size);
}

void pendulum_array(int array[], int size)
{
    int sp[size], temp = 0, i, j;

    // Sorting the Array
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

    // Creating Simple Pendulum Array !
    for(int i = 0; i < size; i++) sp[i] = 0;

    // Middle Term
    int mid = (size - 1)/2;
    sp[mid]  = array[0];
    i = 1;
    j = 1;

    // Sorting as Pendulum Motion
    for(i = 1; i <= mid; i++)
    {
        sp[mid + i] = array[j++];
        sp[mid - i] = array[j++];
    }

    // Correction if Size of the Array is Even
    if(size%2 == 0) sp[mid + i] = array[j];

    printf("\n\n Pendulum Motion: ");
    for(i = 0; i < size; i++) printf("%d ", sp[i]);
    getch();
}