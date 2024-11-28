
//Bully algorithm


#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;

class Process {
public:
    int id; // Unique identifier for the process
    bool isCoordinator; // Flag to indicate if this process is the coordinator
    bool isAlive; // Flag to simulate process failure
    vector<Process*> processes; // List of processes connected to this one (neighbors in the ring)

    // Constructor to initialize the process with an ID
    Process(int id) : id(id), isCoordinator(false), isAlive(true) {}

    // Add other processes to the current process (neighbors in the ring)
    void addProcess(Process* p) {
        processes.push_back(p); // Add the given process to the list of neighbors
    }

    // Simulate process failure
    void fail() {
        isAlive = false; // Mark the process as failed
        cout << "Process " << id << " has failed." << endl; // Print that the process has failed
    }

    // Start the election process to find the coordinator
    void startElection() {
        cout << "Process " << id << " starts election." << endl; // Print that the process starts the election
        bool foundHigher = false; // Flag to check if a higher-ID process exists

        // Notify all higher-ID processes to start their own election
        for (Process* p : processes) {
            if (p->id > id && p->isAlive) { // If a higher-ID process is found
                foundHigher = true; // Set the flag to true
                p->startElection(); // Start the election on the higher-ID process
            }
        }

        // If no higher-ID process was found, the current process becomes the coordinator
        if (!foundHigher) {
            electCoordinator(); // Elect the current process as coordinator
        }
    }

    // Elect the current process as the coordinator
    void electCoordinator() {
        isCoordinator = true; // Mark the process as the coordinator
        cout << "Process " << id << " is the new coordinator!" << endl; // Print the new coordinator
        // Inform all other processes that this process is the coordinator
        for (Process* p : processes) {
            if (p->id != id) {
                p->isCoordinator = false; // Set all other processes as not the coordinator
            }
        }
    }

    // Display the status of the process (whether it's alive and if it's the coordinator)
    void displayStatus() {
        cout << "Process " << id; // Print the process ID
        if (isCoordinator) {
            cout << " is the coordinator."; // Print if the process is the coordinator
        }
        if (!isAlive) {
            cout << " has failed."; // Print if the process has failed
        }
        cout << endl; // Print a newline for formatting
    }
};

int main() {
    // Create processes with unique IDs
    Process p1(1), p2(2), p3(3), p4(4);

    // Adding other processes to each process (form the ring structure)
    p1.addProcess(&p2); // p1 is connected to p2, p3, and p4
    p1.addProcess(&p3);
    p1.addProcess(&p4);

    p2.addProcess(&p1); // p2 is connected to p1, p3, and p4
    p2.addProcess(&p3);
    p2.addProcess(&p4);

    p3.addProcess(&p1); // p3 is connected to p1, p2, and p4
    p3.addProcess(&p2);
    p3.addProcess(&p4);

    p4.addProcess(&p1); // p4 is connected to p1, p2, and p3
    p4.addProcess(&p2);
    p4.addProcess(&p3);

    // Simulate a failure in process 2
    p2.fail(); // Process 2 is marked as failed

    // Start the election from process 1
    p1.startElection(); // Process 1 starts the election

    // Display the final status of all processes (alive or failed, and if they are the coordinator)
    p1.displayStatus(); // Display the status of process 1
    p2.displayStatus(); // Display the status of process 2
    p3.displayStatus(); // Display the status of process 3
    p4.displayStatus(); // Display the status of process 4

    return 0; // End of the program
}

/*


Process 1 (p1) starts the election.
Process 2 (p2) fails, so it's skipped.
Process 3 (p3) and Process 4 (p4) continue the election.
Process 4, being the highest-ID process, becomes the coordinator.
The status of each process is displayed, showing that Process 4 is the coordinator, and Process 2 has failed.
In essence, this is the Bullying Algorithm: processes with higher IDs take over the election until the one with the highest ID is elected as the leader or coordinator.

*/




