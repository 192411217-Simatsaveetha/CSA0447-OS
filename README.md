#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Process ID: %d\n", getpid());
    printf("Parent Process ID: %d\n", getppid());
    printf("\n----------------------------------\n");

    return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int source, dest;
    char buffer[100];
    int bytes;

    char src[100], dst[100];

    // Input file names
    printf("Enter the filename to open for reading\n");
    scanf("%s", src);

    printf("Enter the filename to open for writing\n");
    scanf("%s", dst);

    // Open source file
    source = open(src, O_RDONLY);
    if (source < 0) {
        printf("Error opening source file\n");
        return 1;
    }

    // Open/create destination file
    dest = open(dst, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest < 0) {
        printf("Error opening destination file\n");
        return 1;
    }

    // Read and write loop
    while ((bytes = read(source, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytes);
    }

    printf("\nContents copied to %s\n", dst);

    // Close files
    close(source);
    close(dest);

    return 0;
}

#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of process: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];

    printf("Enter Burst Time:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
    }

    // Waiting Time
    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    // Turnaround Time
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Output Table (same style as your image)
    printf("\nP\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    // Averages
    float total_wt = 0, total_tat = 0;
    for(i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time= %.6f\n", total_wt/n);
    printf("Average Turnaround Time= %.6f\n", total_tat/n);
    printf("_________________________________________\n");

    return 0;
}

#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of process:");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];

    printf("\nEnter Burst Time:\n");
    for(i = 0; i < n; i++) {
        printf("P%d:", i+1);
        scanf("%d", &bt[i]);
    }

    // Waiting Time
    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    // Turnaround Time
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Proper Table Format
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    // Averages
    float total_wt = 0, total_tat = 0;

    for(i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time=%.6f", total_wt/n);
    printf("\nAverage Turnaround Time=%.6f\n", total_tat/n);

    return 0;
}

#include <stdio.h>

struct process {
    char name;
    int bt, pr, wt, tat;
};

int main() {
    int n, i, j;
    struct process p[10], temp;

    printf("Enter the total number of Processes: ");
    scanf("%d", &n);

    printf("\nPlease Enter the Burst Time and Priority of each process:\n");

    for(i = 0; i < n; i++) {
        p[i].name = 'A' + i;

        printf("\nEnter the details of the process %c\n", p[i].name);

        printf("Enter the burst time: ");
        scanf("%d", &p[i].bt);

        printf("Enter the priority: ");
        scanf("%d", &p[i].pr);
    }

    // Sort by priority (higher number = higher priority)
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(p[i].pr < p[j].pr) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Waiting Time
    p[0].wt = 0;
    for(i = 1; i < n; i++) {
        p[i].wt = p[i-1].wt + p[i-1].bt;
    }

    // Turnaround Time
    for(i = 0; i < n; i++) {
        p[i].tat = p[i].wt + p[i].bt;
    }

    // Output
    printf("\nProcess_name\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("-------------------------------------------------------------\n");

    float total_wt = 0, total_tat = 0;

    for(i = 0; i < n; i++) {
        printf("\t%c\t\t%d\t\t%d\t\t%d\n",
               p[i].name, p[i].bt, p[i].wt, p[i].tat);

        printf("-------------------------------------------------------------\n");

        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    printf("\nAverage Waiting Time : %.6f\n", total_wt/n);
    printf("Average Turnaround Time: %.6f\n", total_tat/n);

    return 0;
}
