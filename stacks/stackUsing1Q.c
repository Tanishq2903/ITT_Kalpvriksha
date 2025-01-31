#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
void enqueue(Node **front, Node **rear, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*rear == NULL)
    {
        *front = *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}
int dequeue(Node **front)
{
    if (*front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    Node *temp = *front;
    int data = temp->data;
    *front = (*front)->next;
    if (*front == NULL)
    {
        printf("Queue is empty\n");
    }
    free(temp);
    return data;
}
int front(Node *front)
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}
void pushToStack(int data, Node **front, Node **rear)
{
    enqueue(front, rear, data);
    for (Node *temp = *front; temp != NULL && temp->next != NULL; temp = temp->next)
    {
        int dequeuedData = dequeue(front);
        enqueue(front, rear, dequeuedData);
    }
}
void popFromStack(Node **front)
{
    if (*front == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    int data = dequeue(front);
    printf("Popped element: %d\n", data);
}
void peekStack(Node *front)
{
    if (front == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", front->data);
}
void printStackElements(Node *front)
{
    if (front == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    Node *front = NULL;
    Node *rear = NULL;
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
            pushToStack(data, &front, &rear);
        }
        else if (choice == 2)
        {
            popFromStack(&front);
        }
        else if (choice == 3)
        {
            peekStack(front);
        }
        else if (choice == 4)
        {
            printf("Stack elements: ");
            printStackElements(front);
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
