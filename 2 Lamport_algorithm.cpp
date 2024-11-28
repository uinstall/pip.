#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the maximum of two integers
int findMax(int a, int b) {
    return (a > b) ? a : b; // Return the larger of the two numbers
}

// Function to display timestamps and the order of events
void displayTimestamps(vector<int>& p1, vector<int>& p2) {
    // Display timestamps for events in Process 1 (P1)
    cout << "\nLogical Timestamps of Events:\n";
    cout << "Process 1 (P1): ";
    for (int i = 0; i < p1.size(); i++) {
        cout << "E1_" << i + 1 << " (" << p1[i] << ") "; // Display event E1_i with its timestamp
    }

    // Display timestamps for events in Process 2 (P2)
    cout << "\nProcess 2 (P2): ";
    for (int i = 0; i < p2.size(); i++) {
        cout << "E2_" << i + 1 << " (" << p2[i] << ") "; // Display event E2_i with its timestamp
    }

    // Display the causal order of events based on their timestamps
    cout << "\n\nCausal Order of Events (Ascending Timestamps):\n";

    // Combine events from both processes with their timestamps into a vector
    vector<pair<int, string>> events;
    for (int i = 0; i < p1.size(); i++) {
        events.emplace_back(p1[i], "E1_" + to_string(i + 1)); // Add P1 events with timestamps
    }
    for (int i = 0; i < p2.size(); i++) {
        events.emplace_back(p2[i], "E2_" + to_string(i + 1)); // Add P2 events with timestamps
    }

    // Sort the events by their timestamps
    sort(events.begin(), events.end());

    // Display the sorted events in causal order
    for (auto& event : events) {
        cout << event.second << " (Timestamp: " << event.first << ") ";
    }
    cout << endl;
}

// Function to calculate timestamps and determine event order
void lamportLogicalClock(vector<int>& p1, vector<int>& p2, vector<vector<int>>& dependencyMatrix) {
    int e1 = p1.size(); // Number of events in Process 1
    int e2 = p2.size(); // Number of events in Process 2

    // Iterate over the dependency matrix to calculate timestamps
    for (int i = 0; i < e1; i++) { // Loop over events in P1
        for (int j = 0; j < e2; j++) { // Loop over events in P2
            if (dependencyMatrix[i][j] == 1) { // If P1's event depends on P2's event
                p1[i] = findMax(p1[i], p2[j] + 1); // Update timestamp for the P1 event
            } else if (dependencyMatrix[i][j] == -1) { // If P2's event depends on P1's event
                p2[j] = findMax(p2[j], p1[i] + 1); // Update timestamp for the P2 event
            }
        }
    }

    // Display the timestamps and causal order
    displayTimestamps(p1, p2);
}

int main() {
    // Number of events in each process
    int e1 = 3, e2 = 3; // P1 and P2 both have 3 events each

    // Initialize timestamps for all events in both processes to 1
    vector<int> p1(e1, 1); // P1 events initialized to 1
    vector<int> p2(e2, 1); // P2 events initialized to 1

    // Dependency matrix to define causal relationships
    // 1: Event in P1 depends on an event in P2
    // -1: Event in P2 depends on an event in P1
    // 0: No dependency
    vector<vector<int>> dependencyMatrix = {
        {0, 0, 0},  // E1_1 in P1 has no dependency
        {-1, 0, 0}, // E1_2 in P1 depends on E2_1 in P2
        {0, 1, 0}   // E1_3 in P1 depends on E2_2 in P2
    };

    // Print the dependency matrix for understanding
    cout << "Dependency Matrix:\n";
    for (const auto& row : dependencyMatrix) { // Loop through rows of the matrix
        for (int val : row) { // Loop through values in each row
            cout << val << " "; // Print the dependency value
        }
        cout << endl;
    }

    // Calculate timestamps and determine event order
    lamportLogicalClock(p1, p2, dependencyMatrix);

    return 0; // End of program
}

/*

Theory:
Lamport’s Logical Clock was created by Leslie Lamport. It is a procedure to determine the order of events occurring. It provides a basis for the more advanced Vector Clock Algorithm. Due to the absence of a Global Clock in a Distributed Operating System Lamport Logical Clock is needed.

Algorithm:

Happened before relation(->): a -> b, means ‘a’ happened before ‘b’.
Logical Clock: The criteria for the logical clocks are:
[C1]: Ci (a) < Ci(b), [ Ci -> Logical Clock, If ‘a’ happened before ‘b’, then time of ‘a’ will be less than ‘b’ in a particular process. ]
[C2]: Ci(a) < Cj(b), [ Clock value of Ci(a) is less than Cj(b) ]



[IR1]: If a -> b [‘a’ happened before ‘b’ within the same process] then, Ci(b)  =Ci(a) + d
[IR2]: Cj = max(Cj, tm + d) [If there’s more number of processes, then tm = value of Ci(a), Cj = max value between Cj and tm + d]

*/