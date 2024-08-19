#include <stdio.h>

struct Process {
    int id;         // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
    int waiting;    // Waiting time
    int turnaround; // Turnaround time
};

void calculateWaitingTime(struct Process p[], int n) {
    p[0].waiting = 0; // First process has no waiting time

    for (int i = 1; i < n; i++) {
        p[i].waiting = p[i-1].waiting + p[i-1].burst;
        p[i].waiting -= p[i].arrival; // Waiting time considering arrival time
        if (p[i].waiting < 0)
            p[i].waiting = 0; // Waiting time can't be negative
    }
}

void calculateTurnaroundTime(struct Process p[], int n) {
    for (int i = 0; i < n; i++) {
        p[i].turnaround = p[i].burst + p[i].waiting;
    }
}

void printResults(struct Process p[], int n) {
    int totalWaiting = 0, totalTurnaround = 0;

    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        totalWaiting += p[i].waiting;
        totalTurnaround += p[i].turnaround;
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].arrival, p[i].burst, p[i].waiting, p[i].turnaround);
    }

    printf("\nAverage Waiting Time: %.2f", (float)totalWaiting / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)totalTurnaround / n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter arrival time for process %d: ", p[i].id);
        scanf("%d", &p[i].arrival);
        printf("Enter burst time for process %d: ", p[i].id);
        scanf("%d", &p[i].burst);
    }

    calculateWaitingTime(p, n);
    calculateTurnaroundTime(p, n);
    printResults(p, n);

    return 0;
}