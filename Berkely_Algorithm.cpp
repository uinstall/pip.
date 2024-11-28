#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to calculate average clock time
void berkeleyAlgorithm(vector<int>& clocks) {
    int serverTime = clocks[0];
    int n = clocks.size();
    int sum = 0;

    // Compute offsets from server clock
    vector<int> offsets(n);
    for (int i = 0; i < n; ++i) {
        offsets[i] = clocks[i] - serverTime;
        sum += offsets[i];
    }

    // Average offset
    int avgOffset = round((double)sum / n);

    // Adjust all clocks
    for (int i = 0; i < n; ++i) {
        clocks[i] -= avgOffset;
    }

    // Output the synchronized clocks
    cout << "Synchronized Clocks:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Clock " << i + 1 << ": " << clocks[i] << endl;
    }
}

int main() {
    // Example: Initial clocks (in seconds)
    vector<int> clocks = {120, 130, 115, 140}; // Server clock and clients' clocks
    cout << "Initial Clocks:\n";
    for (int i = 0; i < clocks.size(); ++i) {
        cout << "Clock " << i + 1 << ": " << clocks[i] << endl;
    }
    cout<<endl;
    cout<<"---------------------------------------------";
	cout<<endl;
	
    berkeleyAlgorithm(clocks);
    return 0;
}

