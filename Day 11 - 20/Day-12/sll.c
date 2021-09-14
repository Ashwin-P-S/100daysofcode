#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int count = 0;

struct node 
{
    int data;
    struct node* next;
};

void insert_at_begining(struct node** head, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
    printf("\n\n The Element %d is Inserted at Begining!", new_data);
}

void insert_at_position(struct node** head, int position, int new_data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* ptr = *head;
    new_node->data = new_data;
    int i = 1;
    while(i != position-1)
    {
        ptr = ptr->next;
        i++;
    }
    new_node->next = ptr->next;
    ptr -> next = new_node;
    printf("\n\n The Element %d is Inserted at Position %d", new_data, position);
}

void append(struct node** head, int new_data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* last = *head;

    new_node->data = new_data;
    new_node->next = NULL;

    if(*head == NULL)
        *head = new_node;
    else
    {
        while(last->next != NULL)
            last = last->next;
        last->next = new_node;
    }

    printf("\n\n The Element %d is Inserted!", new_data);
}

int delete_by_element(struct node** head, int data)
{
    struct node* last = *head;
    int flag = 0;

    if(last->data == data)
    {
        *head = last->next;
        last->next == NULL;
        flag = 1;
    }
    else
    {    
        struct node* prev = *head;
        while(last->next!=NULL)
        { 
            last = last->next;
            if(last->data == data)
            {
                flag = 1;
                break;
            }
            prev = prev->next;
        }
        prev->next = last->next;
        last->next = NULL;
    }
    return flag;
}

int delete_by_position(struct node** head, int position)
{
    int flag = 0;
    struct node* last = *head;
    if(position == 1)
    {
        *head = last->next;
        last->next = NULL;
        flag = 1;
    }
    else
    {
        struct node* prev = *head;int i = 1;
        while(last->next!=NULL)
        {
            last = last->next;
            if(i == position-1){flag=1;break;}
            prev = prev->next;
            i++;
        }

        prev->next = last->next;
        last->next = NULL;
    }
    return flag;
}

int find_an_element(struct node** head, int data)
{
    int position = 0, i = 2;
    struct node* find = *head;
    if(find->data == data)
        position = 1;
    else
    {
        while(find->next!=NULL)
        {
            find = find->next;
            if(find->data == data)
                position = i;
            i++;
        }
    }
    return position;
}

void print_list(struct node* p)
{   
    if(p == NULL)
        printf("\n\n The List is Empty!... Please Append Element");
    else
    {
        int i = 0;
        printf("\n\n The Elements in the List are: ");
        while(p)
        {
            printf("%d", p->data);
            p = p->next;
            if(i != count-1){printf(", ");}
            i++;
        }
    }
}

int main()
{
    int choice, data, position, delete_choice, flag;
    struct node* head = (struct node*) malloc(sizeof(struct node));
    head = NULL;
    do
    {
        system("cls");
        printf("\n\t---------------------");
        printf("\n\t Singly Linked List");
        printf("\n\t---------------------");
        printf("\n\t1) Append Element");
        printf("\n\t2) Insert at Beginging");
        printf("\n\t3) Insert at Position");
        printf("\n\t4) Delete an Element");
        printf("\n\t5) Find the Element");
        printf("\n\t6) Print the List");
        printf("\n\t7) Exit from Menu");
        printf("\n\n\t---------------------");
        printf("\n\n Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n\n Enter the Element: ");
            scanf("%d", &data);
            append(&head, data);
            count++;
            print_list(head);
            getch();
            break;

        case 2:
            printf("\n\n Enter the Element: ");
            scanf("%d", &data);
            insert_at_begining(&head, data);
            count++;
            print_list(head);
            getch();
            break;

        case 3:
            if(count == 0)
                printf("\n\n The List is Empty!... Please Append Element");
            else
            {
                printf("\n\n Enter the Position and Element to Insert: ");
                scanf("%d %d", &position, &data);
                if(position > count)
                    printf("\n\n The List has only %d Elements & Postion %d is Not Available", count, position);
                else if (position == 1)
                {
                    insert_at_begining(&head, data);
                    count++;
                    print_list(head);
                }
                else
                {
                    insert_at_position(&head, position, data);
                    count++;
                    print_list(head);
                }
            }
            getch();
            break;

        case 4:
            if(count == 0)
                printf("\n\n The List is Empty!... Can't Delete Elements");
            else
            {
            system("cls");
            printf("\n\t\t Deleting An Element");
            printf("\n\n\n\t 1) Delete by Element");
            printf("\n\t 2) Delete by Position");
            printf("\n\n Enter Your Choice: ");
            scanf("%d", &delete_choice);
            if(delete_choice == 1)
            {
                system("cls");
                print_list(head);
                printf("\n\n Enter the Element to Delete: ");
                scanf("%d", &data);
                flag = delete_by_element(&head, data);
                if(flag == 0)
                    printf("\n\n Element %d is not in the List!", data);
                else
                {
                system("cls");
                count--;
                print_list(head);
                printf("\n\n The Element %d is Deleted!", data);
                }
            }
            else if(delete_choice == 2)
            {
                system("cls");
                print_list(head);
                printf("\n\n Enter the Position of element to Delete: ");
                scanf("%d", &position);
                flag = delete_by_position(&head, position);
                if(flag == 0)
                    printf("\n\n The List has Only %d Elements\n\n Position %d is not Available!", count, position);
                else
                {
                system("cls");
                count--;
                print_list(head);
                printf("\n\n The Element of Position %d is Deleted!", data);
                }
            }
            else{printf("\n\n Invalid Choice!... Try Again");}
            }
            getch();
            break;
        
        case 5:
            if(count == 0)
                printf("\n\n The List is Empty!... Can't find Elements");
            else
            {
                printf("\n\n Enter the Element to Find: ");
                scanf("%d", &data);
                position = find_an_element(&head, data);
                if(position == 0)
                    printf("\n\n The Element %d is not Found!", data);
                else
                {
                    printf("\n\n The Element %d is at Position %d", data, position);
                }
            }
            getch();
            break;
        
        case 6:
            print_list(head);
            getch();
            break;

        case 7:
            exit(0);
            break;

        default:
            printf("\n\n Invalid Choice!... Try Again");
            getch();
            break;
        }
    } while (choice != 7);
    
    return 0;
}