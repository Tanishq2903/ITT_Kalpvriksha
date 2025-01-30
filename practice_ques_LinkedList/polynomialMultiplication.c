#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
typedef struct node
{
    int coeffecient;
    struct node *next;
    int exponents;
} node;

node *createNode(int coeffecient, int exponent)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->coeffecient = coeffecient;
    newNode->next = NULL;
    newNode->exponents = exponent;
    return newNode;
}

node *mergeList(node *head1, node *head2)
{
    node *dummyNode = createNode(-1, -1);
    node *temp = dummyNode;

    while (head1 && head2)
    {
        if (head1->exponents > head2->exponents)
        {
            temp->next = head1;
            head1 = head1->next;
        }
        else
        {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }

    if (head1)
    {
        temp->next = head1;
    }
    else if (head2)
    {
        temp->next = head2;
    }

    return dummyNode->next;
}

node *findMiddle(node *head)
{
    node *fast = head->next;
    node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

node *mergeSort(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    node *middleNode = findMiddle(head);
    node *leftHead = head;
    node *rightHead = middleNode->next;
    middleNode->next = NULL;

    node *leftSorted = mergeSort(leftHead);
    node *rightSorted = mergeSort(rightHead);

    return mergeList(leftSorted, rightSorted);
}

void printList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->coeffecient >= 1)
        {
            printf(" %d", temp->coeffecient);
        }
        if (temp->exponents > 1)
            printf("x^");
        if (temp->exponents == 1)
            printf("x ");
        if (temp->exponents > 1)
        {
            printf("%d ", temp->exponents);
        }
        temp = temp->next;
    }
    printf("\n");
}

void insertNode(node **newNode, node **temp, int coeffecient, int exponent)
{
    if (*newNode == NULL)
    {
        *newNode = createNode(coeffecient, exponent);

        *temp = *newNode;
    }
    else
    {
        (*temp)->next = createNode(coeffecient, exponent);
        *temp = (*temp)->next;
    }
}
void addingSameExponentValues(node **head)
{
    node *temp = *head;
    while (temp && temp->next)
    {
        if (temp->exponents == temp->next->exponents)
        {
            temp->coeffecient = temp->coeffecient + temp->next->coeffecient;
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
}
node *polynomialMultiplication(node *head1, node *head2)
{
    node *temp1 = head1;
    node *temp2 = head2;
    node *newNode = NULL;
    node *temp = NULL;
    while (temp1)
    {
        while (temp2)
        {
            int coeffecient = temp2->coeffecient * temp1->coeffecient;
            int exponent = temp2->exponents + temp1->exponents;

            if (newNode == NULL)
            {
                newNode = createNode(coeffecient, exponent);
                temp = newNode;
            }
            else
            {
                temp->next = createNode(coeffecient, exponent);
                temp = temp->next;
            }
            temp2 = temp2->next;
        }
        temp2 = head2;
        temp1 = temp1->next;
    }
    addingSameExponentValues(&newNode);
    return newNode;
}

node *createLinkedList(char *input)
{
    node *head = NULL;
    node *temp = NULL;
    int index = 0;
    int negative = 0;
    int coeffecient = INT_MAX;
    int exponent = INT_MAX;
    while (input[index] != '\0')
    {
        // if(input[index] == '-'){
        //      negative = 1;
        // }
        if (isdigit(input[index]))
        {
            int num = 0;
            while (isdigit(input[index]))
            {
                num = num * 10 + input[index] - '0';
                index++;
            }
            if (coeffecient == INT_MAX)
            {
                coeffecient = num;
            }
            else
            {
                exponent = num;
            }
        }
        if (coeffecient != INT_MAX && exponent != INT_MAX)
        {
            insertNode(&head, &temp, coeffecient, exponent);
            coeffecient = INT_MAX;
            exponent = INT_MAX;
        }

        index++;
    }
    return head;
}

int main()
{
    char input1[200];
    char input2[200];
    printf("Enter elements of 1st Linked List(coffecients and exponents space separated): ");
    fgets(input1, sizeof(input1), stdin);
    input1[strcspn(input1, "\n")] = '\0';
    node *head1 = createLinkedList(input1);

    printf("Enter elements of 2st Linked List(coffecients and exponents space separated):  ");
    fgets(input2, sizeof(input2), stdin);
    input2[strcspn(input2, "\n")] = '\0';
    node *head2 = createLinkedList(input2);

    head1 = mergeSort(head1);
    head2 = mergeSort(head2);

    printf("Original List 1 : ");
    printList(head1);
    printf("Original List 2 : ");
    printList(head2);

    node *newHead = polynomialMultiplication(head1, head2);
    printf("After multiplying Lists: ");
    printList(newHead);
    return 0;
}