#include "../include/queue.h"
#include "../include/simulationA2.h"
#include "../include/commandLine.h"
#include "../include/patient.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>


void commandLine (Queue *q, Queue *x, int numPatients) {

	FILE* fptr = NULL;
	int i = 0;
	char *text = malloc(sizeof(char) * 30);	
	while (1) {
		printf("\n");
		printf("Enter an option (1,2,3)\n");
		printf("-----------------------\n");
		printf("Simulations run: %d\n", i);
		printf("1) Add a new patient \n");
		printf("2) Run the simulation \n");
		printf("3) Exit \n");
		printf("Option: ");	
		fgets (text, 10, stdin);
		removeTrailingHardReturn(text);
		if (text[0] == '1') {
			addPatient(q, x);
			++numPatients;
		}
		else if (text[0] == '2') {
			q = simulation(q, numPatients);
			++i;
		} 
		else if (text[0] == '3') {
			printToFile(x, fptr, numPatients);
			break;
			
		} else {
			break;
		}
	} 
	free(text);

	
}

void addPatient(Queue *q, Queue *x) {

	Patient *p = NULL;
	char *symptom = malloc(sizeof(char) * 3);
	int priority;
	char prty[10];

	char *text = malloc(sizeof(char) * 30);	
	printf("Enter an ID: ");
	fgets ( text, 50, stdin );
	removeTrailingHardReturn(text);

	do {
	printf("Enter a symptom: ");
	fgets ( symptom, 10, stdin );
	removeTrailingHardReturn(symptom);
	symptom[0] = toupper(symptom[0]);
	symptom[1] = toupper(symptom[1]);

	} while (checkSymptom(symptom) == 1);

	do {
	printf("Enter a priority: ");
	fgets (prty, 10, stdin );
	removeTrailingHardReturn(prty);
	} while (checkPriority(prty) == 1);
	priority = atoi(prty);
	p = createPatient(text, priority, symptom);
	insertSortedQueue(q, p, priority);
	Enqueue(x, p, priority);

}

int checkSymptom(char symptom[]) {

	char syms[11][3];
	strcpy(syms[0],"CV");
	strcpy(syms[1],"HN");
	strcpy(syms[2],"EV");
	strcpy(syms[3],"GI");
	strcpy(syms[4],"MH");
	strcpy(syms[5],"NC");
	strcpy(syms[6],"EC");
	strcpy(syms[7],"RC");
	strcpy(syms[8],"SK");
	strcpy(syms[9],"SA");
	strcpy(syms[10],"TR");
	for (int i = 0; i < 11; ++i) {
		if (strcmp(syms[i],symptom) == 0)
			return 0;
	}

	return 1;
}

int checkPriority(char priority[]) {

	char prty[5] = "12345";

	for (int i=0; i < 5; ++i) {
		if (priority[0] == prty[i] && strlen(priority) == 1)
			return 0;
	}
	return 1;
}

void removeTrailingHardReturn(char line[]) {

   if (line[strlen(line)-1] == '\n')
   {
      line[strlen(line)-1] = '\0';
   }
   return;
}

