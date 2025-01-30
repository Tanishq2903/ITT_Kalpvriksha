#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void pushInQueue(int data, struct Node **frontOfQueue, struct Node **lastOfQueue)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*lastOfQueue == NULL)
    {
        *frontOfQueue = *lastOfQueue = newNode;
        return;
    }
    (*lastOfQueue)->next = newNode;
    *lastOfQueue = newNode;
}
void popFromQueue(struct Node **frontOfQueue, struct Node **lastOfQueue)
{
    if (*frontOfQueue == NULL)
    {
        printf("queue is already empty\n");
        return;
    }
    struct Node *temp = *frontOfQueue;
    printf("Deleted element: %d\n", temp->data);
    *frontOfQueue = (*frontOfQueue)->next;
    if (*frontOfQueue == NULL)
    {
        *lastOfQueue = NULL;
    }
    free(temp);
}
void peekOnQueue(struct Node *frontOfQueue)
{
    if (frontOfQueue == NULL)
    {
        printf("queue is already empty\n");
    }
    else
    {
        printf("%d\n", frontOfQueue->data);
    }
}
void printQueueElements(struct Node *frontOfQueue)
{
    if (frontOfQueue == NULL)
    {
        printf("queue is already empty\n");
        return;
    }
    struct Node *temp = frontOfQueue;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void pushToStack(int data, struct Node **q1Front, struct Node **q1Last, struct Node **q2Front, struct Node **q2Last)
{
    pushInQueue(data, q1Front, q1Last);
}
void popFromStack(struct Node **q1Front, struct Node **q1Last, struct Node **q2Front, struct Node **q2Last)
{
    if (*q1Front == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    while ((*q1Front)->next != NULL)
    {
        int tempData = (*q1Front)->data;
        popFromQueue(q1Front, q1Last);
        pushInQueue(tempData, q2Front, q2Last);
    }
    printf("Popped element: %d\n", (*q1Front)->data);
    popFromQueue(q1Front, q1Last);
    while (*q2Front != NULL)
    {
        int tempData = (*q2Front)->data;
        popFromQueue(q2Front, q2Last);
        pushInQueue(tempData, q1Front, q1Last);
    }
}
void peekStack(struct Node *q1Front)
{
    if (q1Front == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", q1Front->data);
}
int main()
{
    struct Node *q1Front = NULL;
    struct Node *q1Last = NULL;
    struct Node *q2Front = NULL;
    struct Node *q2Last = NULL;
    while (1)
    {
        int choice;
        printf("Enter choice : \nPress 1 to push in Stack\nPress 2 to pop from Stack\nPress 3 to peek on Stack\nPress 4 to print the elements of Stack\nPress 5 to exit\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int data;
            printf("Enter data to push: \n");
            scanf("%d", &data);
            pushToStack(data, &q1Front, &q1Last, &q2Front, &q2Last);
        }
        else if (choice == 2)
        {
            popFromStack(&q1Front, &q1Last, &q2Front, &q2Last);
        }
        else if (choice == 3)
        {
            peekStack(q1Front);
        }
        else if (choice == 4)
        {
            
            printQueueElements(q1Front);
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            printf("Please enter a valid choice\n");
        }
    }
    return 0;
}
