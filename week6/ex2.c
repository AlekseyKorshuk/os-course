/*
 * SJF
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
    printf("Enter the amount of processes: ");
    scanf("%d", &N);
    printf("\nEnter AT and BT for each process in a row:\n");

    struct Process process;

    struct Process processes[N];

    for (int i = 0; i < N; i++){
        processes[i] .index = i;
        printf("\n>");
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }


    for (int i = 0; i < N; i++){
        for (int j = i; j < N; j++){
            if (processes[i].arrival_time > processes[j].arrival_time || (processes[i].burst_time > processes[j].burst_time && processes[i].arrival_time == processes[j].arrival_time )){
                process = processes[i];
                processes[i] = processes[j];
                processes[j] = process;
            }
        }
    }


    float average_turnaround_time = 0, average_waiting_time = 0;
    for (int i = 0; i < N; i++){
        if (i == 0){
            processes[i].waiting_time =  0;
            processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
            processes[i].completion_time = processes[i].turnaround_time + processes[i].arrival_time;
            continue;
        }

        processes[i].waiting_time = processes[0].arrival_time;
        for (int j = 0; j < i; j++){
            processes[i].waiting_time += processes[j].burst_time;
        }
        processes[i].waiting_time -= processes[i].arrival_time;
        if (processes[i].waiting_time < 0)
            processes[i].waiting_time = 0;

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
4
0 10
0 5
1 3
2 2
*/