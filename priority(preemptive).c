#include <stdio.h>

int main()
{
    int n;

    // Get the number of processes from the user
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processId[n], arrivalTime[n], burstTime[n], priority[n], completionTime[n], turnaroundTime[n], waitTime[n], remainingTime[n];

    // Initialize remaining time and completion time arrays
    for (int i = 0; i < n; i++)
    {
        completionTime[i] = 0;
        remainingTime[i] = 0;
    }

    // Get process details from the user
    printf("Enter process Id, arrival time, priority and burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d %d", &processId[i], &arrivalTime[i], &priority[i], &burstTime[i]);
        remainingTime[i] = burstTime[i];
    }

    int currentTime = 0;
    int completed = 0;
    float totalTurnaroundTime = 0, totalWaitTime = 0;

    while (completed < n)
    {
        int highestPriorityJob = -1;
        int highestPriority = 9999;

        // Find the process with the highest priority that has arrived and not completed yet
        for (int i = 0; i < n; i++)
        {
            if (arrivalTime[i] <= currentTime && remainingTime[i] > 0 && priority[i] < highestPriority)
            {
                highestPriority = priority[i];
                highestPriorityJob = i;
            }
        }

        if (highestPriorityJob == -1)
        {
            currentTime++;
            continue;
        }

        // Reduce remaining burst time for the chosen process
        remainingTime[highestPriorityJob]--;

        // If burst time becomes 0, update completion time and calculate turnaround and wait time
        if (remainingTime[highestPriorityJob] == 0)
        {
            completed++;
            completionTime[highestPriorityJob] = currentTime + 1;
            turnaroundTime[highestPriorityJob] = completionTime[highestPriorityJob] - arrivalTime[highestPriorityJob];
            waitTime[highestPriorityJob] = turnaroundTime[highestPriorityJob] - burstTime[highestPriorityJob];
            totalTurnaroundTime += turnaroundTime[highestPriorityJob];
            totalWaitTime += waitTime[highestPriorityJob];
        }

        // Move to the next unit of time
        currentTime++;
    }

    // Calculate average turnaround time and average wait time
    float avgTurnaroundTime = totalTurnaroundTime / n;
    float avgWaitTime = totalWaitTime / n;

    // Display process details and results
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWait Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processId[i], arrivalTime[i], burstTime[i], completionTime[i], turnaroundTime[i], waitTime[i]);
    }

    printf("\nAverage Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("Average Wait Time: %.2f\n", avgWaitTime);

    return 0;
}
