#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
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

void linearSearch(node *head, int value)
{
    node *temp = head;
    while (temp)
    {
        if (temp->data == value)
        {
            printf("\nnode with %d is present in this linked list", value);

            return;
        }
        else
            temp = temp->next;
    }
    printf("\nnode with %d is not present in this linked list", value);
}

node *midNode(node *head, node *tail)
{
    if (!head)
    {
        return NULL;
    }

    node *slow = head;
    node *fast = head;
    while (fast != tail && fast->next != tail)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

void binarySearch(node *head, int value, node *tail) // here to apply binary search the linked list must be sorted if not then we need to apply sorting first on linked list ofr which I made another program
{
    node *middle = midNode(head, tail);
    if (middle == NULL)
    {
        printf("\nnode with %d is not present in this linked list", value);
        return;
    }

    if (middle->data == value)
    {
        printf("\nnode with %d is present in this linked list", value);
        return;
    }

    else if (middle->data > value)
    {
        binarySearch(head, value, middle);  //recursion call 
    }
    else
        binarySearch(middle->next, value, tail);//recursion call we can also use infinite while loop instead of recursion for binary search
}

node *createLinkedList(char *input) {
    node *head = NULL;
    node *temp = NULL;
    
    int inputIndex = 0;
    int negative = 0;

    while (input[inputIndex] != '\0') {
        if (input[inputIndex] == '-') {
            negative = 1;
            inputIndex++;
        } else if (isdigit(input[inputIndex])) {
            int num = 0;

            while (isdigit(input[inputIndex])) {
                num = num * 10 + (input[inputIndex] - '0');
                inputIndex++;
            }

            if (negative) {
                num = -num;
                negative = 0;
            }

            if (head == NULL) {
                head = createNode(num);
                temp = head;
            } else {
                temp->next = createNode(num);
                temp = temp->next;
            }
        }
        inputIndex++;
    }
    
    return head;
}

int main()
{
    printf("Enter elements of Linked List : ");
    char input[200];
    fgets(input, 199, stdin);
    input[strcspn(input, "\n")] = '\n';
    node *head = createLinkedList(&input[0]);

    int searchingValue;
    int choice;

    while (1)
    {

        printf("\nEnter choice:\nPress 1 for linear searching\nPress 2 for binary searching\nPress 3 to exit\n");
        scanf("%d", &choice);
        if (choice == 1 || choice == 2)
        {
            printf("\nEnter value to search : ");
            scanf("%d", &searchingValue);

            if (choice == 1)
            {
                linearSearch(head, searchingValue);
            }
            else if (choice == 2)
            {
                binarySearch(head, searchingValue, NULL);
            }
        }

        else if (choice == 3)
        {
            break;
        }
        else
        {
            printf("You entered invalid choice\n");
        }
    }
    return 0;
}
