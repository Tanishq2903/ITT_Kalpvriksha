
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void printValue(Node *head, int windowSize, int currentLength)
{

    int sum = 0;
    Node *temp = head;
    if (currentLength <= windowSize)
    {
        while (temp != NULL)
        {
            sum += temp->data;
            temp = temp->next;
        }
    }//IF LINKED LIST LENGTH IS LESS THAN WINDOW THAN IT WILL SUM UP ALL ELEMENTS OF LINKED LIST AND PRINT IT

    else
    {
        for (int iteration = 0; iteration < currentLength - windowSize; iteration++)
        {
            temp = temp->next;
        } //TO TAKE TEMP TO NODE FROM WHERE WE WANT TO START ADDING VALUES IN SUM
        while (temp != NULL)
        {
            sum += temp->data;
            temp = temp->next;
        }
    }
    printf("%d", sum);
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

int main()
{
    Node *head = NULL;
    Node *curr = NULL;
    int numberofOperations, windowSize, currentLength = 0;
    scanf("%d %d", &numberofOperations, &windowSize);
    getchar();
    int iteration = 0;
    char query;

    while (iteration < numberofOperations)
    {
        scanf("%c", &query);
        getchar();

        if (query == 'A')
        {
            int data;
            scanf("%d", &data);
            getchar();
            if (head == NULL)
            {
                head = createNode(data);
                curr = head;
                currentLength++;
            }
            else
            {
                curr->next = createNode(data);
                curr = curr->next;
                currentLength++;
            }
        }

        else if (query == 'S')
        {
            printValue(head, windowSize, currentLength);
        }
        iteration++;
    }
    return 0;
}
