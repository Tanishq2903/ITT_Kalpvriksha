#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    struct Node *next;
    int data;
} Node;

Node *createNode(int num)
{
    Node *newNode = (Node *)malloc(sizeof(Node *));
    newNode->data = num;
    newNode->next = NULL;
    return newNode;
}
Node *addNodeInLinkedList(Node *head, int num)
{
    if (head == NULL)
        head = createNode(num);
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = createNode(num);
    }
    return head;
}




Node *reverse(Node *head, int windowSize)
{
    if (head == NULL)
        return NULL;

    Node *prev = NULL;
    Node *temp = head;
    Node *next = head->next;

    Node *nextHead = head;
    for (int index = 0; index < windowSize - 1 && next != NULL; index++)
    {
        temp->next = prev;
        prev = temp;
        temp = next;
        next = next->next;
    }
    temp->next = prev;

    head = temp;

    nextHead->next = next;
    for (int index = 0; index < windowSize && next != NULL; index++)
    {
        prev = next;
        next = next->next;
    }

    if (prev)
        prev->next = reverse(prev->next, windowSize);

    return head;
}
void main()
{
    char string[100];
    fgets(string, sizeof(char) * 100, stdin);
    string[strcspn(string, "\n")] = '\0';

    Node *head = NULL;
    int windowSize;
    scanf("%d", &windowSize);
    int negative = 0;
    int num = 0;

    for (int index = 0; index <= strlen(string); index++)
    {
        if (string[index] == ' ' || string[index] == '\0')
        {
            if (negative)
                num *= -1;
            head = addNodeInLinkedList(head, num);
            num = 0;
            negative = 0;
        }
        else if (string[index] == '-')
        {
            negative = 1;
        }
        else if (string[index] >= '0' && string[index] <= '9')
        {
            num *= 10;
            num += string[index] - '0';
        }
    }
    head = reverse(head, windowSize);
  Node* temp = head;
  while(temp){
    printf("%d ",temp -> data);
    temp = temp -> next;
  }
}
