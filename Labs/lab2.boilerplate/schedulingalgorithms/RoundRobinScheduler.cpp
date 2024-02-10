#include "RoundRobinScheduler.h"
#include <iostream>
#include <map> // Include necessary header for std::map
#include <algorithm> // Include necessary header for std::min

RoundRobinScheduler::RoundRobinScheduler(std::queue<Process> proc, int quantum)
    : timeQuantum(quantum), averageWaitTime(0.0f), averageTurnAroundTime(0.0f), initialProcessCount(proc.size()) {
    // Initialize the processes queue
    processes = proc;
}

void RoundRobinScheduler::schedule() {
    int currentTime = 0, totalWaitTime = 0, totalTurnAroundTime = 0;
    std::map<int, int> remainingBurstTime; // Declare remainingBurstTime here

    // Initialize remainingBurstTime map
    while (!processes.empty()) {
        const Process& process = processes.front();
        remainingBurstTime[process.id] = process.burstTime;
        processes.pop();
    }

    // Main scheduling loop
    while (!remainingBurstTime.empty()) {
        for (auto it = remainingBurstTime.begin(); it != remainingBurstTime.end();) {
            int executionTime = std::min(timeQuantum, it->second);
            currentTime += executionTime;
            it->second -= executionTime;

            if (it->second <= 0) {
                totalTurnAroundTime += currentTime; // Update totalTurnAroundTime
                it = remainingBurstTime.erase(it); // Process completed, remove from map
            } else {
                ++it; // Move to the next process
            }
        }
    }

    // Calculate totalWaitTime
    totalWaitTime = totalTurnAroundTime - initialProcessCount;

    // Calculate averages based on the initial count of processes
    averageWaitTime = static_cast<float>(totalWaitTime) / initialProcessCount;
    averageTurnAroundTime = static_cast<float>(totalTurnAroundTime) / initialProcessCount;
}

void RoundRobinScheduler::calculateAverageWaitTime() {
    std::cout << "Average Wait Time: " << averageWaitTime << std::endl;
}

void RoundRobinScheduler::calculateAverageTurnAroundTime() {
    std::cout << "Average Turnaround Time: " << averageTurnAroundTime << std::endl;
}
