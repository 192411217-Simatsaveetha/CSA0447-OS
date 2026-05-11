// C Program for Best Fit Memory Management

#include <stdio.h>

int main()
{
    int blockSize[10], processSize[10], allocation[10];
    int m, n;
    int i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter size of each memory block:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter size of each process:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &processSize[i]);
    }

    // Initialize allocation array
    for(i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }

    // Best Fit Algorithm
    for(i = 0; i < n; i++)
    {
        int bestIdx = -1;

        for(j = 0; j < m; j++)
        {
            if(blockSize[j] >= processSize[i])
            {
                if(bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                {
                    bestIdx = j;
                }
            }
        }

        // Allocate memory block
        if(bestIdx != -1)
        {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    // Display allocation
    printf("\nPROCESS\tPROCESS SIZE\tBLOCK NUMBER\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);

        if(allocation[i] != -1)
        {
            printf("%d\n", allocation[i] + 1);
        }
        else
        {
            printf("Not Allocated\n");
        }
    }

    return 0;
}
