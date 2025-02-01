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

void printList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

node *insertionSort(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *sorted = NULL;
    node *current = head;
    while (current != NULL)
    {
        node *next = current->next;
        if (sorted == NULL || sorted->data >= current->data)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            node *temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }

    return sorted;
}

node *createLinkedList(char *input)
{
    node *head = NULL;
    node *temp = NULL;

    char *token = strtok(input, " ");

    while (token != NULL)
    {
        int num = atoi(token);

        if (head == NULL)
        {
            head = createNode(num);
            temp = head;
        }
        else
        {
            temp->next = createNode(num);
            temp = temp->next;
        }

        token = strtok(NULL, " ");
    }

    return head;
}

int main()
{
    printf("Enter elements of Linked List: ");

    char input[200];
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';
    node *head = createLinkedList(input);

    printf("Original List: ");
    printList(head);

    node *newhead = insertionSort(head);

    printf("Sorted List: ");
    printList(newhead);

    return 0;
}
