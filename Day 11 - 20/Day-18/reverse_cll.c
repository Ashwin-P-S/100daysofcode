// Required Header Files
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Creating Linked List
struct node
{
    int data;
    struct node* link;
};

// Defining List
typedef struct node* list;

// Declaring Methods
void append(list*, int);
void reverse_list(list*);
void print_list(list);

// Main Method
int main(void)
{
    list head = (list) malloc(sizeof(struct node));
    head = NULL;

    // Let's Append Some Elements [10 to 100]
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);
    append(&head, 60);
    append(&head, 70);
    append(&head, 80);
    append(&head, 90);
    append(&head, 100);

    // Output Screen
    system("cls");
    printf("\n\n Before Reversing");
    print_list(head);
    printf("\n\n After Reversing");
    reverse_list(&head);
    print_list(head);
}

// Append Method
void append(list* head, int new_data)
{
    list new_node = (list) malloc(sizeof(struct node));
    new_node->data = new_data;
    if(*head == NULL)
    {
        new_node->link = new_node;
        *head = new_node;
        return;
    }
    list current = *head;
    while(current->link != *head)
        current = current->link;
    new_node->link = current->link;
    current->link = new_node;
}

// Reversing the List
void reverse_list(list *head)
{
    // Pointer for Traversal
    list current = (*head)->link;
    list prev = *head;
    list last = *head;

    // Moving Our Head Ahead
    *head = (*head)->link;

    // Traversing
    do
    {
        *head = (*head)->link;
       current->link = prev;
       prev = current;
       current = *head;
    }while (*head != last);

    // Assigning Our Head
    current->link = prev;
    *head = prev;
}


// Printing the List
void print_list(list head)
{
    if(head == NULL)
    {
        printf("\n\n The List is Empty!, Please Append Element!");
        return;
    }
    list current = head;
    printf("\n\n The List Elements are: ");
    do
    {
        printf("%d ", current->data);
        current = current->link;
    }while(current != head);
}