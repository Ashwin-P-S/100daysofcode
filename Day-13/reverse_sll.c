#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};


void append_elements(struct node** head, int data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node* current = *head;

    new_node -> data = data;
    new_node -> next = NULL;

    if(*head == NULL)
        *head = new_node;
    else
    {
        while(current -> next != NULL)
            current = current -> next;
        current -> next = new_node;
    }
}
struct node* reverse_list(struct node* head)
{
    struct node* prev = NULL;
    struct node* current = NULL;

    while(head != NULL)
    {
        current = head -> next;
        head->next = prev;
        prev = head;
        head = current;
    }
    head = prev;
}


void print_list(struct node* current)
{
    int if_continue = 1;
    printf("\n\n The Elements in the List are: ");

    while(if_continue)
    {
        if(current->next == NULL)
            if_continue = 0;
        printf("%d ", current -> data);
        current = current -> next;
    }
}

int main()
{
    struct node* head = (struct node*) malloc(sizeof(struct node));
    int no_of_elements, elements;
    head = NULL;
    append_elements(&head, 100);
    append_elements(&head, 200);
    append_elements(&head, 300);
    append_elements(&head, 400);
    append_elements(&head, 500);
    append_elements(&head, 600);
    append_elements(&head, 700);
    append_elements(&head, 800);
    append_elements(&head, 900);
    append_elements(&head, 1000);
    print_list(head);
    head = reverse_list(head);
    print_list(head);
    return 0;
}