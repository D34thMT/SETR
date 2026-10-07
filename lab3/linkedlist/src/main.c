#include <stdio.h>
#include <stdlib.h>

/* Define the node structure */
struct Node{
    int data;
    struct Node *next;
};

/* Function Prototypes */
struct Node* createNode(int data);                      /* Create a node and insert data        */
void insertNode(struct Node** head, int number);        /* Insert a node                        */
void deleteNode(struct Node** head);                    /* Delete the node                      */
void printNodedata(struct Node* head);                   /* Print the integer value of the node  */

int main(void){

    struct Node* head;

    head = createNode(5);
    printNodedata(head);
    insertNode(&head,20);
    insertNode(&head,90);
    insertNode(&head,1);
    insertNode(&head,3);
    printNodedata(head);
    deleteNode(&head);
    printNodedata(head);
    deleteNode(&head);
    printNodedata(head);
    deleteNode(&head);
    printNodedata(head);

    return 0;
}

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

void insertNode(struct Node** head, int number)
{
    /* Create a new node */
    struct Node* newNode = createNode(number);
    /* Point the next node to this head node */
    newNode->next = *head;
    /* Now trade places with them so now this new node is the head node and has the next reference to the previous head node */
    *head = newNode;
}

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

void printNodedata(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}