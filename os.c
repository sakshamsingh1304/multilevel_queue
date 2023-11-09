#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Process {
    char name[50];
    int priority;
    int burstTime;
};

int sortByPriority(const void *a, const void *b) {
    struct Process *pa = (struct Process *)a;
    struct Process *pb = (struct Process *)b;

    return (pa->priority - pb->priority);
}

int main() {
    int x, y, z;
    printf("Enter the number of processes for Queue 1: ");
    scanf("%d", &x);
    printf("Enter the number of processes for Queue 2: ");
    scanf("%d", &y);
    printf("Enter the number of processes for Queue 3: ");
    scanf("%d", &z);

    int priority1, priority2, priority3;
    printf("Enter the priority for Queue 1: ");
    scanf("%d", &priority1);
    printf("Enter the priority for Queue 2: ");
    scanf("%d", &priority2);
    printf("Enter the priority for Queue 3: ");
    scanf("%d", &priority3);

    struct Process *queue1 = (struct Process *)malloc(x * sizeof(struct Process));
    struct Process *queue2 = (struct Process *)malloc(y * sizeof(struct Process));
    struct Process *queue3 = (struct Process *)malloc(z * sizeof(struct Process));

    for (int i = 0; i < x; i++) {
        struct Process process;
        sprintf(process.name, "1%d", i+1);
        process.priority = priority1;

        if (priority1 == 1) {
            printf("Enter the burst time for %s: ", process.name);
            scanf("%d", &process.burstTime);
        } else {
            process.burstTime = 0;
        }

        queue1[i] = process;
    }

    for (int i = 0; i < y; i++) {
        struct Process process;
        sprintf(process.name, "2%d", i+1);

        if (priority2 == 2) {
            printf("Enter the priority for %s: ", process.name);
            scanf("%d", &process.priority);
        } else {
            process.priority = priority2;
        }

        queue2[i] = process;
    }

    for (int i = 0; i < z; i++) {
        struct Process process;
        printf("Enter the name for process A%d: ", i+1);
        scanf("%s", process.name);
        queue3[i] = process;
    }

    printf("Processes in Queue 1: ");
    for (int i = 0; i < x; i++) {
        printf("%s ", queue1[i].name);
    }
    printf("\n");

    printf("Processes in Queue 2: ");
    for (int i = 0; i < y; i++) {
        printf("%s ", queue2[i].name);
    }
    printf("\n");

    printf("Processes in Queue 3: ");
    for (int i = 0; i < z; i++) {
        printf("%s ", queue3[i].name);
    }
    printf("\n");

    int quantum = 4;
    if (priority1 == 1) {
        printf("Round Robin Output for Queue 1: ");
        for (int i = 0; i < x; i++) {
            struct Process currentProcess = queue1[i];

            printf("%s ", currentProcess.name);

            if (currentProcess.burstTime > quantum) {
                currentProcess.burstTime -= quantum;
                queue1[x] = currentProcess;
                x++;
            }
        }
        printf("\n");
    }

    if (priority2 == 2) {
        qsort(queue2, y, sizeof(struct Process), sortByPriority);

        printf("Processes in Queue 2 based on priority (Low Number Highest Priority): ");
        for (int i = 0; i < y; i++) {
            printf("%s ", queue2[i].name);
        }
        printf("\n");
    }

    if (priority3 == 3) {
        printf("Processes in Queue 3: ");
        for (int i = 0; i < z; i++) {
            printf("%s ", queue3[i].name);
        }
        printf("\n");
    }

    free(queue1);
    free(queue2);
    free(queue3);

    return 0;
}
