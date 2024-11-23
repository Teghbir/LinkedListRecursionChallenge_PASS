#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} node_t;

// Function to insert a new node at the end of the circular linked list
node_t* push_rear(node_t* head, int data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if (new_node == NULL) {
        perror("Failed to allocate memory");
        exit(1);
    }
    new_node->data = data;

    if (head == NULL) {
        // List is empty, new node becomes head and points to itself
        new_node->next = new_node;
        return new_node;
    }

    // Find the last node
    node_t* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    // Insert the new node at the end and make it circular
    temp->next = new_node;
    new_node->next = head;
    return head;
}

// Function to display the circular linked list
void display(node_t* head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    node_t* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main function
int main() {
    node_t* head = NULL;

    // Create the circular linked list by pushing elements to the rear
    head = push_rear(head, 4);
    head = push_rear(head, 3);
    head = push_rear(head, 2);
    head = push_rear(head, 1);

    // Display the circular linked list
    printf("Circular Linked List: ");
    display(head);

    return 0;
}

