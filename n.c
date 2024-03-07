#include <stdio.h>

int main() {
    int n, ct = 0, remaining, temp;
    float avgtat = 0, avgwt = 0;

    printf("<--Smallest Priority First Scheduling Algorithm (Non-Preemptive)-->\n");
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    int no[n], at[n], bt[n], ct_arr[n], wt[n], tat[n], pri[n], status[n];

    for (int i = 0; i < n; i++) {
        printf("\nProcess No: %d\n", i + 1);
        no[i] = i + 1;
        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Enter Priority: ");
        scanf("%d", &pri[i]);
        status[i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = no[j];
                no[j] = no[j + 1];
                no[j + 1] = temp;

                temp = pri[j];
                pri[j] = pri[j + 1];
                pri[j + 1] = temp;
            }
        }
    }

    printf("\nProcessNo\tAT\tBT\tPri\tCT\tTAT\tWT\n");

    remaining = n;
    for (ct = at[0]; remaining != 0;) {
        int s = n - 1;
        for (int i = 0; i < n; i++) {
            if (at[i] <= ct && status[i] != 1 && pri[i] < pri[s]) {
                s = i;
            }
        }
        ct_arr[s] = ct = ct + bt[s];
        tat[s] = ct_arr[s] - at[s];
        avgtat += tat[s];
        wt[s] = tat[s] - bt[s];
        avgwt += wt[s];
        status[s] = 1;
        remaining--;
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n", no[s], at[s], bt[s], pri[s], ct_arr[s], tat[s], wt[s]);
    }

    avgtat /= n;
    avgwt /= n;
    printf("\nAverage Turnaround Time: %.2f\n", avgtat);
    printf("Average Waiting Time: %.2f\n", avgwt);

    return 0;
}
