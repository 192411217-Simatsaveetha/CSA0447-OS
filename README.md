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

#include <stdio.h>

int main() {
    int n, i, tq;
    
    printf("Total number of process in the system: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], wt[n], tat[n];

    for(i = 0; i < n; i++) {
        printf("\nEnter the Arrival and Burst time of the Process[%d]\n", i+1);

        printf("Arrival time is: ");
        scanf("%d", &at[i]);

        printf("Burst time is: ");
        scanf("%d", &bt[i]);

        rt[i] = bt[i]; // remaining time
    }

    printf("\nEnter the Time Quantum for the process: ");
    scanf("%d", &tq);

    int time = 0, done;
    
    // Round Robin Logic
    do {
        done = 1;
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                done = 0;

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                }
            }
        }
    } while(!done);

    // Turnaround Time
    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    // Output
    printf("\nProcess No\tBurst Time\tTAT\tWaiting Time\n");

    float total_tat = 0, total_wt = 0;

    for(i = 0; i < n; i++) {
        printf("Process No[%d]\t%d\t\t%d\t%d\n",
               i+1, bt[i], tat[i], wt[i]);

        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nAverage Turn Around Time: %.6f", total_tat/n);
    printf("\nAverage Waiting Time: %.6f\n", total_wt/n);

    return 0;
}

#include <stdio.h>

struct Process {
    int id, arrival, burst, start, end, waiting, turnaround;
};

int main() {
    int n, i;
    printf("Enter the number of processes\n");
    scanf("%d", &n);

    struct Process p[n];
    for(i = 0; i < n; i++) {
        p[i].id = i+1;
        printf("Enter the arrival time and execution time for process %d\n", i+1);
        scanf("%d %d", &p[i].arrival, &p[i].burst);
    }

    int current_time = 0;
    float total_wait = 0, total_turnaround = 0;

    for(i = 0; i < n; i++) {
        if(current_time < p[i].arrival)
            current_time = p[i].arrival;

        p[i].start = current_time;
        p[i].waiting = p[i].start - p[i].arrival;
        p[i].end = p[i].start + p[i].burst;
        p[i].turnaround = p[i].end - p[i].arrival;

        current_time = p[i].end;

        total_wait += p[i].waiting;
        total_turnaround += p[i].turnaround;
    }

    printf("\nProcess |Arrival time |Execution time |Start time |End time |Waiting\n");
    for(i = 0; i < n; i++) {
        printf("p[%d]    | %d           | %d             | %d         | %d       | %d\n",
               p[i].id, p[i].arrival, p[i].burst, p[i].start, p[i].end, p[i].waiting);
    }

    printf("\nAverage waiting time is %f", total_wait/n);
    printf("\nAverage turnaround time is %f\n", total_turnaround/n);

    return 0;
}

#include <stdio.h>

int main() {
    int n, tq;
    int i, j;

    printf("Total number of process in the system: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];

    // Input
    for (i = 0; i < n; i++) {
        printf("\nEnter the Arrival and Burst time of the Process[%d]\n", i + 1);

        printf("Arrival time is: ");
        scanf("%d", &at[i]);

        printf("\nBurst time is: ");
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
    }

    printf("\nEnter the Time Quantum for the process: ");
    scanf("%d", &tq);

    int time = 0, completed = 0;

    while (completed < n) {
        int executed = 0;

        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                executed = 1;

                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                    completed++;
                }
            }
        }

        if (!executed) {
            time++;
        }
    }

    // Calculate TAT and WT
    float total_tat = 0, total_wt = 0;

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Sort by completion time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ct[i] > ct[j]) {
                int temp;

                temp = ct[i]; ct[i] = ct[j]; ct[j] = temp;
                temp = tat[i]; tat[i] = tat[j]; tat[j] = temp;
                temp = wt[i]; wt[i] = wt[j]; wt[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = at[i]; at[i] = at[j]; at[j] = temp;
            }
        }
    }

    // Output
    printf("\nProcess No        Burst Time        TAT        Waiting Time\n");

    for (i = 0; i < n; i++) {
        printf("Process No[%d]        %d            %d            %d\n",
               i + 1, bt[i], tat[i], wt[i]);

        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nAverage Turn Around Time: %f", total_tat / n);
    printf("\nAverage Waiting Time: %f\n", total_wt / n);

    return 0;
}

#include <stdio.h>
#include <windows.h>

int main() {
    HANDLE hRead, hWrite;
    char buffer[100];

    // Create pipe
    CreatePipe(&hRead, &hWrite, NULL, 0);

    // -------- Producer --------
    char msg[] = "Hello, message queue!";
    DWORD written;

    WriteFile(hWrite, msg, sizeof(msg), &written, NULL);
    printf("Producer: Data sent to message queue: %s\n", msg);

    // -------- Consumer --------
    DWORD read;
    ReadFile(hRead, buffer, sizeof(buffer), &read, NULL);

    printf("Consumer: Data received from message queue: %s\n", buffer);

    // Close handles
    CloseHandle(hRead);
    CloseHandle(hWrite);

    return 0;
}

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

// Message structure
struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    // Create unique key
    key = ftok("msgqueuefile", 65);

    // Create message queue
    msgid = msgget(key, 0666 | IPC_CREAT);

    // -------- Producer --------
    message.msg_type = 1;
    strcpy(message.msg_text, "Hello, message queue!");

    msgsnd(msgid, &message, sizeof(message), 0);

    printf("Producer: Data sent to message queue: %s\n", message.msg_text);

    // -------- Consumer --------
    msgrcv(msgid, &message, sizeof(message), 1, 0);

    printf("Consumer: Data received from message queue: %s\n", message.msg_text);

    // Delete message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}


#include <stdio.h>
#include <pthread.h>

// Thread function 1
void* thread1_func(void* arg) {
    int i;
    for (i = 1; i <= 5; i++) {
        printf("Thread 1: %d\n", i);
    }
    return NULL;
}

// Thread function 2
void* thread2_func(void* arg) {
    int i;
    for (i = 1; i <= 5; i++) {
        printf("Thread 2: %d\n", i);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Create threads
    pthread_create(&t1, NULL, thread1_func, NULL);
    pthread_create(&t2, NULL, thread2_func, NULL);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads have finished execution.\n");

    return 0;
}
