#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void pushInQueue(int data, int *frontOfQueue, int maxSize, int *Queue, int *lastOfQueue)
{
    if ((*lastOfQueue) == -1)
    {
        Queue[++(*lastOfQueue)] = data;
        *frontOfQueue = *lastOfQueue;
        return;
    }
    else if ((*lastOfQueue) == maxSize - 1)
    {
        printf("Queue overflowed\n");
        return;
    }
    else
        Queue[++(*lastOfQueue)] = data;
}

void popFromQueue(int *lastOfQueue, int *frontOfQueue, int *Queue, int maxSize)
{
    if ((*frontOfQueue) == -1 || (*frontOfQueue) > (*lastOfQueue))
    {
        printf("queue is already empty\n");
        return;
    }

    printf("Deleted element: %d \n", Queue[(*frontOfQueue)]);

    if ((*frontOfQueue) == (*lastOfQueue))
    {
        (*frontOfQueue) = (*lastOfQueue) = -1;
    }

    else
        (*frontOfQueue) = (*frontOfQueue) + 1;
}

void peekOnQueue(int *frontOfQueue, int *Queue)
{
    if ((*frontOfQueue) == -1)
    {
        printf("queue is already empty\n");
    }
    else
    {
        printf("%d\n", Queue[(*frontOfQueue)]);
    }
}

void printQueueElements(int *frontOfQueue, int *Queue, int *lastOfQueue)
{
    for (int i = (*frontOfQueue); i <= (*lastOfQueue); i++)
    {
        printf("%d ", Queue[i]);
    }
    printf("\n");
}
int main()
{
    int maxSize;
    printf("Enter maximum size of Queue: \n");
    scanf("%d", &maxSize);
    int Queue[maxSize];
    int frontOfQueue = -1;
    int lastOfQueue = -1;
    while (1)
    {
        int choice;
        printf("Enter choice : \nPress 1 to push in Queue\nPress 2 to pop from Queue\nPress 3 to peek on Queue\nPress 4 to print the elements of Queue\nPress 5 to exit\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int data;
            printf("Enter data to push: \n");
            scanf("%d", &data);
            pushInQueue(data, &frontOfQueue, maxSize, &Queue[0], &lastOfQueue);
        }
        else if (choice == 2)
        {
            popFromQueue(&lastOfQueue, &frontOfQueue, &Queue[0], maxSize);
        }
        else if (choice == 3)
        {
            peekOnQueue(&frontOfQueue, &Queue[0]);
        }
        else if (choice == 4)
        {
            printQueueElements(&frontOfQueue, &Queue[0], &lastOfQueue);
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            printf("Please enter valid choice\n");
        }
    }
    return 0;
}