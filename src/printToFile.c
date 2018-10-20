#include "../include/printToFile.h"

void printToFile (Queue *x, FILE *fptr, int numPatients) {


	fptr = fopen("simulationOutput.txt", "w");


	char heading1[100] = "Patient ID";
	char heading2[100] = "Priority";
	char heading3[100] = "Symptom Code";
	char heading4[100] = "Time Finished";
	fprintf(fptr, "%s %20s %20s %20s\n", heading1, heading2, heading3, heading4);

	Patient *p = NULL;
	int max_width = 0;
	int i = 0;
	while (i < numPatients) {
		p = (Patient *)peek(x);
		max_width = 25 - strlen(p->ID);
		if (max_width <= 0) 
			max_width = 20;

		fprintf(fptr, "%s %*d %20s %20d\n", p->ID, max_width, p->priority, p->symptom, p->timeFinished);
		Dequeue(x);
		++i;
	
	}
	fclose(fptr);
}

