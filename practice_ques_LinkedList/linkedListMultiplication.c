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
int reverse(int num){
    int reversedNum = 0;
    while(num > 0){
        reversedNum =(reversedNum*10) +  (num%10);
        num = num/10;
    }
    return reversedNum;
    
}

node *multiplyFunction(node *head1, node *head2)
{
    int num1 = 0;
    int num2 = 0;
    while(head1){
        num1 = num1*10 + head1 ->data;
       head1 =  head1 -> next;
    }
    while(head2){
        num2 = num2*10 + head2 ->data;
        head2 = head2 -> next;
    }
    num1 = reverse(num1);
    num2 = reverse(num2);
    int result = reverse(num1*num2);
    node* newNode = NULL;
    node* temp = NULL;
    while(result > 0){
     if(newNode == NULL){
        newNode = createNode(result%10);
        temp = newNode;
     }
     else{
        temp -> next = createNode(result%10);
        temp = temp -> next;
     }

     result /= 10;
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
    node *newHead = multiplyFunction(head1, head2);
    printf("After adding Lists: ");
    printList(newHead);
    return 0;
}