//Ring algorithm 

#include <iostream>
#include <vector>

using namespace std;

class Process {//created a class process ; class consistes of various attributes
public:
    int id;  // since every process has a unique id(identifier)
    bool isCoordinator;  // Flag to find out whether  node/ process is the coordinator
    bool isAlive;  // Flag to find out whether the process is alive or has failed
    Process* next;  // Pointer to the next process/node forming the ring structure

    // Constructor to initialize process with an ID
    Process(int id) : id(id), isCoordinator(false), isAlive(true), next(nullptr) {}

    // Connect this process to the next process in the ring
    void connectToNext(Process* p) {
        next = p;  // Set the next process pointer to the provided process
    }

    // Simulate failure of the process
    void fail() {
        isAlive = false;  // Mark the process as failed (not alive)
        cout << "Process " << id << " has failed." << endl;  // Print that the process has failed
    }

    // Start the election process to find the coordinator
    void startElection() {
        if (!isAlive) return;  // If the process has failed, do not start the election

        cout << "Process " << id << " starts election." << endl;  // Print that the process is starting the election

        Process* current = this;  // Start the election with the current process
        int highestId = id;  // Initialize the highest ID as the current process's ID
        Process* highestProcess = this;  // Set the highest process to the current process

        // Passing the election message around the ring
        do {
            current = current->next;  // Move to the next process in the ring
            if (current->isAlive && current->id > highestId) {  // If the next process is alive and has a higher ID
                highestId = current->id;  // Update the highest ID
                highestProcess = current;  // Update the highest process
            }
        } while (current != this);  // Continue looping until we complete one full cycle around the ring

        // After one complete cycle, elect the process with the highest ID as coordinator
        highestProcess->isCoordinator = true;  // Mark the highest process as the coordinator
        cout << "Process " << highestProcess->id << " is the new coordinator!" << endl;  // Print the new coordinator
    }

    // Display the status of the process
    void displayStatus() {
        cout << "Process " << id;  // Print the process ID
        if (isCoordinator) {  // If this process is the coordinator
            cout << " is the coordinator.";  // Print that it is the coordinator
        }
        if (!isAlive) {  // If this process has failed
            cout << " has failed.";  // Print that the process has failed
        }
        cout << endl;  // Print a newline for better formatting
    }
};

int main() {
    // Creating processes with unique IDs
    Process p1(1), p2(2), p3(3), p4(4);

    // Connecting processes in a ring (circular connection)
    p1.connectToNext(&p2);  // p1 points to p2
    p2.connectToNext(&p3);  // p2 points to p3
    p3.connectToNext(&p4);  // p3 points to p4
    p4.connectToNext(&p1);  // p4 points back to p1, completing the ring

    // Simulate process failure
    p2.fail();  // Mark process 2 as failed

    // Start the election from process 1
    p1.startElection();  // Process 1 starts the election process

    // Display the final status of each process (whether alive and if coordinator)
    p1.displayStatus();  // Display status of process 1
    p2.displayStatus();  // Display status of process 2
    p3.displayStatus();  // Display status of process 3
    p4.displayStatus();  // Display status of process 4

    return 0;  // End of the program
}

/*

Here's a concise explanation of the Ring Algorithm logic:

Initialization: One process (any process) starts the election by sending a message with its own ID to the next process in the ring.

Message Passing: Each process compares its own ID with the ID in the election message:

If its ID is higher, it replaces the ID in the message and sends it forward.
If its ID is lower, it simply forwards the message without changes.
Complete the Circle: The message continues around the ring until it reaches the process that started the election.

Election Completion: The process that receives the message with the highest ID becomes the new coordinator (leader).

Fault Tolerance: If a process fails, the election continues without it, as the message will just skip over the failed process.

This ensures that the process with the highest ID in the system is elected as the coordinator.


*/



