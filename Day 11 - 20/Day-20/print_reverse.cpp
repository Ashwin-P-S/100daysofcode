#include <iostream>
using namespace std;

// Linked List
class Node
{
    public:
    int data;
    Node* link;
};

// Methods Declaration
void append(Node**, int);
void print_list(Node*);
void print_reverse(Node*);

// Main Function
int main(void)
{
    Node* head = new Node();
    head = NULL;
    append(&head, 2);
    append(&head, 4);
    append(&head, 6);
    append(&head, 8);
    append(&head, 10);
    append(&head, 12);
    cout << "\n The Linked List";
    cout << "\n\n The List is: ";
    print_list(head);
    cout << "\n\n Printing in Reverse using Recursion";
    cout << "\n\n The List is: ";
    print_reverse(head);
}

// Append New Elements
void append(Node** head, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->link = NULL;
    if(*head == NULL){*head = new_node; return;}
    Node* last = *head;
    while(last->link != NULL)
        last = last->link;
    last->link = new_node;
}

// Printing the Original List
void print_list(Node* current)
{
    
    if(current == NULL) return;
    cout << current->data << " ";
    print_list(current->link);
}

// Reverse Printing Using Recursive Calling
void print_reverse(Node* current)
{
    if(current == NULL) return;
    print_reverse(current->link);
    cout << current->data << " ";
}