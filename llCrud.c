#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtBeginning(int value, Node **head)
{
    if (*head == NULL)
    {
        *head = createNode(value);
    }
    else
    {
        Node *temp = createNode(value);
        temp->next = *head;
        *head = temp;
    }
   
}

void insertAtLast(int value, Node **head)
{
    if (!*head)
    {
        *head = createNode(value);
    }
    else
    {
        Node *temp = createNode(value);
        Node *newHead = *head;
        while (newHead->next != NULL)
        {
            newHead = newHead->next;
        }
        newHead->next = temp;
    }
   
}

void insertAtPosition(int value, Node **head, int position)
{
    if (position == 1)
    {
      insertAtBeginning(value, head);
    }
    else
    {
        int flag = 0;
        int currentPosition = 1;
        Node *temp = *head;
        while (currentPosition < position - 1)
        {
            temp = temp->next;
            currentPosition++;
            if (!temp)
            {
                flag = 1;
                printf("Invalid position entered\n");
                break;
            }
        }

        if (flag == 0)
        {
            Node *newNode = createNode(value);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
   
}

void deleteAtBeginning(Node **head)
{
    if (!(*head))
    {
        printf("No elements to delete");
    }
    else if ((*head)->next == NULL)
    {
        *head = NULL;
    }
    else if ((*head)->next != NULL)
    {
        Node *temp = (*head)->next;
        (*head) = temp;
    }

    
}
void deleteAtPosition(Node **head, int position)
{
    if (position == 1)
    {
        deleteAtBeginning(head);
        return ;
    }
    if (!head)
    {
        printf("No elements to delete");
    }
    else
    {
        Node *temp = *head;
        int currentPosition = 1;
        int flag = 0;
        while (currentPosition != position - 1)
        {
            currentPosition++;
            temp = temp->next;
            if (!temp)
            {
                printf("Invalid");
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            if (temp->next == NULL)
            { // to check if user want to remove position next to last node as we are running while loop to position minus 1
                printf("Invalid");
            }
        }
        else if (flag != 1)
        { // it means the position given by user is out of bound
            if (temp->next->next != NULL)
            {
                temp->next = temp->next->next;
            }
            else
                temp->next = NULL;
        }
    }
   
}

void DeleteAtLast(Node **head)
{

    if (!(*head))
    {
        printf("No elements to delete");
    }
    else
    {
        Node *temp = (*head);
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }

    
}

void updateAtPosition(int value, Node **head, int position)
{
    if (!(*head))
    {
        printf("Invalid");
    }

    else
    {
        int flag = 0;
        Node *temp = *head;
        int currentPosition = 1;
        while (currentPosition < position)
        {
            temp = temp->next;
            currentPosition++;
            if (!temp)
            {
                printf("Invalid");
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            temp->data = value;
        }
    }
   
}

int main()
{
    int numberOfOperations;
    printf("Enter number of operations:");
    scanf("%d", &numberOfOperations);
    Node *head = NULL;

    while (numberOfOperations)
    {
        printf("1 Add new node to the end\n2  Add new node at the beginning\n3  Add new node at position \n4  Display all node\n5 Update the node at position \n6 Delete the first node\n7  Delete the last node\n8 Delete the node at position \n");
        int operation = 0;
        scanf("%d", &operation);

        int value = 0, position = 0;
        switch (operation)
        {
        case 1:
            printf("Enter Value:");
            scanf("%d", &value);
             insertAtLast(value, &head);
            break;
        case 2:
            printf("Enter Value:");
            scanf("%d", &value);
          insertAtBeginning(value, &head);
            break;
        case 3:
            printf("Enter Value and index:");
            scanf("%d %d", &value, &position);
           insertAtPosition(value, &head, position);
            break;
        case 4:
            display(head);
            break;
        case 5:
            printf("Enter Value and index:");
            scanf("%d %d", &value, &position);
             updateAtPosition(value, &head, position);
            break;
        case 6:
            deleteAtBeginning(&head);
            break;
        case 7:
             DeleteAtLast(&head);
            break;
        case 8:
            printf("Enter index:");
            scanf("%d", &position);
           deleteAtPosition(&head, position);
            break;
        default:
            printf("Invalid Input\n");
            break;
        }
        numberOfOperations--;
    }
    return 0;
}
