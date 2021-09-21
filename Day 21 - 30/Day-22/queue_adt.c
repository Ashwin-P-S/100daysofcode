#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Linked List Creation for Queue Operations
struct node
{
	int data;
	struct node* link;
};

// Declaration of Methods
typedef struct node* queue;
void enqueue(queue*, queue*, int);
int dequeue(queue*);
void print_queue(queue);

// Main Function
int main(void)
{
	queue front, rear; int choice = 0, data;
	front = rear = NULL;
	
	while(choice != 4)
	{
		system("cls");	// Clear Screen
		printf("\n\n\t Queue Operations");
		printf("\n\n 1) Enqueue");
		printf("\n 2) Dequeue");
		printf("\n 3) Print Queue");
		printf("\n 4) Exit");
		printf("\n\n Enter your Choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("\n\n Enter the Element: ");
				scanf("%d", &data);
				enqueue(&front, &rear, data);
				printf("\n\n %d is Enqueued", data);
				print_queue(front);
				break;
			
			case 2:
				// If Queue is Empty
				if(front == NULL){printf("\n\n The Queue is Empty! - Queue Underflow!");break;}
				
				printf("\n\n %d is Dequeued", dequeue(&front));
				print_queue(front);
				break;
			
			case 3: print_queue(front); break;
			case 4: exit(0);
			default: printf("\n\n Invalid Choice...");
		}
		getch();
	}
}

// Enqueue Operation
void enqueue(queue* front, queue* rear, int new_data)
{
	// New Node - for Enqueuing
	queue new_node = (queue) malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->link = NULL;
	
	// If Queue is Empty
	if(*front == NULL) 
	{
		*front = new_node;
		*rear = new_node;
		return;
	}
	
	queue current = *rear;
	current->link = new_node;
	
	*rear = new_node;
}

// Dequeue Operation
int dequeue(queue* front)
{
	queue current = *front;
	int data = current->data;
	*front = current->link;
	free(current);
	return data;
}

// Printing the Queue
void print_queue(queue front)
{
	queue current = front;
	
	// If Queue is Empty
	if(current == NULL)
	{
		printf("\n\n Queue is Empty!");
		return;
	}
	
	printf("\n\n The Queue is: ");
	while(current != NULL)
	{
		printf("%d ", current->data);
		current = current->link;
	}
	free(current);
}
