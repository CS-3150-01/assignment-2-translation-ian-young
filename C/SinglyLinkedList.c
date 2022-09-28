#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

 struct Node {
    int data;
    struct Node* next;
};

//Globally set head and current nodes
struct Node *head = NULL;
struct Node *current = NULL;

void addNode(struct Node** head, int data);
void showNodes(struct Node* node);

int main() {
    /**It is important to note that all functions will need to refer
     * to the head in one way or another for the code to work... Found
     * that out the hard way. **/

    //Add nodes to the list    
    addNode(&head,1);
    addNode(&head,2);
    addNode(&head,3);
    addNode(&head,4);  
            
    //Displays the nodes present in the list    
    showNodes(head); // Only need & if changing!!

    return 0;
}

void addNode (struct Node** head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next =*head;

    *head = newNode;
};

void showNodes (struct Node* node) {
    printf("\nYour linked list is: ");

    while (node != NULL) {
        printf("%d",node->data);
        node = node->next;
    }
    
    // Print a new, blank line for aesthetics
    printf("\n");
}