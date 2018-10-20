#ifndef SIM
#define SIM

#include "../include/queue.h"
#include "../include/patient.h"

/**
*Function used to calculate the Patients process time base on there symptom
*@param Patient *p
*@return time to process
*/
int checkTime(Patient *p);

/**
*Simulates each patietns finish time and prints it to an output file
*@param Queue *q - to identify the list to simulate
*@param FILE *fptr - the file to output information to
*@param int time - the time in the simulation
*@return returns time to constantly add to the same value
*/
Queue *simulation (Queue *q, int numPatients);


#endif

