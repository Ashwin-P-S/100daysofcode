#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Linked List
struct node
{
    int data;
    struct node* link;
};

// Definition
typedef struct node* stack;

// Declaration
void push(stack*);
void pop(stack*);
void top(stack);
void displayStack(stack);

int main(void)
{
    int choice = 0, data;
    stack head = NULL;
    while (choice != 5)
    {
        system("cls");
        printf("\n\n\t Stack ADT");
        printf("\n\n 1) Push");
        printf("\n 2) Pop");
        printf("\n 3) Top");
        printf("\n 4) Display Stack");
        printf("\n 5) Exit");
        printf("\n\n Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: push(&head); break;
        case 2: pop(&head); break;
        case 3: top(head); break;
        case 4: displayStack(head); break;
        case 5: exit(0);
        default: printf("\n\n Invalid Choice... Try Again ");
        }
        getch();
    }   
}

void push(stack* head)
{
    int data;
    stack newNode = (stack) malloc(sizeof(struct node));

    printf("\n Enter the Data: ");
    scanf("%d", &data);

    newNode->data = data;
    newNode->link = *head;
    *head = newNode;

    printf("\n %d is Pushed ", data);
}

void pop(stack* head)
{
    if( *head == NULL ) { printf("\n Stack UnderFlow ! "); return; }

    stack pop = *head;
    int data = pop->data;

    printf("\n The Popped Element is: %d ", data);

    *head = pop->link;
}

void top(stack head)
{
    if( head == NULL ) { printf("\n Stack is Empty ! "); return; }

    printf("\n The Top Data is: %d ", head->data);
}

void displayStack(stack head)
{
    if( head == NULL ) { printf("\n Stack is Empty ! "); return; }

    printf("\n The Stack is:\n\n");
    while (head != NULL)
    {
        printf("\t %d\n", head->data);
        head = head->link;
    }
}
