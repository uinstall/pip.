#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
using namespace std;

// Number of philosophers
const int NUM_PHILOSOPHERS = 5;

// Mutexes representing forks
vector<mutex> forks(NUM_PHILOSOPHERS);

// Function for a philosopher's actions
void philosopher(int id) {
    int leftFork = id;                   // Left fork is the same as philosopher ID
    int rightFork = (id + 1) % NUM_PHILOSOPHERS; // Right fork is next in the circle

    for (int i = 0; i < 3; ++i) { // Each philosopher eats 3 times
        // Thinking
        cout << "Philosopher " << id << " is thinking.\n";
        this_thread::sleep_for(chrono::milliseconds(100 + rand() % 200));

        // Picking up forks
        // To avoid deadlock, pick the lower-numbered fork first
        if (id % 2 == 0) {
            forks[leftFork].lock();
            cout << "Philosopher " << id << " picked up left fork " << leftFork << ".\n";
            forks[rightFork].lock();
            cout << "Philosopher " << id << " picked up right fork " << rightFork << ".\n";
        } else {
            forks[rightFork].lock();
            cout << "Philosopher " << id << " picked up right fork " << rightFork << ".\n";
            forks[leftFork].lock();
            cout << "Philosopher " << id << " picked up left fork " << leftFork << ".\n";
        }

        // Eating
        cout << "Philosopher " << id << " is eating.\n";
        this_thread::sleep_for(chrono::milliseconds(100 + rand() % 200));

        // Putting down forks
        forks[leftFork].unlock();
        cout << "Philosopher " << id << " put down left fork " << leftFork << ".\n";
        forks[rightFork].unlock();
        cout << "Philosopher " << id << " put down right fork " << rightFork << ".\n";
    }
}

int main() {
    // Seed for random number generation
    srand(time(0));

    // Create threads for each philosopher
    vector<thread> philosophers;
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers.push_back(thread(philosopher, i));
    }

    // Wait for all threads to finish
    for (auto& t : philosophers) {
        t.join();
    }

    cout << "All philosophers are done.\n";
    return 0;
}

