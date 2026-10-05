#include <stdio.h>
#include <stdlib.h>

/* Define the node structure */
struct Node{
    int data;
    struct Node *next;
};

/* Function Prototypes */
struct Node* createNode(int data);                      /* Create a node and insert data        */
void insertNode(struct Node** linkedNode, int number);  /* Insert a node                        */
void deleteNode(struct Node linkedNode);                /* Delete the node                      */
int printNodedata(struct Node linkedNode);              /* Print the integer value of the node  */

int main(void){


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

void insertNode(struct Node** linkedNode, int number)
{

}

void deleteNode(struct Node linkedNode)
{

}

int printNodedata(struct Node linkedNode)
{

}