#include <stdio.h>

int main() {
    // Declare variables
    int n;

    // Get the number of processes from the user
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Declare arrays to store process information
    int processId[n], arrivalTime[n], burstTime[n], completionTime[n], turnaroundTime[n], waitTime[n], isCompleted[n];

    // Get process details from the user
    printf("Enter process Id, arrival time, and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &processId[i], &arrivalTime[i], &burstTime[i]);
        isCompleted[i] = 0; // Initialize all processes as not completed
    }

    int currentTime = 0; // Initialize current time
    int completed = 0; // Initialize number of completed processes

    while (completed < n) {
        int shortestJob = -1;
        int shortestBurst = 999999; // Initialize with a very large value

        // Find the shortest job that has arrived and not completed yet
        for (int i = 0; i < n; i++) {
            if (arrivalTime[i] <= currentTime && isCompleted[i] == 0 && burstTime[i] < shortestBurst) {
                shortestBurst = burstTime[i];
                shortestJob = i;
            }
        }

        if (shortestJob == -1) {
            currentTime++; // If no process is available at the moment, move to the next unit of time
            continue;
        }

        // Mark the shortest job as completed
        isCompleted[shortestJob] = 1;
        completed++;

        // Update current time and completion time for the completed process
        currentTime += burstTime[shortestJob];
        completionTime[shortestJob] = currentTime;

        // Calculate turnaround time and wait time for the completed process
        turnaroundTime[shortestJob] = completionTime[shortestJob] - arrivalTime[shortestJob];
        waitTime[shortestJob] = turnaroundTime[shortestJob] - burstTime[shortestJob];
    }

    // Calculate average turnaround time and average wait time
    float avgTurnaroundTime = 0, avgWaitTime = 0;
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWait Time\n");
    for (int i = 0; i < n; i++) {
        avgTurnaroundTime += turnaroundTime[i];
        avgWaitTime += waitTime[i];
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processId[i], arrivalTime[i], burstTime[i], completionTime[i], turnaroundTime[i], waitTime[i]);
    }

    // Calculate averages
    avgTurnaroundTime /= n;
    avgWaitTime /= n;

    // Display average turnaround time and average wait time
    printf("\nAverage Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("Average Wait Time: %.2f\n", avgWaitTime);

    return 0;
}
