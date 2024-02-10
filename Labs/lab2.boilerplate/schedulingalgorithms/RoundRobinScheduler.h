#ifndef ROUNDROBINSCHEDULER_H
#define ROUNDROBINSCHEDULER_H

#include <queue>
#include <vector> // Consider including if you decide to use vector instead of queue
#include "Process.h"
#include "CPUScheduler.h"

class RoundRobinScheduler : public CPUScheduler {
private:
    std::queue<Process> processes; // Consider using std::vector<Process> for direct iteration
    int timeQuantum;
    float averageWaitTime;
    float averageTurnAroundTime;
    int initialProcessCount; // To store the original number of processes for average calculations

public:
    RoundRobinScheduler(std::queue<Process> proc, int quantum);
    void schedule() override;
    void calculateAverageWaitTime() override;
    void calculateAverageTurnAroundTime() override;
};

#endif // ROUNDROBINSCHEDULER_H
