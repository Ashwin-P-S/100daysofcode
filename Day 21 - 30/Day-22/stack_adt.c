// Stack Implementation of Linked List

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Linked list creation for Stack Operations
struct node
{
    int data;
    struct node* link;
};

// Methods Declaration
typedef struct node* stack;
int top(stack);
int pop(stack*);
void push(stack*, int);
void print_stack(stack);

//Main function
int main(void)
{
    system("cls");
    stack front = NULL; int data, choice = 0;
    while (choice != 5)
    {
        system("cls");
        printf("\n\t Stack Operations\n");
        printf("\n 1) PUSH");
        printf("\n 2) POP");
        printf("\n 3) TOP");
        printf("\n 4) PRINT STACK");
        printf("\n 5) EXIT");
        printf("\n\n Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\n Enter the Element to Push: ");
                scanf("%d", &data);push(&front, data);
                break;

            case 2:
                data = pop(&front);
                if(data == -1){printf("\n Stack is Empty! - UnderFlow"); break;}
                printf("\n The Top Element %d is Popped [ Deleted ]", data);
                break;
            
            case 3:
                data = top(front);
                if(data == -1){printf("\n Stack is Empty!"); break;}
                printf("\n The Top Value is %d", data);
                break;

            case 4: print_stack(front); break;
            case 5: exit(0);
            default: printf("\n\n Invalid Choice!...");
        }
        getch();   
    }
}

// Push New Data
void push(stack* front, int new_data)
{
    stack new_stack = (stack) malloc(sizeof(struct node));
    new_stack->data = new_data;

    // If Stack is Empty
    if(*front == NULL)
    {
        new_stack->link = NULL;
        *front = new_stack;
    }
    else
    {
        new_stack->link = *front;
        *front = new_stack;
    }

    printf("\n %d is Pushed!", new_data);
}

// Pop Operation
int pop(stack* front)
{
    if(*front == NULL) return -1;

    int data = (*front)->data;

    stack pop = *front;
    *front = pop->link;
    free(pop);

    return data;
}

// Top Operation
int top(stack front)
{
    if(front == NULL){return -1;}
    return front->data;
}

// Prints the Stack
void print_stack(stack front)
{
    // If Stack is Empty
    if(front == NULL)
    {
        printf("\n\n Stack is Empty!");
        return;
    }

    stack current = front;
    printf("\n The Stack is:\n\n");

    while(current != NULL)
    {
        printf("\t%d\n", current->data);
        current = current->link;
    }
}