CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -c -Iinclude

all: bin/main bin/testMain

bin/LinkedListAPI.o: src/LinkedListAPI.c
	$(CC) $(CFLAGS) src/LinkedListAPI.c -o bin/LinkedListAPI.o

bin/queue.o: src/queue.c
	$(CC) $(CFLAGS) src/queue.c -o bin/queue.o

bin/patient.o: src/patient.c
	$(CC) $(CFLAGS) src/patient.c -o bin/patient.o

bin/commandLine.o: src/commandLine.c
	$(CC) $(CFLAGS) src/commandLine.c -o bin/commandLine.o

bin/simulationA2.o: src/simulationA2.c
	$(CC) $(CFLAGS) src/simulationA2.c -o bin/simulationA2.o

bin/printToFile.o: src/printToFile.c
	$(CC) $(CFLAGS) src/printToFile.c -o bin/printToFile.o

bin/main.o: src/main.c
	$(CC) $(CFLAGS) src/main.c -o bin/main.o

bin/main: bin/main.o bin/LinkedListAPI.o bin/simulationA2.o bin/queue.o bin/patient.o bin/commandLine.o bin/printToFile.o
	$(CC) bin/main.o bin/LinkedListAPI.o bin/simulationA2.o bin/queue.o bin/patient.o bin/commandLine.o bin/printToFile.o -o bin/runMe 

bin/testMain.o: src/testMain.c
	$(CC) $(CFLAGS) src/testMain.c -o bin/testMain.o 

bin/testMain: bin/testMain.o bin/queue.o bin/patient.o bin/LinkedListAPI.o bin/simulationA2.o bin/commandLine.o bin/printToFile.o
	$(CC) bin/testMain.o bin/queue.o bin/patient.o bin/LinkedListAPI.o bin/simulationA2.o bin/commandLine.o bin/printToFile.o -o bin/runTest

run:
	./bin/runMe test.txt

runTest:
	./bin/runTest

clean:
	rm bin/*.o
	rm bin/runMe
	rm bin/runTest
	
