#include <stdio.h>
int main()
{

    int n;
    printf("Enter the Process: ");
    scanf("%d", &n);
    printf("Enter the process Id: ");
    int processId[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &processId[i]);
    }
    int arrivalTime[n];
    printf("Enter the arrival time: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arrivalTime[i]);
    }
    int burstTime[n];
    printf("Enter the burst time: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &burstTime[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arrivalTime[i] > arrivalTime[j])
            {
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

    int completionTime[n];
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

    int turnaroundTime[n], waitTime[n];
    float awt = 0, atat = 0;
    printf("\np\t A.T\t B.T\t C.T\t TAT\t WT");
    for (int i = 0; i < n; i++)
    {
        turnaroundTime[i] = completionTime[i] - arrivalTime[i];
        waitTime[i] = turnaroundTime[i] - burstTime[i];
        atat += turnaroundTime[i];
        awt += waitTime[i];
    }
    atat = atat / n;
    awt = awt / n;
    for (int i = 0; i < n; i++)
    {
        printf("\nP%d\t %d\t %d\t %d \t %d \t %d", processId[i], arrivalTime[i], burstTime[i], completionTime[i], turnaroundTime[i], waitTime[i]);
    }
    printf("\naverage turnaround time is %f", atat);

    printf("\naverage wating timme is %f", awt);
    return 0;
}
