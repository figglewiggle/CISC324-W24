#include "RoundRobinScheduler.h"
#include <iostream>
#include <queue>
#include <map>
#include <algorithm> // For std::min and std::max

void RoundRobinScheduler::schedule() {
    int currentTime = 0, totalWaitTime = 0, totalTurnAroundTime = 0;
    std::queue<Process> readyQueue = this->processes; // Copy of the processes queue
    std::map<int, int> remainingBurstTime;

    // No direct range-based for loop over std::queue, so we initialize remainingBurstTime differently
    std::queue<Process> tempQueue = readyQueue; // Temporary queue for iteration
    while (!tempQueue.empty()) {
        const Process& process = tempQueue.front();
        remainingBurstTime[process.id] = process.burstTime; // Direct access to Process fields
        tempQueue.pop();
    }

    // Main scheduling loop
    while (!readyQueue.empty()) {
        Process process = readyQueue.front();
        readyQueue.pop();

        // Assume each process must at least be executed for a 'timeQuantum' or until completion
        int executionTime = std::min(this->timeQuantum, remainingBurstTime[process.id]);
        remainingBurstTime[process.id] -= executionTime;
        currentTime += executionTime;

        if (remainingBurstTime[process.id] > 0) {
            readyQueue.push(process); // Process not completed, re-queue
        } else {
            // Process completed, calculate its total time and wait time
            totalTurnAroundTime += currentTime - process.arrivalTime;
        }

        // Wait time for each process is current time minus its arrival time and total burst time up to now
        totalWaitTime += currentTime - process.arrivalTime - (process.burstTime - remainingBurstTime[process.id]);
    }

    // Calculate averages based on the initial count of processes
    this->averageWaitTime = static_cast<float>(totalWaitTime) / this->initialProcessCount;
    this->averageTurnAroundTime = static_cast<float>(totalTurnAroundTime) / this->initialProcessCount;
}

void RoundRobinScheduler::calculateAverageWaitTime() {
    std::cout << "Average Wait Time: " << this->averageWaitTime << std::endl;
}

void RoundRobinScheduler::calculateAverageTurnAroundTime() {
    std::cout << "Average Turnaround Time: " << this->averageTurnAroundTime << std::endl;
}
