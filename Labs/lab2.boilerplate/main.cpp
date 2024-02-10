#include <iostream>
#include <queue>
#include <ctime> // Include this header for time()
#include <vector>
#include <ctime>
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
    int timeQuantum_tc1_2 = 2;
    int timeQuantum_tc3_4 = 4;

    // Test Case #1: Using First-Come-First-Served Scheduler
    cout << "###############################################\n";
    cout << "##### TEST CASE #1: First Come First Served Scheduler #####" << endl;
    scheduler = new FirstComeFirstServedScheduler(processes_tc1, 0);
    scheduler->schedule();
    scheduler->calculateAverageWaitTime();
    scheduler->calculateAverageTurnAroundTime();
    delete scheduler; // Clean up
    cout << "###############################################\n";

    // Test Case #1: Using Round Robin Scheduler
    cout << "##### TEST CASE #1: Round Robin Scheduler + time quantum = 2 #####" << endl;
    scheduler = new RoundRobinScheduler(processes_tc1, timeQuantum_tc1_2); // Time quantum of 2
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
    cout << "##### TEST CASE #2: Round Robin Scheduler + time quantum = 2 #####" << endl;
    scheduler = new RoundRobinScheduler(processes_tc2, timeQuantum_tc1_2); // Time quantum of 2
    scheduler->schedule();
    scheduler->calculateAverageWaitTime();
    scheduler->calculateAverageTurnAroundTime();
    delete scheduler; // Clean up
    cout << "###############################################\n";

    // Test Case #3: Using First-Come-First-Served Scheduler
    cout << "##### TEST CASE #3: First Come First Served Scheduler #####" << endl;
    scheduler = new FirstComeFirstServedScheduler(processes_tc1, 0);
    scheduler->schedule();
    scheduler->calculateAverageWaitTime();
    scheduler->calculateAverageTurnAroundTime();
    delete scheduler; // Clean up
    cout << "###############################################\n";

    // Test Case #3: Using Round Robin Scheduler
    cout << "##### TEST CASE #3: Round Robin Scheduler + time quantum = 4 #####" << endl;
    scheduler = new RoundRobinScheduler(processes_tc1, timeQuantum_tc3_4); // Time quantum of 2
    scheduler->schedule();
    scheduler->calculateAverageWaitTime();
    scheduler->calculateAverageTurnAroundTime();
    delete scheduler; // Clean up
    cout << "###############################################\n";

    // Test Case #4: Using First-Come-First-Served Scheduler
    cout << "##### TEST CASE #4: First Come First Served Scheduler #####" << endl;
    scheduler = new FirstComeFirstServedScheduler(processes_tc2, 0);
    scheduler->schedule();
    scheduler->calculateAverageWaitTime();
    scheduler->calculateAverageTurnAroundTime();
    delete scheduler; // Clean up
    cout << "###############################################\n";

    // Test Case #4: Using Round Robin Scheduler
    cout << "##### TEST CASE #4: Round Robin Scheduler + time quantum = 4 #####" << endl;
    scheduler = new RoundRobinScheduler(processes_tc2, timeQuantum_tc3_4); // Time quantum of 2
    scheduler->schedule();
    scheduler->calculateAverageWaitTime();
    scheduler->calculateAverageTurnAroundTime();
    delete scheduler; // Clean up
    cout << "###############################################\n";

    return 0;
}
