#include <stdio.h>

int main()
{
    int n;

    // Get the number of processes from the user
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processId[n], arrivalTime[n], burstTime[n], priority[n], completionTime[n], turnaroundTime[n], waitTime[n], isCompleted[n];

    // Initialize isCompleted array
    for (int i = 0; i < n; i++)
    {
        isCompleted[i] = 0;
    }

    // Get process details from the user
    printf("Enter process Id, arrival time, priority and burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d %d", &processId[i], &arrivalTime[i], &priority[i], &burstTime[i]);
    }

    int currentTime = 0;
    int completed = 0;
    float totalTurnaroundTime = 0, totalWaitTime = 0;

    while (completed < n)
    {
        int highestPriority = 9999;
        int highestPriorityJob = -1;

        // Find the highest priority job that has arrived and not completed yet
        for (int i = 0; i < n; i++)
        {
            if (arrivalTime[i] <= currentTime && !isCompleted[i] && priority[i] < highestPriority)
            {
                highestPriority = priority[i];
                highestPriorityJob = i;
            }
        }

        if (highestPriorityJob == -1)
        {
            currentTime++; // If no process is available at the moment, move to the next unit of time
            continue;
        }

        // Mark the highest priority job as completed
        isCompleted[highestPriorityJob] = 1;
        completed++;

        // Update current time and completion time for the completed process
        currentTime += burstTime[highestPriorityJob];
        completionTime[highestPriorityJob] = currentTime;

        // Calculate turnaround time and wait time for the completed process
        turnaroundTime[highestPriorityJob] = completionTime[highestPriorityJob] - arrivalTime[highestPriorityJob];
        waitTime[highestPriorityJob] = turnaroundTime[highestPriorityJob] - burstTime[highestPriorityJob];

        // Calculate total turnaround time and total wait time
        totalTurnaroundTime += turnaroundTime[highestPriorityJob];
        totalWaitTime += waitTime[highestPriorityJob];
    }

    // Calculate average turnaround time and average wait time
    float avgTurnaroundTime = totalTurnaroundTime / n;
    float avgWaitTime = totalWaitTime / n;

    // Display process details and results
    printf("\nProcess\tCompletion Time\tTurnaround Time\tWait Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", processId[i], completionTime[i], turnaroundTime[i], waitTime[i]);
    }

    printf("\nAverage Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("Average Wait Time: %.2f\n", avgWaitTime);

    return 0;
}
