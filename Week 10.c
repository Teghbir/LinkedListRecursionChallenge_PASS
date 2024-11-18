#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} node_t;

// Function to insert a new node at the beginning of the list
node_t* push_front(node_t* head, int data) {
    // Step a: Allocate memory for the new node
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if (new_node == NULL) {
        perror("Failed to allocate memory");
        exit(1);
    }

    // Step b: Initialize the new node's data and set its next pointer to the current head
    new_node->data = data;
    new_node->next = head;

    // Step c: Return the new node as the new head of the list
    return new_node;
}

// Function to reverse the linked list recursively, complete it below:


// Function to print the linked list
void print_list(node_t* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to delete all nodes in the linked list
void delete_list(node_t** head) {
    node_t* current = *head;
    node_t* next_node;

    while (current != NULL) {
        next_node = current->next;  // Save the next node
        free(current);              // Free the current node
        current = next_node;        // Move to the next node
    }

    *head = NULL;  // Set head to NULL to avoid dangling pointers
}

// Main function
int main() {
    node_t* head = NULL;

    // Print the original list
    printf("Original List:\n");
    print_list(head);

    // Call the funciton to reverse the list:
  

    // Print the reversed list:
    

    // Delete the linked list
    delete_list(&head);

    // Verify the list is deleted
    printf("List after deletion:\n");
    print_list(head); // Should print "NULL"

    return 0;
}
