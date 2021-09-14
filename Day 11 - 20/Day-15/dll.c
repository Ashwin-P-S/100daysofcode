#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

int is_empty(struct node** head)
{
    if(*head == NULL)
    {
        printf("\n\n The List is Empty!");
        return 1;
    }
    return 0;
}

void push(struct node** head, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = *head;
    if(*head != NULL)
        (*head)->prev = new_node;
    *head = new_node;
    printf("\n\n %d is Inserted first", new_data);
}

void append(struct node** head, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }
    struct node* last = *head;
    while(last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
    printf("\n\n %d is Inserted Last", new_data);
}

void insert_after(struct node** head, int value, int new_data)
{
    if(is_empty(head)){return;}
    struct node* current = *head;
    while(current!=NULL)
    {
        if(current->data == value)
            break;
        current = current->next;
    }
    if(current == NULL){printf("\n\n %d is Not Present!", value);return;}
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    if(current->next==NULL)
    {
        current->next = new_node;
        new_node->prev = current;
        new_node->next = NULL;
        printf("\n\n %d is Inserted after %d", new_data, value);
        return;
    }
    current->next->prev = new_node;
    new_node->next = current->next;
    current->next = new_node;
    new_node->prev = current;
    printf("\n\n %d is Inserted after %d", new_data, value);
}

void insert_before(struct node** head, int value, int new_data)
{
    if(is_empty(head)){return;}
    struct node* current = *head;
    while(current!=NULL)
    {
        if(current->data == value)
            break;
        current = current->next;
    }
    if(current == NULL){printf("\n\n %d is Not Present!", value);return;}
    if(current == *head || current->prev == NULL){push(head, new_data);return;}
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    current->prev->next = new_node;
    new_node->prev = current->prev;
    current->prev = new_node;
    new_node->next = current;
    printf("\n\n %d is Inserted before %d", new_data, value);
}

void pop(struct node** head)
{
    if(is_empty(head)){return;}
    int data = (*head)->data;
    struct node* current = *head;
    if((*head)->next == NULL){*head = NULL;printf("\n\n %d is Deleted", data);return;}
    *head = current->next;
    current->next->prev = NULL;
    current->next = NULL;
    printf("\n\n %d is Deleted", data);
}

void delete_last(struct node** head)
{
    if(is_empty(head)){return;}
    struct node* last = *head;
    while(last->next != NULL)
        last = last->next;
    if(last == *head){*head == NULL;printf("\n\n Last Element is Deleted");return;}
    last->prev->next = NULL;
    last->prev = NULL;
    printf("\n\n Last Element is Deleted");
}

void delete_element(struct node** head, int data)
{
    if(is_empty(head)){return;}
    struct node* current = *head;
    while(current != NULL)
    {
        if(current->data == data)
            break;
        current = current->next;
    }
    if(current == NULL){printf("\n\n %d is Not Present");return;}
    if(current == *head){pop(head);return;}
    if(current->next == NULL){delete_last(head);}
    current->prev->next = current->next;
    current->next->prev = current->prev;
    current->next = NULL;current->prev = NULL;
    printf("\n\n %d is Deleted", data);
}

void delete_after(struct node** head, int value)
{
    if(is_empty(head)){return;}
    struct node* current = *head;
    while(current != NULL)
    {
        if(current->data == value)
            break;
        current = current->next;
    }
    if(current == NULL){printf("\n\n %d is Not Present", value);return;}
    if(current->next == NULL){printf("\n\n No Element is Present after %d", value);return;}
    current = current->next;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    current->next = NULL;current->prev = NULL;
    printf("\n\n Element after %d is Deleted", value);
}

void delete_before(struct node** head, int value)
{
    if(is_empty(head)){return;}
    struct node* current = *head;
    while(current != NULL)
    {
        if(current->data == value)
            break;
        current = current->next;
    }
    if(current == NULL){printf("\n\n %d is Not Present", value);return;}
    if(current->prev == NULL){printf("\n\n No Element is Present before %d", value);return;}
    current = current->prev;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    current->next = NULL;current->prev = NULL;
    printf("\n\n Element before %d is Deleted", value);
}

void print_list(struct node** head)
{
    if(is_empty(head)){return;}
    struct node* current = *head;
    printf("\n\n The List is: ");
    while(current!=NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

void print_list_reverse(struct node** head)
{
    struct node* current = *head;
    if(is_empty(head)){return;}
    while(current->next != NULL)
        current = current->next;
    printf("\n\n The Reversed List is: ");
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current->prev;
    }
}

void main()
{
    int choice, data, value;
    struct node* head = (struct node*) malloc(sizeof(struct node));
    head = NULL;
    push(&head, 100);
    push(&head, 50);
    append(&head, 150);
    append(&head, 200);
    while(1)
	{
		system("cls");
		print_list(&head);
		printf("\n\n\t1) Insert At Begining (Push)");
		printf("\n\t2) Insert At End (Append)");
		printf("\n\t3) Insert Before an Element");
		printf("\n\t4) Insert After an Element");
		printf("\n\t5) Delete First Element (Pop)");
		printf("\n\t6) Delete Last Element");
		printf("\n\t7) Delete Before an Element");
		printf("\n\t8) Delete After an Element");
		printf("\n\t9) Delete an Element");
		printf("\n\t10) Print the List in Reverse");
        printf("\n\t11) Exit");
		printf("\n\n Enter Your Choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: 
				printf("\n Enter Element: ");scanf("%d", &data);
				push(&head, data);
				break;
			case 2:
				printf("\n Enter Element: ");scanf("%d", &data);
				append(&head, data);
				break;
			case 3:
				printf("\n Enter Element, before which you want to Insert and Element to Insert: ");scanf("%d%d", &value, &data);
				insert_before(&head, value, data);
				break;
			case 4:
				printf("\n Enter Element, after which you want to Insert and Element to Insert: ");scanf("%d%d", &value, &data);
				insert_after(&head, value, data);
				break;
			case 5: pop(&head); break;
			case 6: delete_last(&head); break;
			case 7:
				printf("\n Enter the Element, before which you want to Delete: ");scanf("%d", &value);
				delete_before(&head, value);
				break;
			case 8:
				printf("\n Enter the Element, after which you want to Delete : ");scanf("%d", &value);
				delete_after(&head, value);
				break;
			case 9:
				printf("\n Enter the Element to Delete: ");scanf("%d", &data);
				delete_element(&head, data); break;
            case 10:
                print_list_reverse(&head);
                getch();break;
			case 11:
				exit(0);
			default:
				printf("\n Invalid Choice..."); 
		}
		getch();
    }
    
}