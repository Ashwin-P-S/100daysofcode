#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

struct node {
    int value;
    struct node* link;
};

typedef struct node* list;
list hash_table[MAX_SIZE];
int hash(int); // Hash Function
void insert_value(int);
void display_table();

void main() {
    int value, ans;

    // Initialization
    for(int i=0;i<MAX_SIZE;i++)
        hash_table[i] = NULL;
    system("cls");   //Clears Screen

    // Getting Values for Hash Table
    printf("\tCollision Handling Technique by Seperate Chaining\n");
    do {
        printf("\n Enter Value: ");
        scanf("%d", &value);
        insert_value(value);
        printf("\n Wish to Continue? (0/1): ");
        scanf("%d", &ans);
    } while(ans == 1);

    // Display the Hash Table
    display_table();
}

int hash(int value) {
    return (value % MAX_SIZE);
}

void insert_value(int value) {
    // Key for Value
    int key = hash(value);

    list new_node = (list) malloc(sizeof(struct node));
    new_node->value = value;
    new_node->link = NULL;

    // Check for Emptyness
    if(hash_table[key] == NULL) {
        hash_table[key] = new_node;
        return;
    }

    // If Collision Occurs
    list curr = hash_table[key];
    while(curr->link != NULL) {
        curr = curr->link;
    }
    curr->link = new_node;
}

void display_table() {

    list temp;
    system("cls");

    printf("\n\tHash Table with Size %d\n", MAX_SIZE);
    for(int i=0;i<MAX_SIZE;i++) {
        printf("\n %d - ", i);
        temp = hash_table[i];
        if(hash_table[i] == NULL) { printf("NULL "); continue;}
        while(temp != NULL) {
            printf("%d", temp->value);
            if(temp->link != NULL) printf("->");
            temp = temp->link;
        }
    }
}