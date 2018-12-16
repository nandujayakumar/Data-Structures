#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}Node ;

/* Head node always point to the First element of the Linked List
 * Tail node always points to the Last element of the Linked list
 */

Node *head = NULL;
Node *tail = NULL;

void InsertElement(int data);
void PrintList();
void ReversePrint();
void DeleteNode(int data);
void SwapNode(int data1,int data2);

void main(){

    InsertElement(22);
    InsertElement(30);
    InsertElement(40);
    InsertElement(35);
    PrintList();
    DeleteNode(35);
    PrintList();
}

/* Insert Elements to the linked list */
void InsertElement(int data){

    Node *temp;

    temp = (Node *)malloc(sizeof(Node));
    temp -> data = data;
    temp -> prev = NULL;
    temp -> next = NULL;

    if (! head ){
        head = temp;
        tail = temp;
        return;
    }

    // Variable to keep track of the current node
    Node *current_node = head;

    while (current_node -> next){
        current_node = current_node -> next;
    }

    temp -> prev = current_node;
    current_node -> next = temp;
    tail = temp;
}

/* Print the elements of the linked list in forward order */
void PrintList(){

    Node *current_node = head;
    
    while(current_node){
        printf("%i -> ",current_node -> data);
        current_node = current_node -> next;
    }
    printf("NULL\n");
}

void ReversePrint(){
    
    // Iterate with the tail pointer
    Node *current_node = tail;

    while (current_node){
        printf("%i ->",current_node -> data);
        current_node = current_node -> prev;
    }
    printf("NULL\n");
}

void DeleteNode (int data){

    Node *current_node = head , **pp = &head ;
    
    // Iterate through the list to find the data 
    while (current_node){
        if (current_node -> data == data){
            *pp = current_node -> next ;
            free (current_node);
            break;
        }
        pp = &current_node -> next;
        current_node = current_node -> next;
    }
}
