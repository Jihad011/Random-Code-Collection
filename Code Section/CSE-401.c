#include <stdio.h>
#include <stdbool.h>

struct Process {
    int burstTime;
    int priority;
    int arrivalTime;
    int remainingTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    bool executed;
};

void sjf(struct Process processes[], int n) {
    int time = 0;
    int completed = 0;
    int shortest = -1;
    int prev_shortest = -1;
    
    while (completed != n) {
        shortest = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= time && !processes[i].executed) {
                if (shortest == -1 || processes[i].remainingTime < processes[shortest].remainingTime) {
                    shortest = i;
                }
            }
        }
        
        if (shortest == -1) {
            time++;
            continue;
        }
        
        if (prev_shortest != shortest) {
            printf("|P%d|", shortest + 1);
        }
        
        processes[shortest].remainingTime--;
        prev_shortest = shortest;
        
        if (processes[shortest].remainingTime == 0) {
            processes[shortest].completionTime = time + 1;
            processes[shortest].turnaroundTime = processes[shortest].completionTime - processes[shortest].arrivalTime;
            processes[shortest].waitingTime = processes[shortest].turnaroundTime - processes[shortest].burstTime;
            completed++;
            processes[shortest].executed = true;
        }
        
        time++;
    }
}

void priorityScheduling(struct Process processes[], int n) {
    int time = 0;
    int completed = 0;
    int highest_priority = -1;
    
    while (completed != n) {
        highest_priority = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= time && !processes[i].executed) {
                if (highest_priority == -1 || processes[i].priority < processes[highest_priority].priority) {
                    highest_priority = i;
                }
            }
        }
        
        if (highest_priority == -1) {
            time++;
            continue;
        }
        
        printf("|P%d|", highest_priority + 1);
        
        processes[highest_priority].remainingTime--;
        
        if (processes[highest_priority].remainingTime == 0) {
            processes[highest_priority].completionTime = time + 1;
            processes[highest_priority].turnaroundTime = processes[highest_priority].completionTime - processes[highest_priority].arrivalTime;
            processes[highest_priority].waitingTime = processes[highest_priority].turnaroundTime - processes[highest_priority].burstTime;
            completed++;
            processes[highest_priority].executed = true;
        }
        
        time++;
    }
}

int main() {
    struct Process processes[] = {
        {20, 40, 0, 20, 0, 0, 0, false},
        {25, 30, 25, 25, 0, 0, 0, false},
        {25, 30, 30, 25, 0, 0, 0, false},
        {15, 35, 60, 15, 0, 0, 0, false},
        {10, 5, 100, 10, 0, 0, 0, false},
        {10, 10, 105, 10, 0, 0, 0, false}
    };
    int n = sizeof(processes) / sizeof(processes[0]);
    
    printf("SJF Gantt Chart: ");
    sjf(processes, n);
    printf("\n\n");
    
    printf("Priority Scheduling Gantt Chart: ");
    priorityScheduling(processes, n);
    printf("\n\n");
    
    float avgTurnaroundTime = 0;
    float avgWaitingTime = 0;
    
    printf("Process\t Turnaround Time\t Waiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t %d\t\t\t %d\n", i + 1, processes[i].turnaroundTime, processes[i].waitingTime);
        avgTurnaroundTime += processes[i].turnaroundTime;
        avgWaitingTime += processes[i].waitingTime;
    }
    
    avgTurnaroundTime /= n;
    avgWaitingTime /= n;
    
    printf("\nAverage Turnaround Time: %.2f", avgTurnaroundTime);
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    
    return 0;
}
