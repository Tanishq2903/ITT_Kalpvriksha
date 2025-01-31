#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
void push(Node **top, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}
int pop(Node **top)
{
    if (*top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    Node *temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}
int peek(Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}




void enqueue(Node **stack1, Node **stack2, int data)
{
    push(stack1, data);
}




int dequeue(Node **stack1, Node **stack2)
{
    if (*stack2 == NULL)
    {
        if (*stack1 == NULL)
        {
            printf("Queue is empty\n");
            return -1; 
        }
        while (*stack1 != NULL)
        {
            int data = pop(stack1);
            push(stack2, data);
        }
    }
    return pop(stack2);
}



void printQueue(Node *stack1, Node *stack2)
{
    if (stack1 == NULL && stack2 == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    Node *temp = stack2;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    temp = stack1;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}




int main()
{
    Node *stack1 = NULL;
    Node *stack2 = NULL;
    while (1)
    {
        int choice;
        printf("Enter choice : \nPress 1 to enqueue\nPress 2 to dequeue\nPress 3 to print the queue\nPress 4 to exit\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int data;
            printf("Enter data to enqueue: \n");
            scanf("%d", &data);
            enqueue(&stack1, &stack2, data);
        }
        else if (choice == 2)
        {
            int data = dequeue(&stack1, &stack2);
            if (data != -1)
            {
                printf("Dequeued element: %d\n", data);
            }
        }
        else if (choice == 3)
        {
            printf("Queue elements: ");
            printQueue(stack1, stack2);
        }
        else if (choice == 4)
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
