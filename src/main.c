#include "../include/LinkedListAPI.h"
#include "../include/queue.h"
#include "../include/simulationA2.h"
#include "../include/patient.h"
#include "../include/commandLine.h"
#include "../include/printToFile.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
*function prompts user for a valid fileName if an invalid one is given 
*/
FILE* myOpenforReading (char fileName[]) {
	FILE* fileptr; 
	char newFile[50];
	fileptr = fopen(fileName, "r");
	if (fileptr == NULL) {
      	printf("Could not open file %s.\n",fileName);
      	printf("Please enter a new file name:\n");
      	scanf("%s",newFile);
      	fileptr = myOpenforReading(newFile);
      return fileptr; 
   }
   return fileptr;
}

int main (int arg, char *argv[]) {

	FILE *fptr = NULL;
	fptr = myOpenforReading( argv[1] );
	

	char *text = malloc(sizeof(char) * 30);


	char *id;
	int priority = 0;
	char *symptom;
	int numPatients = 0;

	Queue *q = createQueue(&printNode, &deleteNode, &compare);
	Queue *x = createQueue(&printNode, &deleteNode, &compare);

	/* Reads from the file line by line */
	while ( fgets ( text, 30, fptr ) ) {
		id = malloc(sizeof(char) * 50);
		symptom = malloc(sizeof(char) * 3);

		removeTrailingHardReturn(text);
		sscanf(text, "%s %d %s",id, &priority, symptom);

		Patient *a = createPatient(id, priority, symptom);
		insertSortedQueue(q, a, priority);	
		Enqueue(x, a, priority);
		++numPatients;

	} 

	commandLine(q, x, numPatients);
	free(text);
	deleteQueue(q);
	fclose(fptr);

	return 0;
}
