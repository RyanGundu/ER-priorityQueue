#ifndef PAT
#define PAT

/**
*The struct or data that each patient holds
*an ID, priority value and symptom code
**/
typedef struct patient {

	char *ID;
	int priority;
	char *symptom;
	int timeFinished;

}Patient;

/**
*Creates a patient containing the data
*@param Patients ID (char)
*@param Patients priority number (int)
*@param Patients symptom code (char)
*@return returns the patient after assigned values
**/
Patient *createPatient (char *id, int priority, char symptom[]);

#endif
