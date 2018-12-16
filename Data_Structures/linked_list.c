/* The code contains the implementation of singly Linked List and various operations */

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
}Node;

Node *head = NULL;

void addElements(int data);
void printList();
void deleteNode(int data);
void swapNodes(int data1,int data2);
void reverseList();

void main(){

    addElements(22);
    addElements(10);
    addElements(20);
    addElements(34);
    addElements(23);
    printList();
    swapNodes(10,20);
    printList();
    reverseList();
    deleteNode(20);
    printList();
}

/* Add Elements to the LinkedList */
void addElements(int data){

    Node *temp, *current_node;
    temp = (Node *)malloc(sizeof(Node));
    temp -> data = data;
    temp -> next = NULL;
    
    if (head == NULL){
        head = temp;
        return;
    }

    current_node = head;
    while (current_node -> next != NULL){
        current_node = current_node -> next;
    }
    current_node -> next = temp; 
}

/* Delete a node from the Linked List */
void deleteNode (int data){

    /* Use double pointer to avoid the conditional statements used for head nodes and intermediate nodes cases */

    Node *current_node = head, **pp = &head;

    while (current_node){
        
        // On finding the value de-reference the double pointer and change its next link

        if (current_node -> data == data){
            *pp = current_node -> next;
             free(current_node);
             break;
        }

        pp = &current_node -> next;
        current_node = current_node -> next;
    }
}

/* Print the LinkedList */
void printList (){

    Node *current_node = head;

    while (current_node){
        printf("%i -> \t",current_node -> data);
        current_node = current_node -> next;
    }

    printf("NULL");
    printf("\n");
}

/* Swap nodes without swapping the data of each node */
void swapNodes(int data1,int data2){

    // Same nodes cannot be swapped
    if (data1 == data2){
        return;
    }
    
    // Search for x and keep track of the present and previous nodes
    Node *current_Xnode = head, *previous_Xnode = NULL;

    while (current_Xnode && current_Xnode -> data != data1){
 
        previous_Xnode = current_Xnode;
        current_Xnode = current_Xnode -> next;
    }

    // search for y and keep track of the previous and present nodes
    Node *current_Ynode = head, *previous_Ynode = NULL;

    while (current_Ynode && current_Ynode -> data != data2){

        previous_Ynode = current_Ynode;
        current_Ynode  = current_Ynode -> next;
    }

    // If X or Y is not present in the linkedlist
    if (! current_Xnode || ! current_Ynode){
        return;
    }
    
    // Check if the X node is a head node or not
    if (previous_Xnode){
        previous_Xnode -> next = current_Ynode;
    }
    else{
        head = current_Ynode;
    }

    // Check if the Y node is a head node or not
    if (previous_Ynode){
        previous_Ynode -> next = current_Xnode;
    }
    else{
        head = current_Xnode;
    }
    
    // Swap the current pointers
    Node *temp = current_Xnode -> next;
    current_Xnode -> next = current_Ynode -> next;
    current_Ynode -> next = temp; 
}

/* Reverse the Linked list */
void reverseList(){

    Node *current_node = head , *previous_node = NULL;
    Node *temp = NULL;
    
    // Temp variable stores the next link of the current_node
    while (current_node){
        temp = current_node -> next;
        
        // If the node is a head node then make the next of head node as NULL
        if (previous_node == NULL){
            current_node -> next = NULL;
        }

        // If not a head node then make the next of current node as the previous node
        else{
            current_node -> next = previous_node;
        }
        previous_node= current_node;
        current_node = temp;
    }
    head = previous_node;
}


