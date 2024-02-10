#include "FirstComeFirstServedScheduler.h"
#include <iostream>
#include <queue>
#include <algorithm> // For std::max

void FirstComeFirstServedScheduler::schedule() {
    int currentTime = 0;
    int totalWaitTime = 0;
    int totalTurnAroundTime = 0;
    std::queue<Process> tempQueue = processes; // Copy of the original queue

    while (!tempQueue.empty()) {
        Process& process = tempQueue.front();
        process.waitTime = std::max(0, currentTime - process.arrivalTime);
        totalWaitTime += process.waitTime;

        // Calculate turnaround time for each process
        int turnaroundTime = process.waitTime + process.burstTime;
        totalTurnAroundTime += turnaroundTime;

        // Update the current time for the next process
        currentTime += process.burstTime;
        tempQueue.pop(); // Move to the next element
    }

    averageWaitTime = static_cast<float>(totalWaitTime) / processes.size(); // You may need to adjust this logic
    averageTurnAroundTime = static_cast<float>(totalTurnAroundTime) / processes.size(); // Adjust as per actual implementation
}

void FirstComeFirstServedScheduler::calculateAverageWaitTime() {
    std::cout << "Average Wait Time: " << averageWaitTime << std::endl;
}

void FirstComeFirstServedScheduler::calculateAverageTurnAroundTime() {
    std::cout << "Average Turnaround Time: " << averageTurnAroundTime << std::endl;
}
