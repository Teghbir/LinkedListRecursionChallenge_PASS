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
    while (1) {
        printf("%d -> ", temp->data);
        temp = temp->next;
        if (temp == head) {
            break;
        }
    }
    printf("(head)\n");
}

// Function to remove a node at a specific position (1-based indexing)
node_t* remove_at_position(node_t* head, int position) {
    if (head == NULL) {
        printf("Error: List is empty\n");
        return NULL;
    }

    // Handle invalid position
    if (position <= 0) {
        printf("Error: Invalid position\n");
        return head;
    }

    node_t* temp = head;
    node_t* prev = NULL;

    // If removing the head node
    if (position == 1) {
        // Find the last node
        while (temp->next != head) {
            temp = temp->next;
        }

        if (temp == head) {
            // Single node case
            free(head);
            return NULL;
        }

        // Update the last node's next pointer and remove the head
        temp->next = head->next;
        node_t* to_delete = head;
        head = head->next;
        free(to_delete);
        return head;
    }

    // Traverse the list to find the node at the specified position
    int count = 1;
    temp = head;
    while (count < position) {
        prev = temp;
        temp = temp->next;

        // Break if we complete one loop without finding the position
        if (temp == head) {
            printf("Error: Position out of range\n");
            return head;
        }
        count++;
    }

    // Remove the node
    prev->next = temp->next;
    free(temp);
    return head;
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

    // Remove a node at position 2
    int position = 2;
    printf("Removing node at position %d\n", position);
    head = remove_at_position(head, position);

    // Display the updated circular linked list
    printf("Updated Circular Linked List: ");
    display(head);

    // Try removing a node at an invalid position
    position = 10;
    printf("Removing node at position %d\n", position);
    head = remove_at_position(head, position);

    return 0;
}
