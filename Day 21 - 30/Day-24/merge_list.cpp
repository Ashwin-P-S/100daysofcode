#include <iostream>
#include <conio.h>
using namespace std;

// First Linked List Creation
class node_one {
    public:
        int data;
        node_one* link;
};

// Second Linked List Creatin
class node_two {
    public:
        int data;
        node_two* link;
};

// Linked List for Merging
class Node {
    public:
        int data;
        Node* link;
};

// Methods Declaration
void append_one(node_one**, int);
void append_two(node_two**, int);
void merge(node_one**, node_two**);
void print_list(node_one*, node_two*);

int main(void)
{
    int number, data;
    node_one* head_one = new node_one();
    node_two* head_two = new node_two();
    system("cls");
    head_one = NULL;
    head_two = NULL;
    cout<<"\n How Many Elements in List: ";
    cin>>number;
    cout<<"\n Enter First List Elements One-by-one:\n\n";
    for( int i=0;i<number;i++ )
    {
        cin>>data;
        append_one(&head_one, data);
    }
    
    cout<<"\n Enter Second List Elements One-by-one:\n\n";
    for( int i=0;i<number;i++ )
    {
        cin>>data;
        append_two(&head_two, data);
    }
    print_list(head_one, head_two);
    merge(&head_one, &head_two);
}

void append(Node** head, int new_data)
{
    Node* new_node = new Node();
    new_node -> data = new_data;
    new_node -> link = NULL;
    if (*head == NULL)
        *head = new_node;
    else
    {
        Node* last = *head;
        while(last -> link != NULL)
            last = last -> link;
        last -> link = new_node;
    }
}

void append_one(node_one** head, int new_data)
{
    node_one* new_node = new node_one();
    new_node -> data = new_data;
    new_node -> link = NULL;
    if (*head == NULL)
        *head = new_node;
    else
    {
        node_one* last = *head;
        while(last -> link != NULL)
            last = last -> link;
        last -> link = new_node;
    }
}

void append_two(node_two** head, int new_data)
{
    node_two* new_node = new node_two();
    new_node -> data = new_data;
    new_node -> link = NULL;
    if (*head == NULL)
        *head = new_node;
    else
    {
        node_two* last = *head;
        while(last -> link != NULL)
            last = last -> link;
        last -> link = new_node;
    }
}

void print_list(node_one* head_one, node_two* head_two)
{
    node_one* current_one = head_one;
    node_two* current_two = head_two;
    cout << "\n\n The Elements in First List are: ";
    while(current_one != NULL)
    {
        cout << current_one -> data << " ";
        current_one = current_one -> link;
    }
    cout << "\n\n The Elements in Second List are: ";
    while(current_two != NULL)
    {
        cout << current_two -> data << " ";
        current_two = current_two -> link;
    }
}

void merge(node_one** head_one, node_two** head_two)
{
    node_one* one = *head_one;
    node_two* two = *head_two;

    Node* head = new Node();
    head = NULL;
    
    while(two != NULL)
    {
        append(&head, one->data);
        append(&head, two->data);
        one = one->link;
        two = two->link;
    }

    Node* current = head;
    cout<<"\n\n The Merged List is: ";
    while(current != NULL)
    {
        cout << current->data << " ";
        current = current->link;
    }
    cout<<"\n\n";
}