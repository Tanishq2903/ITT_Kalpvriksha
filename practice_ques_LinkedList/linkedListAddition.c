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

node *additionFunction(node *head1, node *head2)
{
    node *newNode = NULL;
    node *temp = NULL;
    int carry = 0;
    int sum;
    while (head1 && head2)
    {
        sum = head1->data + head2->data + carry;
        carry = sum / 10;
        sum = sum % 10;
        if (newNode == NULL)
        {
            newNode = createNode(sum);
            temp = newNode;
        }
        else
        {
            temp->next = createNode(sum);
            temp = temp->next;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    if (head1)
    {
        sum = head1->data + carry;
        carry = sum / 10;
        sum = sum % 10;
        temp->next = createNode(sum);
        temp = temp->next;
    }

    else if (head2)
    {
        sum = head2->data + carry;
        carry = sum / 10;
        sum = sum % 10;
        temp->next = createNode(sum);
        temp = temp->next;
    }

    if (carry != 0)
    {
        temp->next = createNode(carry);
    }
    return newNode;
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
    char input1[200];
    char input2[200];
    printf("Enter elements of 1st Linked List: ");
    fgets(input1, sizeof(input1), stdin);
    input1[strcspn(input1, "\n")] = '\0';
    node *head1 = createLinkedList(input1);

    printf("Enter elements of 2nd Linked List: ");
    fgets(input2, sizeof(input2), stdin);
    input2[strcspn(input2, "\n")] = '\0';
    node *head2 = createLinkedList(input2);

    printf("Original List 1 : ");
    printList(head1);
    printf("Original List 2 : ");
    printList(head2);
    node *newHead = additionFunction(head1, head2);
    printf("After adding Lists: ");
    printList(newHead);
    return 0;
}