#include "mylinkedlist.h"

/* Create a node and insert data */
struct Node* createNode(int data)
{
    /* Creade a newNode and allocate dinamic memory */
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    /* If the newNode wasn't created occured a error in memory allocation */
    if (!newNode) {
        printf("Memory allocation error\n");
        return NULL;
    }
    /* Insert the data in the new node */
    newNode->data = data;
    /* Put the next pointer to NULL */
    newNode->next = NULL;
    return newNode;
}
/* Insert a node */
void insertNode(struct Node** head, int number)
{
    /* Create a new node */
    struct Node* newNode = createNode(number);
    /* Point the next node to this head node */
    newNode->next = *head;
    /* Now trade places with them so now this new node is the head node and has the next reference to the previous head node */
    *head = newNode;
}
/* Delete the node */
void deleteNode(struct Node** head)
{
    // Safety check: If the list is already empty, do nothing!
    if (*head == NULL) {
        return; 
    }
    /* Temporary node that is equal to the head node */
    struct Node* temp = *head;
    /* Point the head to the temporary, basically the second node now is the 1st */
    *head = (*head)->next;
    /* Delete the old node */
    free(temp);
}
/* Print the integer value of the node */
void printNodedata(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
