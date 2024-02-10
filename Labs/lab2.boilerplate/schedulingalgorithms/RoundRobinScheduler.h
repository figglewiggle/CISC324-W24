#ifndef ROUNDROBINSCHEDULER_H
#define ROUNDROBINSCHEDULER_H

#include <queue>
#include <vector> // If you decide to store processes in a vector instead of a queue for easier iteration
#include "Process.h"
#include "CPUScheduler.h"

class RoundRobinScheduler : public CPUScheduler {
private:
    std::queue<Process> processes; // Use this if you want to stick with the queue
    // Alternatively, std::vector<Process> processes; if you prefer direct iteration
    int timeQuantum;
    float averageWaitTime;
    float averageTurnAroundTime;
    int initialProcessCount; // To store the original number of processes for average calculations

public:
    RoundRobinScheduler(std::queue<Process> proc, int quantum)
        : processes(proc), timeQuantum(quantum), averageWaitTime(0), averageTurnAroundTime(0) {
            initialProcessCount = processes.size(); // Initialize the process count
        }

    void schedule() override;
    void calculateAverageWaitTime() override;
    void calculateAverageTurnAroundTime() override;

    // Optional: Add getters for averageWaitTime and averageTurnAroundTime if needed
};

#endif // ROUNDROBINSCHEDULER_H
