#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    Node *next;
} Node;

void pushInQueue(int data, Node **frontOfQueue, Node **lastOfQueue)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
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
void popFromQueue(Node **frontOfQueue, Node **lastOfQueue)
{
    if (*frontOfQueue == NULL)
    {
        printf("queue is already empty\n");
        return;
    }
    Node *temp = *frontOfQueue;
    printf("Deleted element: %d\n", temp->data);
    *frontOfQueue = (*frontOfQueue)->next;
    if (*frontOfQueue == NULL)
    {
        *lastOfQueue = NULL;
    }
    free(temp);
}
void peekOnQueue(Node *frontOfQueue)
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
void printQueueElements(Node *frontOfQueue)
{
    if (frontOfQueue == NULL)
    {
        printf("queue is already empty\n");
        return;
    }
    Node *temp = frontOfQueue;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    Node *frontOfQueue = NULL;
    Node *lastOfQueue = NULL;
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
            pushInQueue(data, &frontOfQueue, &lastOfQueue);
        }
        else if (choice == 2)
        {
            popFromQueue(&frontOfQueue, &lastOfQueue);
        }
        else if (choice == 3)
        {
            peekOnQueue(frontOfQueue);
        }
        else if (choice == 4)
        {
            printQueueElements(frontOfQueue);
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
