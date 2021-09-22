#include <iostream>
#include <conio.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* link;
};

void append(Node**, int);
void printList(Node*);
void printMiddle(Node*);

int main(void)
{

    Node* head = new Node();
    head = NULL;
    int n, data;
    system("cls");
    cout << "\n Enter No of Elements: "; cin >> n;
    cout << "\n Enter Elements One-by-One:\n\n";
    while(n--)
    {
        cin >> data;
        append(&head, data);
    }
    system("cls");
    printList(head);
    printMiddle(head);
    getch();
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

void printList(Node* current)
{
    if(current == NULL)
        cout << "\n\n The List is Empty";
    else
    {
        cout << "\n\n The Elements in List are: ";
        while(current != NULL)
        {
            cout << current -> data << " ";
            current = current -> link;
        }
    }
}

void printMiddle(Node* head)
{
    Node* slow_ptr = head;
    Node* fast_ptr = head;

    while( fast_ptr != NULL && fast_ptr->link != NULL)
    {
        slow_ptr = slow_ptr->link;
        fast_ptr = fast_ptr->link->link;
    }
    cout << "\n\n The Middle Element is: " << slow_ptr->data;
}