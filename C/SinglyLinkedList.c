#include <stdio.h>
#include <stdlib.h>

void insert(struct Node**, int);
void display(struct Node*);

struct Node {
    int data;
    struct Node* next;
};

int main() {
    /**It is important to note that all functions will need to refer
     * to the head in one way or another for the code to work... Found
     * that out the hard way. **/

    struct Node* head = NULL; // Set the head

    //Add nodes to the list    
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);  
            
    //Displays the nodes present in the list    
    display(head); // Only need & if changing!!

    return 0;
}

void insert (struct Node** head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next =*head;

    *head = newNode;
};

void display (struct Node* node) {
    printf("\nYour linked list is: ");

    while (node != NULL) {
        printf("%d",node->data);
        node = node->next;
    }
    
    // Print a new, blank line for aesthetics
    printf("\n");
}