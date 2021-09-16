#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Circular Linked List Creation
struct node 
{
    int data;    
    struct node* next;
};

// Declaring Methods
void insert_at_end(struct node**, int);
void insert_at_begin(struct node**, int);
void insert_after(struct node**, int , int);
void insert_before(struct node**, int , int);
void search_element(struct node*, int);
void print_list(struct node*);

// Main Method
int main(void)
{
    int data;
    struct node* head = (struct node*) malloc(sizeof(struct node));
    head = NULL;
    insert_at_begin(&head, 100);
    insert_at_end(&head, 200);
    insert_at_end(&head, 300);
    insert_at_end(&head, 400);
    insert_at_end(&head, 500);
    insert_at_end(&head, 600);
    insert_at_end(&head, 700);
    insert_after(&head, 300, 350);
    insert_before(&head, 350, 325);
    print_list(head);
    printf("\n Enter an Element to Search: ");
    scanf("%d", &data);
    search_element(head, data);
}

// Inserting at Begining
void insert_at_begin(struct node** head, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head;
    
    if((*head) == NULL)
    {
        new_node->next = new_node;
        *head = new_node;
        return;
    }

    struct node* last = (*head);
    while(last->next != (*head))
        last = last->next;
    last->next = new_node;
}

// Inserting at End
void insert_at_end(struct node** head, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head;

    if((*head) == NULL)
    {
        new_node->next = new_node;
        (*head) = new_node;
        return;
    }

    struct node* last = (*head);
    while(last->next != (*head))
        last = last->next;
    last->next = new_node;
}

// Insert after any Elements
void insert_after(struct node** head, int value, int new_data)
{
    if(*head == NULL){printf("\n\n The List is Empty, Can't Insert After");return;}

    struct node* new_node =(struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;

    struct node* current = *head;
    do
    {
        if(current->data == value)
            break;
        current = current->next;
    }while(current != *head);

    if(current == *head){printf("\n\n %d is Not Present", value);return;}
    new_node->next = current->next;
    current->next = new_node;
}

// Insert Before any Elements
void insert_before(struct node** head, int value, int new_data)
{
    if(*head == NULL){printf("\n\n The List is Empty, Can't Insert Before");return;}
    if((*head)->data == value){insert_at_begin(head, new_data);return;}

    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;

    struct node* current = *head;
    do
    {
        if(current->next->data == value)
            break;
        current = current->next;
    }while(current != *head);
    new_node->next = current->next;
    current->next = new_node;
}

// Search Any Elements
void search_element(struct node* head, int value)
{
    if(head == NULL){printf("\n\n List is Empty, Can't Find Elements");return;}
    int i = 1;
    struct node* current = head;
    do
    {
        if(current->data == value)
        {
            printf("\n\n %d is Found at Position %d", value, i);
            return;
        }
        current = current->next;
        i++;
    }while(current != head);
    printf("\n\n %d is not Found!", value);
}

// Printing the Entire List
void print_list(struct node* head)
{
    if(head == NULL){printf("\n\n The List is Empty!");return;}
    printf("\n\n The List is: ");
    struct node* last = head;
    do
    {
        printf("%d ", last->data);
        last = last->next;
    }while(last != head);
}