# ER-priorityQueue

Student Information

Ryan Gundu
rgundu@uoguelph.ca

Program Description

- Wrapping a doubly linked list with a Queue
- Simulating the finish time of patients that arrive at a hospital 
- Finish time based on the patients symptom and priority


Important things to consider

- The program reads data from a file called "test.txt"

- The program outputs data to a file called "simulationOutput.txt"

- If patients are added after a simulation call has taken place, they are considered to have arrived after all the patients that have been already been processed

- As an addition the program will keep track and output the number of simulations 
that have been run  example: "Simulations run: 0"

- If a patient is added it is important to run the simulation or its finish time will not be set

- A random test file will be provided already inside "test.txt"

- If the simulation is run the output will be ordered, once the program ends by entering '3' it will output into the file in the order it was read/inputed

- if you exit the program with anything other than '3' it will not create the output file


To run the program

- To run the test main run "make" , and then "make runTest" , this runs the 
line "./bin/runTest"

- To run the actual main run "make" and then "make run" , this will run 
the line "./bin/runMe test.txt" which includes the name of the file it reads from
