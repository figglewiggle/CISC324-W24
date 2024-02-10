#ifndef FIRSTCOMEFIRSTSERVEDSCHEDULER_H
#define FIRSTCOMEFIRSTSERVEDSCHEDULER_H

#include <queue>
#include "Process.h"
#include "CPUScheduler.h"
using namespace std;

class FirstComeFirstServedScheduler : public CPUScheduler {
private:
    queue<Process> processes; // To store processes
    float averageWaitTime; // To store the average wait time
    float averageTurnAroundTime; // To store the average turnaround time

public:
    FirstComeFirstServedScheduler(queue<Process> processes, int quantum); // Assuming quantum is ignored for FCFS
    void schedule() override;
    void calculateAverageWaitTime() override;
    void calculateAverageTurnAroundTime() override;
    // Additional methods to access the calculated averages might be necessary
};

#endif // FIRSTCOMEFIRSTSERVEDSCHEDULER_H
