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
node* insertNode(node* head,node* new_node){
    if(head==NULL){
        head=new_node;
    }
    else{
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        } 
        temp->next=new_node;
    }
    return head;
}
node *quickSort(node *head)
{
    if(head==NULL || head->next==NULL)
        return head;

    node* pivot=head;
    node* curr=head->next;
    node* prev=NULL;

    node* smaller=NULL;
    node* larger=NULL;

    while(curr && curr){
        if(curr->data > pivot->data)
            larger=insertNode(larger,curr);
        else
            smaller=insertNode(smaller,curr);

        prev=curr;
        curr=curr->next;
        prev->next=NULL;
    }

    smaller=quickSort(smaller);
    larger=quickSort(larger);

    pivot->next=larger;
    if(smaller){
        head=smaller;
        while(smaller->next)
            smaller=smaller->next;
        smaller->next=pivot;
    }
    else
        head=pivot;

    return head;

    
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

    node *newhead = quickSort(head);

    printf("Sorted List: ");
    printList(newhead);

    return 0;
}
