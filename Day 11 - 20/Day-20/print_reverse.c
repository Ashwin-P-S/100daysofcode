#include <stdio.h>
#include <stdlib.h>

// Linked List
struct Node
{
    int data;
    struct Node* link;
};

// Methods Declaration
struct Node* head;
void print_list(struct Node*);
void print_reverse(struct Node*);
void append(struct Node**, int);

// Main Function
int main(void)
{
    head = (struct Node*) malloc(sizeof(struct Node));
    head = NULL;
    append(&head, 2);
    append(&head, 4);
    append(&head, 6);
    append(&head, 8);
    append(&head, 10);
    append(&head, 12);
    printf("\n The Linked List");
    printf("\n\n The List is: ");
    print_list(head);
    printf("\n\n Printing in Reverse using Recursion");
    printf("\n\n The List is: ");
    print_reverse(head);
}

// Append Function
void append(struct Node** head, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->link = NULL;
    if(*head == NULL) {*head = new_node; return;}
    struct Node* last = *head;
    while (last->link != NULL)
        last = last->link;
    last->link = new_node;
}

// Printing the Original List
void print_list(struct Node* current)
{
    
    if(current == NULL) return;
    printf("%d ", current->data);
    print_list(current->link);
}

// Reverse Printing Using Recursive Calling
void print_reverse(struct Node* current)
{
    if(current == NULL) return;
    print_reverse(current->link);
    printf("%d ", current->data);
}