#include "../include/simulationA2.h"
#include <stdio.h>

Queue *simulation (Queue *q, int numPatients) {


		int time = 0;

		char heading1[100] = "Patient ID";
		char heading2[100] = "Priority";
		char heading3[100] = "Symptom Code";
		char heading4[100] = "Time Finished";
		printf("%s %20s %20s %20s\n", heading1, heading2, heading3, heading4);
	

	Patient *p = NULL;
	Queue *temp = createQueue(&printNode, &deleteNode, &compare);
	Patient *tempPatient = NULL;

	int i = 0;
	int max_width = 0;

	while (i < numPatients) {

		p = (Patient *)peek(q); // gets first Node
		time += checkTime(p); //add the time it takes to process
		++time; // 1 second of paper work

		p->timeFinished = time;
		max_width = 25 - strlen(p->ID);
		if (max_width <= 0) 
			max_width = 20;
		printf("%s %*d %20s %20d\n", p->ID, max_width, p->priority, p->symptom, p->timeFinished);

		tempPatient = p;
		Dequeue(q);
		insertSortedQueue(temp, tempPatient, p->priority);
		++i;
	}

	return temp;

}

int checkTime(Patient *p) {

	if (strcmp(p->symptom, "CV") == 0 || strcmp(p->symptom, "MH") == 0 || strcmp(p->symptom, "NC") == 0) {
		return 5;
	}
	else if  (strcmp(p->symptom, "HN") == 0) {
		return 3;
	}
	else if (strcmp(p->symptom, "EV") == 0) {
		return 10;
	}
	else if (strcmp(p->symptom, "GI") == 0 || strcmp(p->symptom, "SK") == 0) {
		return 2;
	}
	else if (strcmp(p->symptom, "EC") == 0 || strcmp(p->symptom, "RC") == 0) {
		return 1;
	}
	else if (strcmp(p->symptom, "SA") == 0) {
		return 7;
	}
	else if (strcmp(p->symptom, "TR") == 0) {
		return 4;
	}

	return 0;

}

