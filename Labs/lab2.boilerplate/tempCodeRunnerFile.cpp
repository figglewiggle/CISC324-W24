#include <iostream>
#include <queue>
#include <vector>
#include "schedulingalgorithms/CPUScheduler.h"
#include "schedulingalgorithms/FirstComeFirstServedScheduler.h"
#include "schedulingalgorithms/RoundRobinScheduler.h"
#include "schedulingalgorithms/Process.h"

using namespace std;

// Generate random processes with different arrival times
queue<Process> generateProcesses(int numberOfProcesses) {
    queue<Process> processes;
    for (int i = 0; i < numberOfProcesses; i++) {
        // Generating random burst and arrival times for each process
        processes.push(Process(i + 1, rand() % 10 + 1, rand() % 10));
    }
    return processes;
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    CPUScheduler *scheduler;

    // Init processes for two test cases
    queue<Process> processes_tc1 = generateProcesses(5);
    queue<Process> processes_tc2 = generateProcesses(10);

    // Test Case #1: Using First-Come-First-Served Scheduler
    cout << "##### TEST CASE #1: First Come First Served Scheduler #####" << endl;
    scheduler = new FirstComeFirstServedScheduler(processes_tc1, 0);
    scheduler->schedule();
    scheduler->calculateAverageWaitTime();
    scheduler->calculateAverageTurnAroundTime();
    delete scheduler; // Clean up
    cout << "###############################################\n";

    // Test Case #1: Using Round Robin Scheduler
    cout << "##### TEST CASE #1: Round Robin Scheduler #####" << endl;
    scheduler = new RoundRobinScheduler(processes_tc1, 2); // Time quantum of 2
    scheduler->schedule();
    scheduler->calculateAverageWaitTime();
    scheduler->calculateAverageTurnAroundTime();
    delete scheduler; // Clean up
    cout << "###############################################\n";

    // Test Case #2: Using First-Come-First-Served Scheduler
    cout << "##### TEST CASE #2: First Come First Served Scheduler #####" << endl;
    scheduler = new FirstComeFirstServedScheduler(processes_tc2, 0);
    scheduler->schedule();
    scheduler->calculateAverageWaitTime();
    scheduler->calculateAverageTurnAroundTime();
    delete scheduler; // Clean up
    cout << "###############################################\n";

    // Test Case #2: Using Round Robin Scheduler
    cout << "##### TEST CASE #2: Round Robin Scheduler #####" << endl;
    scheduler = new RoundRobinScheduler(processes_tc2, 2); // Time quantum of 2
    scheduler->schedule();
    scheduler->calculateAverageWaitTime();
    scheduler->calculateAverageTurnAroundTime();
    delete scheduler; // Clean up
    cout << "###############################################\n";

    return 0;
}
