#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processId[n], arrivalTime[n], burstTime[n], priority[n];

    printf("Process ID: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &processId[i]);
    }
    printf("\nArrival Time: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arrivalTime[i]);
    }
    printf("\nBurst Time: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &burstTime[i]);
    }
    printf("\nPriority: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &priority[i]);
    }

    // Sort processes based on arrival time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arrivalTime[j] > arrivalTime[j + 1])
            {
                // Swap arrival time
                int temp = arrivalTime[j];
                arrivalTime[j] = arrivalTime[j + 1];
                arrivalTime[j + 1] = temp;

                // Swap burst time
                temp = burstTime[j];
                burstTime[j] = burstTime[j + 1];
                burstTime[j + 1] = temp;

                // Swap process ID
                temp = processId[j];
                processId[j] = processId[j + 1];
                processId[j + 1] = temp;

                // Swap priority
                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;
            }
        }
    }

    // Calculate completion time, turnaround time, and waiting time
    int completionTime[n], turnaroundTime[n], waitingTime[n];
    float totalTurnaroundTime = 0, totalWaitingTime = 0;
    completionTime[0] = arrivalTime[0] + burstTime[0];
    turnaroundTime[0] = completionTime[0] - arrivalTime[0];
    waitingTime[0] = 0;
    totalTurnaroundTime += turnaroundTime[0];
    totalWaitingTime += waitingTime[0];
    for (int i = 1; i < n; i++)
    {
        completionTime[i] = completionTime[i - 1] + burstTime[i];
        turnaroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
        totalTurnaroundTime += turnaroundTime[i];
        totalWaitingTime += waitingTime[i];
    }

    // Print process details and metrics
    printf("\nProcess\t Arrival\t Burst\t Priority\t Completion\t Turnaround\t Waiting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t %d\t\t %d\t %d\t\t %d\t\t %d\t\t %d\n", processId[i], arrivalTime[i], burstTime[i], priority[i], completionTime[i], turnaroundTime[i], waitingTime[i]);
    }
    printf("\nAverage Turnaround Time: %.2f\n", totalTurnaroundTime / n);
    printf("Average Waiting Time: %.2f\n", totalWaitingTime / n);

    return 0;
}
