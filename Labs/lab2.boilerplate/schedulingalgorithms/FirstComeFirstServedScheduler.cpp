#include "FirstComeFirstServedScheduler.h"
#include <iostream>

// Constructor
FirstComeFirstServedScheduler::FirstComeFirstServedScheduler(queue<Process> processes, int quantum) {
    int currentTime = 0;
    int totalWaitTime = 0;
    int totalTurnAroundTime = 0;
    queue<Process> tempQueue = processes; // Copy of the original queue

    while (!tempQueue.empty()) {
        Process& process = tempQueue.front();
        process.waitTime = max(0, currentTime - process.arrivalTime);
        totalWaitTime += process.waitTime;

        // Calculate turnaround time for each process
        int turnaroundTime = process.waitTime + process.burstTime;
        totalTurnAroundTime += turnaroundTime;

        // Update the current time for the next process
        currentTime += process.burstTime;
        tempQueue.pop(); // Move to the next element
    }

    averageWaitTime = static_cast<float>(totalWaitTime) / processes.size();
    averageTurnAroundTime = static_cast<float>(totalTurnAroundTime) / processes.size();
}

// Override schedule function
void FirstComeFirstServedScheduler::schedule() {
    // Implement scheduling logic here
}

// Override calculateAverageWaitTime function
void FirstComeFirstServedScheduler::calculateAverageWaitTime() {
    cout << "Average Wait Time: " << averageWaitTime << endl;
}

// Override calculateAverageTurnAroundTime function
void FirstComeFirstServedScheduler::calculateAverageTurnAroundTime() {
    cout << "Average Turnaround Time: " << averageTurnAroundTime << endl;
}
