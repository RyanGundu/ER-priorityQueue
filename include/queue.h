#ifndef QUEUE
#define QUEUE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/LinkedListAPI.h"
#include "../include/patient.h"

/**
*Struct that initializes the queue that wraps the linked list
*/
typedef struct queue {
	List *list;
} Queue;
/**
*Removes from Node from back
*@param Queue wrapper to identify a list
*@param priority value to identify the front
*/
void *RemoveFromQueue(Queue *q, int priority);

/**
*Calls deleteList
*@param a single queue
*/
void deleteQueue (Queue *q);

/**
*Creates the  Queue wrapper for the linked-list
*@param printFunction function pointer to print a single node of the list
*@param deleteFunction function pointer to delete a single piece of data from the list
*@param compareFunction function pointer to compare two nodes of the list in order to test for equality or order
*/
Queue *createQueue (void (*printFunction)(void *toBePrinted), void (*deleteFunction)(void *toBeDeleted), int (compareFunction)(int first, int second));

/**
*Moves to the next node from the head
*@param Queue wrapper to identify a list
*/
void *Dequeue(Queue *q); 

/**
*Wrapper for getFromFront
*@param Queue wrapper to identify a list
*/
void *peek(Queue *q);

/**
*Wrapper for insertBack, inserts a node at the end of a list
*@param Queue wrapper to identify a list
*@param priority value to idetify a patients priority 
*/
void Enqueue(Queue* s, void *data, int priority);

/**
*User defined to free the data in a node
*@param void data to be deleted
*/
void deleteNode (void *toBeDeleted);

/**
*Wrapper for insertSorted, inserts a node based on its priority (ordered)
*@param Queue wrapper to identify a list
*@param data to possibly be compared
*@param priority value to idetify a patients priority 
*/
void insertSortedQueue (Queue *q, void *data, int priority);

/**
*User defined compare function used to order based on priority value
*@param first nodes priority value
*@param second nodes priority value
*@param returns 1 if first > second and -1 if first < second and 0 if equal
*/
int compare (int first, int second);

/**
*User defined print function to print the final data
*@param void *data to be typecasted and printed
*/
void printNode (void *data);



#endif
