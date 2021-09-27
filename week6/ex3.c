/*
 * Round robin
 */

#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>

struct Process{
    int index;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};


void solve(){
    int N;
    int quantum;
    printf("Enter the quantum: ");
    scanf("%d", &quantum);
    printf("Enter the amount of processes: ");
    scanf("%d", &N);
    printf("\nEnter AT and BT for each process in a row:\n");

    struct Process process;
    int temp;
    struct Process processes[N];

    int remaining_burst_time[N];

    for (int i = 0; i < N; i++){
        processes[i] .index = i;
        printf("\n>");
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        remaining_burst_time[i] = processes[i].burst_time;
    }

    for (int i = 0; i < N; i++){
        for (int j = i; j < N; j++){
            if (processes[i].arrival_time > processes[j].arrival_time){
                process = processes[i];
                processes[i] = processes[j];
                processes[j] = process;
                temp = remaining_burst_time[i];
                remaining_burst_time[i] = remaining_burst_time[j];
                remaining_burst_time[j] = temp;
            }
        }
    }

    float average_turnaround_time = 0, average_waiting_time = 0;

    int counter = N;
    int T = processes[0].arrival_time;

    int done = 0;
    while (counter > 0){
        done = 0;
        for (int i = 0; i < N; i++){
            if (T >= processes[i].arrival_time && remaining_burst_time[i] > 0){
                done++;
                if (remaining_burst_time[i] > quantum){
                    T += quantum;
                    remaining_burst_time[i] -= quantum;
                }
                else{
                    T += remaining_burst_time[i];
                    processes[i].waiting_time = T - processes[i].burst_time - processes[i].arrival_time;
                    remaining_burst_time[i] = 0;
                    counter -= 1;
                }
            }
        }
        if (done == 0)
            T++;
    }

    for (int i = 0; i < N; i++){
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
        processes[i].completion_time = processes[i].turnaround_time + processes[i].arrival_time;
        average_waiting_time += processes[i].waiting_time;
        average_turnaround_time += processes[i].turnaround_time;
    }
    average_turnaround_time /= N;
    average_waiting_time /= N;

    for (int i = 0; i < N; i++){
        printf("Process #%d: arrival_time=%d, burst_time=%d, waiting_time=%d, completion_time=%d, turnaround_time=%d\n", processes[i].index, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].completion_time, processes[i].turnaround_time);
    }
    printf("Average waiting_time=%f, Average turnaround_time=%f", average_waiting_time, average_turnaround_time);
}

int main(){
    srand(time(NULL));

    solve();
}

/*
2
4
0 10
0 5
1 3
2 2
*/