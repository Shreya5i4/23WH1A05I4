#include <stdio.h>

int main() {
    int n, time_quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    int burst_time[n], arrival_time[n];
    int remaining_burst_time[n], waiting_time[n], turn_around_time[n];
    int total_waiting_time = 0, total_turnaround_time = 0;
    
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        remaining_burst_time[i] = burst_time[i];  
        arrival_time[i] = 0;  
    }

    for (int i = 0; i < n; i++) {
        waiting_time[i] = 0;
    }

    int current_time = 0;  
    int completed = 0;     
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
              
                if (remaining_burst_time[i] > time_quantum) {
                   
                    current_time += time_quantum;
                    remaining_burst_time[i] -= time_quantum;
                } else {
                   
                    current_time += remaining_burst_time[i];
                    waiting_time[i] = current_time - burst_time[i]; 
                    turn_around_time[i] = waiting_time[i] + burst_time[i]; 
                    remaining_burst_time[i] = 0; 
                    completed++; 
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turn_around_time[i];
    }

    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;

    printf("\nProcesses\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turn_around_time[i]);
    }

    printf("\nAverage waiting time = %.2f", avg_waiting_time);
    printf("\nAverage turnaround time = %.2f\n", avg_turnaround_time);

    return 0;
}