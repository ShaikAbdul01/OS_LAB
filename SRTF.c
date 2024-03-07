#include <stdio.h>

int main()
{
  int i, j, smallest, count = 0, time = 0, n;
  double avg_waiting = 0, avg_turnaround = 0;

  printf("Enter the number of Processes: ");
  scanf("%d", &n);

  int arrival[n], burst[n], remaining_burst[n], completion[n], waiting[n], turnaround[n];

  printf("\nEnter arrival time and burst time of each process:\n");
  for (i = 0; i < n; i++)
  {
    printf("Arrival time of process %d: ", i + 1);
    scanf("%d", &arrival[i]);
    printf("Burst time of process %d: ", i + 1);
    scanf("%d", &burst[i]);
    remaining_burst[i] = burst[i];
  }

  while (count != n)
  {
    smallest = -1;
    for (i = 0; i < n; i++)
    {
      if (remaining_burst[i] > 0 && (smallest == -1 || remaining_burst[i] < remaining_burst[smallest]) && arrival[i] <= time)
      {
        smallest = i;
      }
    }

    if (smallest == -1)
    {
      time++;
      continue;
    }

    remaining_burst[smallest]--;

    if (remaining_burst[smallest] == 0)
    {
      count++;
      completion[smallest] = time + 1;
      waiting[smallest] = time + 1 - arrival[smallest] - burst[smallest];
      turnaround[smallest] = time + 1 - arrival[smallest];
      avg_waiting += waiting[smallest];
      avg_turnaround += turnaround[smallest];
    }

    time++;
  }

  printf("pid \t arrival  \t burst \t completion \t waiting \t turnaround \n");
  for (i = 0; i < n; i++)
  {
    printf("%d \t %d \t\t %d \t\t %d \t %d \t\t %d\n", i + 1, arrival[i], burst[i], completion[i], waiting[i], turnaround[i]);
  }

  printf("\nAverage waiting time = %.2lf\n", avg_waiting / n);
  printf("Average Turnaround time = %.2lf", avg_turnaround / n);

  return 0;
}
