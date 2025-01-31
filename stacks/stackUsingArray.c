#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void pushInStack(int data, int *top, int maxSize, int *stack)
{
    if ((*top) == maxSize - 1)
    {
        printf("Stack overflow \n");
        return;
    }
    stack[++(*top)] = data;
}

void popFromStack(int *top, int *stack)
{
    if ((*top) == -1)
    {
        printf("Stack is already empty\n");
        return;
    }
    printf("Popped item : %d\n", stack[(*top)]);
    (*top)--;
}

void peekOnStack(int *top, int *stack)
{
    if ((*top) == -1)
    {
        printf("Stack is already empty\n");
        return;
    }
    printf("%d\n", stack[(*top)]);
}

void printStackElements(int *top, int *stack)
{
    int index = *top;
    while (index >= 0)
    {
        printf("%d \n", stack[index]);
        index--;
    }
    printf("\n");
}
int main()
{
    int maxSize;
    printf("Enter maximum size of stack: \n");
    scanf("%d", &maxSize);
    int stack[maxSize];
    int topOfStack = -1;
    while (1)
    {
        int choice;
        printf("Enter choice : \nPress 1 to push in stack\nPress 2 to pop from stack\nPress 3 to peek on stack\nPress 4 to print the elements of stack\nPress 5 to exit\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int data;
            printf("Enter data to push: \n");
            scanf("%d", &data);
            pushInStack(data, &topOfStack, maxSize, &stack[0]);
        }
        else if (choice == 2)
        {
            popFromStack(&topOfStack, &stack[0]);
        }
        else if (choice == 3)
        {
            peekOnStack(&topOfStack, &stack[0]);
        }
        else if (choice == 4)
        {
            printStackElements(&topOfStack, &stack[0]);
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