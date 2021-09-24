#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define Max 10
int Top = -1, stack[Max];

// Methods
int isEmpty();
void push();
void top();
void pop();
void printStack();

// Main Function
int main(void)
{
    int choice = 0;
    while (choice != 5)
    {
        system("cls");
        printf("\n\t Stack Operations");
        printf("\n\n 1) Push");
        printf("\n 2) Top");
        printf("\n 3) Pop");
        printf("\n 4) Print Stack");
        printf("\n 5) Exit");
        printf("\n\n Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: push(); break;
        case 2: top(); break;
        case 3: pop(); break;
        case 4: printStack(); break;
        case 5: exit(0);
        default: printf("\n Invalid Choice... Try Again"); break;
        }
        getch();
    }   
}

// Checking the Status of Stack
int isEmpty()
{
    if ( Top == -1 )
    { printf("\n Stack is Empty!"); return 1; }
    return 0;
}

// Push Operation
void push()
{
    if ( Top == Max )
    { printf("\n Stack OverFlow!"); return; }
    int data;
    printf("\n Enter the Element: ");
    scanf("%d", &data);
    stack[++Top] = data;
    printf("\n %d is Pushed !", data);
}

// Top Operation
void top()
{
    if ( isEmpty() ) return;
    printf("\n Top Element is: %d", stack[Top]);
}

// Pop Operation
void pop()
{
    if ( isEmpty() ) return;
    printf("\n Poped Element is: %d", stack[Top--]);
}

// Let's Print the Stack
void printStack()
{
    if ( isEmpty() ) return;

    printf("\n Stack is:\n\n");
    for(int i=Top;i>=0;i--)
    {printf("\t %d \n", stack[i]);}
}