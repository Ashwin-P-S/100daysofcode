#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* link;
};

Node* reverse_list(Node* head)
{
    Node* prev = NULL;
    Node* next = NULL;
    while(head != NULL)
    {
        next = head -> link;
        head -> link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
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

void print_list(Node* current)
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

int main(void)
{
    Node* head = new Node();
    head = NULL;
    int count, new_data;
    system("cls");
    cout << "Enter No of Elements: ";
    cin >> count;
    for(int i=0;i<count;i++)
    {
        cout << "\nEnter Element " << i+1 << ": ";
        cin >> new_data;
        append(&head, new_data);
    }
    print_list(head);
    head = reverse_list(head);
    cout << "\n\n After Reversing:";
    print_list(head);
    return 0;
}