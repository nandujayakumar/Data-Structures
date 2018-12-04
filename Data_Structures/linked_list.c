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
    addElements(40);
    addElements(45);
    addElements(23);
    printList();
    deleteNode(22);
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

    Node *temp = head;
    Node *current_node,*previous_node;

    if (head -> data == data){
        head = temp -> next;
        free (temp);
        return;
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
