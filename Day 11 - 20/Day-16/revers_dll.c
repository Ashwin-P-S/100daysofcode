#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    struct node* prev;
    int data;
    struct node* next;
};

void reverse_list(struct node**);
void insert_at_end(struct node**, int);
void print_list(struct node*);

int main()
{
    //Our Head Pointer
    struct node* head = (struct node*) malloc(sizeof(struct node));
    head = NULL;    //Initiates NULL

    //Inserting Few Elements
    insert_at_end(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
    insert_at_end(&head, 40);
    insert_at_end(&head, 50);
    insert_at_end(&head, 60);

    //Before Reversing
    printf("\n\t Before Reversing");
    print_list(head);

    reverse_list(&head);    //Reversing the LIST

    //After Reversing
    printf("\n\n\t After Reversing");
    print_list(head);
    getch();
}

void insert_at_end(struct node** head, int new_data)
{
    //Creating Node for Data
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;   //Assigning Data
    new_node->next = NULL;

    //Check for Empty List
    if(*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;    //Initializing Our Head Data
        return;
    }

    //Traversing to Last Node 
    struct node* last = *head;
    while(last->next != NULL)
        last = last->next;

    //Insertint at End
    last->next = new_node;
    new_node->prev = last;
}

void print_list(struct node* head)
{
    struct node* current = head;    //Current for Traversal
    printf("\n\n The Elements are: ");

    //Printing One-by-One
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

void reverse_list(struct node** head)
{
    //Before & After for Reversing [Interchanging]
    struct node* before = *head;
    struct node* after = before->next;

    //Starts with Head
    before->next = NULL;
    before->prev = after;

    //Traversing to Last Element
    while(after != NULL)
    {
        after->prev = after->next;
        after->next = before;
        before = after;
        after = after->prev;
    }

    //Assigning our Head
    *head = before;
}