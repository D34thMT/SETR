#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

#define EMPTY_LINKED_LIST 1;

/* Define the structure of the linked list */
struct Node{
    int data;
    struct Node* next;
};

/* Functions Prototypes */
struct Node* createNode(int data);                      /* Create a node and insert data        */
void insertNode(struct Node** head, int number);        /* Insert a node                        */
void deleteNode(struct Node** head);                    /* Delete the node                      */
void printNodedata(struct Node* head);                   /* Print the integer value of the node  */


#endif