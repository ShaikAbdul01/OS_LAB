#include <stdio.h>

int main()
{
  int i, j, smallest, count = 0, time = 0, n;
  double avg_waiting = 0, avg_turnaround = 0;

  // Prompt user to input the number of processes
  printf("Enter the number of Processes: ");
  scanf("%d", &n);

  // Arrays to store arrival time, burst time, remaining burst time,
  // completion time, waiting time, and turnaround time for each process
  int arrival[n], burst[n], remaining_burst[n], completion[n], waiting[n], turnaround[n];

  // Input arrival time and burst time for each process
  printf("\nEnter arrival time and burst time of each process:\n");
  for (i = 0; i < n; i++)
  {
    // Prompt user to input arrival time of process i+1
    printf("Arrival time of process %d: ", i + 1);
    scanf("%d", &arrival[i]);

    // Prompt user to input burst time of process i+1
    printf("Burst time of process %d: ", i + 1);
    scanf("%d", &burst[i]);

    // Initialize remaining burst time with burst time
    remaining_burst[i] = burst[i];
  }

  // Scheduling loop continues until all processes are completed
  while (count != n)
  {
    // Find the process with the smallest remaining burst time among the arrived processes
    smallest = -1;
    for (i = 0; i < n; i++)
    {
      if (remaining_burst[i] > 0 && (smallest == -1 || remaining_burst[i] < remaining_burst[smallest]) && arrival[i] <= time)
      {
        smallest = i;
      }
    }

    // If no process is found to execute, increment time and continue
    if (smallest == -1)
    {
      time++;
      continue;
    }

    // Execute the selected process for one time unit
    remaining_burst[smallest]--;

    // If the process completes its burst time
    if (remaining_burst[smallest] == 0)
    {
      count++; // Increment count of completed processes
      completion[smallest] = time + 1; // Record completion time
      waiting[smallest] = time + 1 - arrival[smallest] - burst[smallest]; // Calculate waiting time
      turnaround[smallest] = time + 1 - arrival[smallest]; // Calculate turnaround time
      avg_waiting += waiting[smallest]; // Update average waiting time
      avg_turnaround += turnaround[smallest]; // Update average turnaround time
    }

    // Increment time for the next iteration
    time++;
  }

  // Print the table of process details
  printf("pid \t arrival  \t burst \t completion \t waiting \t turnaround \n");
  for (i = 0; i < n; i++)
  {
    printf("%d \t %d \t\t %d \t\t %d \t %d \t\t %d\n", i + 1, arrival[i], burst[i], completion[i], waiting[i], turnaround[i]);
  }

  // Print average waiting time and average turnaround time
  printf("\nAverage waiting time = %.2lf\n", avg_waiting / n);
  printf("Average Turnaround time = %.2lf", avg_turnaround / n);

  return 0;
}

/* https://github.com/codophobia/process-scheduling-algorithms/blob/master/preemptive_priority_scheduling.cpp */