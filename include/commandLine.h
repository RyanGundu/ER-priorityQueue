#include "../include/queue.h"
#include "../include/printToFile.h"

/**
*The main loop to promt the user of 3 options
*@param Queue *q to identify the list
*@param char *text used for users choice (reused to save memory)
*@param int numPatients - the number of patients
*/
void commandLine (Queue *q, Queue *x, int numPatients);

/**
*Allows the user to add a new patient to the list
*@param Queue *q to identify the ordered list
*@param Queue *q to identify the unordered list
*@param char *text used for ID name (reused to save memory)
*/
void addPatient(Queue *q, Queue *x);

/**
*Identifies if the user inputs a valid symptom code
*@param the users inputted symptom
*@return returns 0 if valid symptom and 1 if invalid
*/
int checkSymptom(char symptom[]);

/**
*Checks if the entered priority 
*@param user inputed symptom
*@return returns 0 if valid priority and 1 if invalid
*/
int checkPriority(char priority[]);

/**
*Function to remove a trailing hard return if stored in string
*@param char line[] - the string to check
*/
void removeTrailingHardReturn(char line[]);


