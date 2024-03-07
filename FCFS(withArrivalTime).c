#include <stdio.h>

int main()
{
    // Declare variables
    int n;

    // Get the number of processes from the user
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Declare arrays to store process information
    int processId[n], arrivalTime[n], burstTime[n], completionTime[n], turnaroundTime[n], waitTime[n];

    // Get process details from the user
    printf("Enter process Id, arrival time, and burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &processId[i], &arrivalTime[i], &burstTime[i]);
    }

    // Sort processes based on arrival time using bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arrivalTime[i] > arrivalTime[j])
            {
                // Swap process details
                int temp = processId[i];
                processId[i] = processId[j];
                processId[j] = temp;

                temp = arrivalTime[i];
                arrivalTime[i] = arrivalTime[j];
                arrivalTime[j] = temp;

                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;
            }
        }
    }

    // Calculate completion time for each process
    completionTime[0] = arrivalTime[0] + burstTime[0];
    for (int i = 1; i < n; i++)
    {
        int temp = 0;
        if (completionTime[i - 1] < arrivalTime[i])
        {
            temp = arrivalTime[i] - completionTime[i - 1];
        }
        completionTime[i] = completionTime[i - 1] + burstTime[i] + temp;
    }

    // Calculate turnaround time, wait time, average turnaround time, and average wait time
    float avgTurnaroundTime = 0, avgWaitTime = 0;
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWait Time\n");
    for (int i = 0; i < n; i++)
    {
        turnaroundTime[i] = completionTime[i] - arrivalTime[i];
        waitTime[i] = turnaroundTime[i] - burstTime[i];
        avgTurnaroundTime += turnaroundTime[i];
        avgWaitTime += waitTime[i];

        // Display process details
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
