#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processId[n], burstTime[n], waitTime[n];

    printf("Enter process id: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &processId[i]);
    }

    printf("Enter burst time: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &burstTime[i]);
    }
    waitTime[0] = 0;
    for (int i = 1; i < n; i++)
    {
        waitTime[i] = burstTime[i - 1] + waitTime[i - 1];
    }

    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    float twt = 0.0;
    float tat = 0.0;
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\n", processId[i], burstTime[i], waitTime[i], burstTime[i] + waitTime[i]);
        twt += waitTime[i];
        tat += (waitTime[i] + burstTime[i]);
    }
    float att, awt;
    awt = twt / n;
    att = tat / n;
    printf("Avg. waiting time= %f\n", awt);
    printf("Avg. turnaround time= %f\n", att);
    return 0;
}