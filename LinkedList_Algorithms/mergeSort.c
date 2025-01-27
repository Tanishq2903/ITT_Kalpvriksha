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



void printList(node* head){
    node* temp = head;
     while(temp != NULL){
        printf("%d ",temp ->data);
        temp = temp -> next;
     }

}

node* mergeList(node* head1 , node* head2){
   node* dummyNode = createNode(-1);
   node* temp = dummyNode;
   while(head1 && head2){
    if(head1->data > head2->data){
       temp -> next = head2;
       temp = temp->next;
       head2 = head2 -> next; 
    }
    else{
       temp -> next = head1;
       temp = temp->next;
       head1 = head1 -> next; 
    }


    if(head1){
    temp -> next = head1;
    }
    else if(head2){
     temp -> next = head2;
    }

    return dummyNode -> next;
   }
}
node* findMiddle(node* head , node* tail){
    node* fast = head;
    node* slow = head;
    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}
node* mergeSort(node* head , node* tail){
 if(head == NULL || head -> next == NULL)return head;
 node* middleNode = findMiddle(head,tail);
 node* leftHead = head;
 node* rightHead = middleNode -> next;
 middleNode -> next = NULL;

 node* left = mergeSort(leftHead,middleNode);
 node* right = mergeSort(rightHead,tail);
 return mergeList(left,right);
}









node *createLinkedList(char *input)
{
    node *head = NULL;
    node *temp = NULL;
    int inputIndex = 0;
    int negative = 0;
    while (input[inputIndex] != '\0')
    {
        if (input[inputIndex] == '-')
        {
            negative = 1;
            inputIndex++;
        }

        else if (isdigit(input[inputIndex]))
        {
            int num = 0;
            while (isdigit(input[inputIndex]))
            {
                num = num * 10 + (input[inputIndex] - '0');
                inputIndex++;
            }
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
            negative = 0;
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
    printList(head);
    head = mergeSort(head,NULL);
    printList(head);

   
    return 0;
}
