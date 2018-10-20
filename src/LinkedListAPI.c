/**
 * @file LinkedListAPI.c
 * @author Ryan Gundu
 */
#ifndef _LIST_API_
#define _LIST_API_
#define EXIT_FAILURE 0
#define EXIT_SUCCESS 1

#include "../include/LinkedListAPI.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct listNode{
    int priority;
    void *data;
    struct listNode *previous;
    struct listNode *next;
} Node;

typedef struct listHead{
    Node *head;
    Node *tail;
    void (*deleteNode)(void *toBeDeleted);
    int (*compare)(int first, int second);
    void (*printNode)(void *toBePrinted);
} List;


List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(int first, int second)) {
	
	List *linkedList = malloc(sizeof(List));
    linkedList->head = NULL;
    linkedList->tail = NULL;


    linkedList->deleteNode = deleteFunction;
    linkedList->compare = compareFunction;
    linkedList->printNode = printFunction;
    return linkedList;
}

Node *initializeNode(void *data, int priority) {

    Node *newNode = malloc(sizeof(Node));
    newNode->priority = priority;
    newNode->data = data;
    newNode->previous = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertFront(List *list, void *toBeAdded, int priority) {

    Node* newNode = initializeNode(toBeAdded, priority);

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        return;  
    } 
    newNode->next = list->head;
    list->head->previous = newNode;
    list->head = newNode;
}

void insertBack(List *list, void *toBeAdded, int priority) {

     Node *newNode = initializeNode(toBeAdded, priority);

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        
    } else {
        newNode->previous = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }

}

void insertSorted(List *list, void *toBeAdded, int priority) {

    int x = 0;
    Node *newNode = initializeNode(toBeAdded, priority);
    
    Node *temp = list->head;
    /* if list empty */
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    }
    /* if only 1 node in list */
    else if (temp->previous == NULL && temp->next == NULL) {
        x = list->compare(temp->priority, newNode->priority);
        if (x == 1) {
            insertFront(list, newNode->data, priority);
        }
        else if (x == -1 || x == 0){
            insertBack(list, newNode->data, priority);
        }
    } else { 
        temp = list->tail;
        x = list->compare(temp->priority, newNode->priority);

        if (x == -1 || x == 0) {
            insertBack(list, newNode->data, priority);
        } else {
            while (1) {
                if (x == 1) {
                    temp = temp->previous;
                    x = list->compare(temp->priority, newNode->priority);
                }
                if (x == -1 || x == 0) {
                    newNode->next = temp->next;
                    temp->next = newNode;
                    newNode->previous = temp;
                    newNode->next->previous = newNode;
                    break;
                } 
                if (temp->previous == NULL) {
                    insertFront(list, newNode->data, priority);
                    break;
                }

            }
       }
    }
}


int deleteNodeFromList(List *list, void *toBeDeleted, int priority) {

    Node *temp = list->head;
    if (temp == NULL) {
        return EXIT_FAILURE;
    }
    while (temp != NULL) {
            if (list->compare(temp->priority, priority) == 0) {
                
                 /* deleting the only node in list */
                if (temp->next == NULL && temp->previous == NULL) {
                    list->head = NULL;
                    list->tail = NULL;
                    list->deleteNode(temp->data);
                    free(temp);
                    temp = NULL;
                    return EXIT_SUCCESS;
                }
                /* deleting the last node in a list */
                 else if (temp->next == NULL && temp->previous != NULL) {
                    list->tail = list->tail->previous;
                    list->tail->next = NULL;
                    list->deleteNode(temp->data);
                    free(temp);
                    temp = NULL;
                    return EXIT_SUCCESS;
                }
                /* deleating first node in a list */
                else if (temp->previous == NULL && temp->next != NULL) {
                    list->head = list->head->next;
                    list->head->previous = NULL;
                    list->deleteNode(temp->data);
                    free(temp);
                    temp = NULL;
                    return EXIT_SUCCESS;
                }
                /* deleting a node in the middle of a list */
                else if (temp->previous != NULL && temp->next != NULL) {
                    temp->previous->next = temp->next;
                    temp->next->previous = temp->previous;
                    list->deleteNode(temp->data);
                    free(temp);
                    temp = NULL;
                    return EXIT_SUCCESS;
                }
            }
            temp = temp->next;
    } 

    return -1;
}

void deleteList(List *list) {
    Node *temp = list->head;

    while (temp != NULL) {
            deleteNodeFromList(list, temp->data, temp->priority);
            temp = temp->next;
    } 
    free(list);
    list = NULL;
}

void *getFromFront(List *list) {
    return list->head->data;
}

void *getFromBack(List *list) {
    return list->tail->data;
}

void printBackwards(List *list) {

    Node *temp = list->tail;
    while (temp != NULL) {
            list->printNode(temp->data);
            temp = temp->previous;
    } 
}

void printForward(List *list) {

    Node *temp = list->head;
    while (temp != NULL) {
            list->printNode(temp->data);
            temp = temp->next;
    } 
}

#endif


