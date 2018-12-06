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
void getSize();

void main(){

    addElements(22);
    addElements(10);
    addElements(20);
    addElements(34);
    addElements(23);
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

    Node *current_node = head;
    Node *previous_node;

    /* If the node to be deleted is a head node then rearrange the head pointer  */
    if (head -> data == data){
        head = current_node -> next;
        free (current_node);
        return;
    }

    current_node = head -> next;
    previous_node = head;

    /* For other nodes rearrange the pointer of the previous node */
    while (current_node){
        if (current_node -> data == data){
            previous_node -> next = current_node -> next;
            free (current_node);
        }
        else{
            previous_node = current_node;
            current_node = current_node -> next;
        }
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

/* Print the size occupied by the Linked List */
void getSize(){

    Node *current_node = head;
}
