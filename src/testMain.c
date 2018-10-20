#include "../include/LinkedListAPI.h"
#include "../include/queue.h"
#include "../include/simulationA2.h"
#include "../include/patient.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Test main for queue*/

int main (int arg, char *argv[]) {

	/*Note: when insertSortedQueue is used so the expected output may not be at the head or tail*/

	Queue *q = createQueue(&printNode, &deleteNode, &compare);

	printf("Expected Output: Ray 2 CV\n");
	Patient *a = createPatient("Ray", 2, "CV");
	insertSortedQueue(q, a, 2);	
	printf("Actual Output:\n");
	printForward(q->list);
	printf("\n");

	printf("Expected Output: bill 1 NC\n");
	a = createPatient("bill", 1, "NC");
	insertSortedQueue(q, a, 1);	
	printf("Actual Output:\n");
	printForward(q->list);
	printf("\n");

	printf("Expected Output:  4 EV\n");
	a = createPatient(" ", 4, "EV");
	insertSortedQueue(q, a, 4);	
	printf("Actual Output\n");
	printForward(q->list);
	printf("\n"); 

	/* Generates error due to missing input
	printf("Expected Output: Ryan  RC\n");
	a = createPatient("Ryan", 10);
	insertSortedQueue(q, a, );	
	printf("Actual Output:\n");
	printForward(q->list);
	printf("\n"); */

	printf("Expected Output: 12345 5 TR\n");
	a = createPatient("12345", 5, "TR");
	insertSortedQueue(q, a, 5);	
	printf("Actual Output:\n");
	printForward(q->list);
	printf("\n");

	printf("Expected Output: # 3 SA\n");
	a = createPatient("#", 3, "SA");
	insertSortedQueue(q, a, 3);	
	printf("Actual Output:\n");
	printForward(q->list);
	printf("\n");

	printf("Expected Output: _!<80 5 EC\n");
	a = createPatient("_!<80", 5, "EC");
	insertSortedQueue(q, a, 5);	
	printf("Actual Output:\n");
	printForward(q->list);
	printf("\n"); 

	/*Tests an empty string ""*/
	printf("Expected Output: 1 CV\n");
	a = createPatient("", 1, "CV");
	insertSortedQueue(q, a, 1);	
	printf("Actual Output:\n");
	printForward(q->list);
	printf("\n");

	/*Send a character as priority value and ASCI value is interpreted */
	printf("Expected Output: A 98 RC\n");
	a = createPatient("A", 'b', "RC");
	insertSortedQueue(q, a, 'b');	
	printf("Actual Output:\n");
	printForward(q->list);
	printf("\n"); 

 	/* Tests printing forward and back */
	printf("List printed forwards:\n");
	printForward(q->list);
	printf("\n");
	printf("List printed backwards:\n");
	printBackwards(q->list);
	printf("\n");

	/* Tests Enqueue */
	printf("Expected tail node after Enqueue: Z 1 SA\n");
	a = createPatient("Z", 1, "SA");
	Enqueue(q, a, 1);	
	printf("Actual Output:\n");
	printForward(q->list);
	printf("\n"); 


	return 0;
}


