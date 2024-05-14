#include <stdio.h>
#include <stdlib.h>

struct Process {
    char pid;
    int burst_time;
    int priority;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
};

void print_gantt_chart(char *chart, int size) {
    printf("\nGantt Chart:\n");
    for (int i = 0; i < size; i++) {
        printf("%c ", chart[i]);
    }
    printf("\n");
}

void fcfs(struct Process processes[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    char gantt_chart[100];
    int current_time = 0;

    for (int i = 0; i < n; i++) {
        gantt_chart[current_time] = processes[i].pid;
        processes[i].waiting_time = current_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        current_time += processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    print_gantt_chart(gantt_chart, current_time);
    printf("Turnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%c: %d\t\t%d\n", processes[i].pid, processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("Average Turnaround Time: %.2f\n", (float) total_turnaround_time / n);
    printf("Average Waiting Time: %.2f\n", (float) total_waiting_time / n);
}

void sjf(struct Process processes[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    char gantt_chart[100];
    int current_time = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].burst_time > processes[j].burst_time) {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        gantt_chart[current_time] = processes[i].pid;
        processes[i].waiting_time = current_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        current_time += processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    print_gantt_chart(gantt_chart, current_time);
    printf("Turnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%c: %d\t\t%d\n", processes[i].pid, processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("Average Turnaround Time: %.2f\n", (float) total_turnaround_time / n);
    printf("Average Waiting Time: %.2f\n", (float) total_waiting_time / n);
}

void priority_scheduling(struct Process processes[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    char gantt_chart[100];
    int current_time = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].priority < processes[j].priority) {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        gantt_chart[current_time] = processes[i].pid;
        processes[i].waiting_time = current_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        current_time += processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    print_gantt_chart(gantt_chart, current_time);
    printf("Turnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%c: %d\t\t%d\n", processes[i].pid, processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("Average Turnaround Time: %.2f\n", (float) total_turnaround_time / n);
    printf("Average Waiting Time: %.2f\n", (float) total_waiting_time / n);
}

void round_robin(struct Process processes[], int n, int quantum) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    char gantt_chart[1000];
    int current_time = 0;

    int remaining_time[n];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
    }

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0;
                if (remaining_time[i] > quantum) {
                    gantt_chart[current_time] = processes[i].pid;
                    current_time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    gantt_chart[current_time] = processes[i].pid;
                    current_time += remaining_time[i];
                    processes[i].turnaround_time = current_time;
                    remaining_time[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }

    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    print_gantt_chart(gantt_chart, current_time);
    printf("Turnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%c: %d\t\t%d\n", processes[i].pid, processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("Average Turnaround Time: %.2f\n", (float) total_turnaround_time / n);
    printf("Average Waiting Time: %.2f\n", (float) total_waiting_time / n);
}

int main() {
    struct Process processes1[] = {
        {'P', 2, 2, 0},
        {'P', 1, 1, 0},
        {'P', 8, 4, 0},
        {'P', 4, 2, 0},
        {'P', 5, 3, 0}
    };

    printf("First Set of Input:\n");
    printf("First-Come, First-Served (FCFS):\n");
    fcfs(processes1, 5);

    printf("\nShortest-Job-First (SJF):\n");
    sjf(processes1, 5);

    printf("\nPriority Scheduling:\n");
    priority_scheduling(processes1, 5);

    int quantum;
    printf("\nEnter Quantum for Round Robin: ");
    scanf("%d", &quantum);
    printf("\nRound Robin:\n");
    round_robin(processes1, 5, quantum);

    return 0;
}
