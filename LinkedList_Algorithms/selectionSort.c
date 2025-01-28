#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *createnode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
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

node *selectionSort(node *head)
{
   
    node* head1=head;
    node* head2=head;
    while(head1!=NULL){
        head2=head1->next;
        node* smallerNode=head1;
        while(head2!=NULL){
            if(head2->data<smallerNode->data){
                smallerNode=head2;
            }
            head2=head2->next;
        }
        int temp=head1->data;
        head1->data=smallerNode->data;
        smallerNode->data=temp;
        head1=head1->next;
    }
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
            head = createnode(num);
            temp = head;
        }
        else
        {
            temp->next = createnode(num);
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

    node *newhead = selectionSort(head);

    printf("Sorted List: ");
    printList(newhead);

    return 0;
}
