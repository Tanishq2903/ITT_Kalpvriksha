#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int isEmpty(node **stack)
{
    if (*stack == NULL)
        return 1;
    return 0;
}

void pushInStack(int data, node **stack)
{
    if (isEmpty(stack))
    {
        *stack = createNode(data);
        return;
    }
    else
    {
        node *temp = createNode(data);
        temp->next = *stack;
        *stack = temp;
    }
}

void popFromStack(node **stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is already empty\n");
        return;
    }
    else
    {
        node *temp = *stack;
        printf("Popped item : %d \n", temp -> data);
        *stack = (*stack)->next;
        
    }
}

void peekOnStack(node **stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("%d\n", (*stack)->data);
    }
}

void printStackElements(node **stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return;
    }
    node *temp = *stack;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    node *stack = NULL;
    while(1){
        int choice ;
        printf("Enter choice : \nPress 1 to push in stack\nPress 2 to pop from stack\nPress 3 to peek on stack\nPress 4 to print the elements of stack\nPress 5 to exit\n");
        scanf("%d",&choice);
       
         if(choice == 1){
            int data;
            printf("Enter data to push: \n");
            scanf("%d",&data);
            pushInStack(data,&stack);
            
        }
        else if(choice == 2){
              popFromStack(&stack);
              
        }
        else if(choice == 3){
            peekOnStack(&stack);
            
        }
        else if(choice == 4){
            printStackElements(&stack);
        }
       else if(choice == 5){
            break;
        }
        else{
            printf("Please enter valid choice\n");
            }
        
    }
    return 0;
}