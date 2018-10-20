#include "../include/patient.h"
#include <string.h>
#include <stdlib.h>

Patient *createPatient (char *id, int priority, char *symptom) {

	Patient *p = malloc(sizeof(Patient));
	p->ID = malloc(sizeof(strlen(id) + 1));
	p->symptom = malloc(sizeof(strlen(symptom) + 1));

	p->ID = id;
	p->priority = priority;
	p->symptom = symptom;
	p->timeFinished = 0;

	return p;

}