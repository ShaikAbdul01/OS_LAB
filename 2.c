#include <stdio.h>
int main()
{
    int n;
    printf("Enter the process: ");
    scanf("%d", &n);
    int id[n];
    printf("Enter the id: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &id[i]);
    }
    int burstTime[n];
    printf("Enter the BurstTime: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &burstTime[i]);
    }
    int waitTime[n];
    waitTime[0] = 0;
    double TotalWait = 0.0;
    for (int i = 1; i < n; i++)
    {
        waitTime[i] = waitTime[i - 1] + burstTime[i - 1];
        TotalWait += waitTime[i];
    }
    int turnaroundTime[n];
    double TotalTurn = 0.0;
    for (int i = 0; i < n; i++)
    {
        turnaroundTime[i] = (waitTime[i] + burstTime[i]);
        TotalTurn += turnaroundTime[i];
    }
    printf("Id\t\tBurstTime\t\tWaitingTime\t\tTurnaroundTime\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\n", id[i], burstTime[i], waitTime[i], turnaroundTime[i]);
    }
    double awt = 0.0;
    awt = TotalWait / n;
    double atat = 0.0;
    atat = TotalTurn / n;
    printf("Average Waiting Time: %lf\n", awt);
    printf("Average Turn Around Time: %lf\n", atat);
    return 0;
}
