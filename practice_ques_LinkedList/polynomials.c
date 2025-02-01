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
        printf("%dx^%d ", temp->coeffecient, temp->exponents);
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
node *polynomialAdd(node *head1, node *head2)
{
    node *newNode = NULL;
    node *temp = NULL;
    int carry = 0;
    int sum;
    while (head1 && head2)
    {
        if (head1->exponents == head2->exponents)
        {
            insertNode(&newNode, &temp, head1->coeffecient + head2->coeffecient, head1->exponents);
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->exponents > head2->exponents)
        {
            insertNode(&newNode, &temp, head1->coeffecient, head1->exponents);

            head1 = head1->next;
        }
        else if (head1->exponents < head2->exponents)
        {
            insertNode(&newNode, &temp, head2->coeffecient, head2->exponents);

            head2 = head2->next;
        }
    }

    if (head1)
    {
        temp->next = head1;
    }
    else
    {
        temp->next = head2;
    }

    return newNode;
}

node *createLinkedList(char *input)
{
    node *head = NULL;
    node *temp = NULL;
    int index = 0;
    int coeffecient = INT_MAX;
    int exponent = INT_MAX;
    while (input[index] != '\0')
    {

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

    node *newHead = polynomialAdd(head1, head2);
    printf("After adding Lists: ");
    printList(newHead);
    return 0;
}