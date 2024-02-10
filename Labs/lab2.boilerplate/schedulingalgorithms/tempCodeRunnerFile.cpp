#include "RoundRobinScheduler.h"
#include <iostream>
#include <queue>
#include <map>

// Assuming the Process class and other necessary includes are correctly set up
// Constructor and other class members are assumed to be defined elsewhere

void RoundRobinScheduler::schedule() {
    int currentTime = 0, totalWaitTime = 0, totalTurnAroundTime = 0;
    std::queue<Process> readyQueue; // Assuming this->processes is something we can iterate over to fill the queue
    std::map<int, int> remainingBurstTime;

    for (Process &process : this->processes) {
        readyQueue.push(process);
        remainingBurstTime[process.getID()] = process.getBurstTime();
    }

    while (!readyQueue.empty()) {
        Process process = readyQueue.front();
        readyQueue.pop();

        int waitTime = max(0, currentTime - process.getArrivalTime());
        totalWaitTime += waitTime;

        int executionTime = min(this->timeQuantum, remainingBurstTime[process.getID()]);
        currentTime += executionTime;
        remainingBurstTime[process.getID()] -= executionTime;

        if (remainingBurstTime[process.getID()] > 0) {
            readyQueue.push(process);
        } else {
            int turnaroundTime = currentTime - process.getArrivalTime();
            totalTurnAroundTime += turnaroundTime;
        }
    }

    this->averageWaitTime = static_cast<float>(totalWaitTime) / this->processes.size();
    this->averageTurnAroundTime = static_cast<float>(totalTurnAroundTime) / this->processes.size();
}

void RoundRobinScheduler::calculateAverageWaitTime() {
    std::cout << "Average Wait Time: " << this->averageWaitTime << std::endl;
}

void RoundRobinScheduler::calculateAverageTurnAroundTime() {
    std::cout << "Average Turnaround Time: " << this->averageTurnAroundTime << std::endl;
}
