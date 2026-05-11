#include <stdio.h>

#define MAX_MEMORY 1000

int memory[MAX_MEMORY];

void initializeMemory()
{
    int i;

    for(i = 0; i < MAX_MEMORY; i++)
    {
        memory[i] = -1;
    }
}

void displayMemory()
{
    int i, start;

    printf("Memory Status:\n");

    for(i = 0; i < MAX_MEMORY; i++)
    {
        if(memory[i] == -1)
        {
            start = i;

            while(i < MAX_MEMORY && memory[i] == -1)
            {
                i++;
            }

            printf("Free memory block %d-%d\n", start, i - 1);
        }
    }
}

void allocateMemory(int processID, int size)
{
    int i, j;
    int start = -1;
    int count = 0;

    for(i = 0; i < MAX_MEMORY; i++)
    {
        if(memory[i] == -1)
        {
            if(start == -1)
            {
                start = i;
            }

            count++;

            if(count == size)
            {
                for(j = start; j < start + size; j++)
                {
                    memory[j] = processID;
                }

                printf("Allocated memory block %d-%d to Process %d\n",
                       start, start + size - 1, processID);

                return;
            }
        }
        else
        {
            start = -1;
            count = 0;
        }
    }

    printf("Memory allocation failed for Process %d\n", processID);
}

void releaseMemory(int processID)
{
    int i;

    for(i = 0; i < MAX_MEMORY; i++)
    {
        if(memory[i] == processID)
        {
            memory[i] = -1;
        }
    }

    printf("Memory released by Process %d\n", processID);
}

int main()
{
    initializeMemory();

    displayMemory();

    allocateMemory(1, 200);

    displayMemory();

    allocateMemory(2, 300);

    displayMemory();

    releaseMemory(1);

    displayMemory();

    allocateMemory(3, 400);

    displayMemory();

    return 0;
}
