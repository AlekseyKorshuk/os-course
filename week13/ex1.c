#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define FILENAME "input.txt" // File name to read the input
#define n 5 // Amount of processes
#define m 3 // Amount of resource types

typedef struct process_D {
    int id;
    int done;
    int C[m];
    int R[m];
} process_t;

int E[m];
int A[m];
process_t process[n];

void scan_file(char *filename) {
    FILE *input;
    input = fopen(filename, "r");

    if (input == NULL) {
        printf("Could not open file!\n");
        return;
    }

    for (int j = 0; j < m; j++)
        fscanf(input, "%d", &E[j]);


    for (int j = 0; j < m; j++)
        fscanf(input, "%d", &A[j]);


    for (int PID = 0; PID < n; PID++) {
        process[PID].id = PID;
        process[PID].done = FALSE;
    }

    for (int PID = 0; PID < n; PID++) {
        for (int j = 0; j < m; j++)
            fscanf(input, "%d", &process[PID].C[j]);

    }

    for (int PID = 0; PID < n; PID++) {
        for (int j = 0; j < m; j++)
            fscanf(input, "%d", &process[PID].R[j]);

    }
}

void release_resources(int PID) {
    for (int j = 0; j < m; j++) {
        A[j] = A[j] + process[PID].C[j];
        process[PID].C[j] = 0;
        process[PID].R[j] = 0;
        process[PID].done = TRUE;
    }
}

int find_candidate() {
    for (int PID = 0; PID < n; PID++) {
        if (process[PID].done == TRUE) continue;

        for (int j = 0; j < m; j++) {
            if (process[PID].R[j] > A[j]) break;
            if (j + 1 == m) return PID;

        }
    }
    return -1;
}

void print_state(int verdict) {
    if (verdict == TRUE)
        printf("\n############ RESULT ###########\n");
    else
        printf("\n###############################\n");

    printf("Available: (");
    for (int j = 0; j < m; j++) {
        printf("%d", A[j]);
        if (j + 1 == m) printf(")\n"); else printf(", ");

    }
    int counter = 0;
    for (int PID = 0; PID < n; PID++) {
        printf("Process %d ", process[PID].id);

        if (verdict == TRUE) {
            if (process[PID].done == FALSE) {
                printf("is deadlocked!\n");
                counter++;
            } else
                printf("is done!\n");

        } else {
            if (process[PID].done == FALSE) {
                printf("is not finished yet. Requires (");
                for (int j = 0; j < m; j++) {
                    printf("%d", process[PID].R[j]);
                    if (j + 1 == m) printf(").\n"); else printf(", ");
                }
            } else
                printf("is done.\n");

        }
    }
    if (verdict)
        if (counter != 0)
            printf("Number of processes that are deadlocked: %d!\n", counter);
        else
            printf("No deadlocks detected!\n");
}

int main() {
    int candidate;
    scan_file(FILENAME);

    printf("Exists: (");
    for (int j = 0; j < m; j++) {
        printf("%d", E[j]);
        if (j + 1 == m) printf(")\n"); else printf(", ");
    }

    while (TRUE) {
        print_state(FALSE);
        candidate = find_candidate();
        if (candidate == -1) break;
        release_resources(candidate);
    }

    print_state(TRUE);

    return 0;
}