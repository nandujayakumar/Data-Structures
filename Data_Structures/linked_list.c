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
    swapNodes(22,20);
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

    // Use double pointer to avoid the conditional statements
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

    Node *current_node = head;
    Node **pp1 = &head, *X_node = NULL;
    
    //Find the data 1
    while (current_node){
        if (current_node -> data == data1){
            X_node = current_node;
            break;
        }
        pp1 = &current_node -> next;
        current_node = current_node -> next;
    }
    
    current_node = head;
    Node **pp2 = &head, *Y_node = NULL;
    
    //Find the data 2
    while (current_node){
        if (current_node -> data == data2){
            Y_node = current_node;
            break;
        }
        pp2 = &current_node -> next;
        current_node = current_node -> next;
    }
    
    // Change the previous nodes first
    *pp1 = Y_node;
    *pp2 = X_node;
    
    //swap the nodes
    Node *temp = X_node -> next;
    X_node -> next = Y_node -> next;
    Y_node -> next = temp;
}


