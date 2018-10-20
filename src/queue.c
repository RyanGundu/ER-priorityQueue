#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/queue.h"

Queue *createQueue (void (*printFunction)(void *toBePrinted), void (*deleteFunction)(void *toBeDeleted), int (compareFunction)(int first, int qecond)) {

	Queue *queue = malloc(sizeof(Queue));
	queue->list = initializeList(printFunction, deleteFunction, compareFunction);

	return queue;
}
void *Dequeue(Queue *q) 
{
	if (q->list->head->next != NULL) {
		q->list->head = q->list->head->next;
		q->list->head->previous = NULL;
	} else {
		q = NULL;
	}
	return q;
}

void *RemoveFromQueue(Queue *q, int priority) 
{
	if (q->list->head != NULL) {
		deleteNodeFromList(q->list, peek(q), priority);
	}
	return q;
}

void *peek(Queue *q) 
{
	return getFromFront(q->list);
}

void Enqueue(Queue* q, void *data, int priority)
{
	insertBack(q->list, data, priority);
}

void insertSortedQueue (Queue *q, void *data, int priority) {

	insertSorted(q->list, data, priority);
}

void deleteQueue (Queue *q) {
	deleteList(q->list);
}

void deleteNode (void *toBeDeleted) {
	Patient *temp = (Patient *)toBeDeleted;
	free(temp->ID);
	free(temp->symptom);
	free(temp);
	temp = NULL;
}

int compare (int first, int second) {

	if (first > second) {
		return 1;
	} else if (first < second) {
		return -1;
	} 

	return 0;
}

void printNode (void *data) {

	Patient *temp = (Patient *)data;
    printf("%s %d %s %d\n",temp->ID, temp->priority, temp->symptom, temp->timeFinished);
}

