#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *createNode(int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void swapNode(node** head, node* prev, node* curr) {
    if (curr == NULL || curr->next == NULL) {
        return;
    }

    node* nextNode = curr->next;

    if (prev != NULL) {
        prev->next = nextNode;
    } else {
        *head = nextNode;
    }

    curr->next = nextNode->next;
    nextNode->next = curr;
}

node* bubbleSort(node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    int swapped;
    node* temp;
    
    do {
        swapped = 0;
        temp = head;
        node* prev = NULL;

        while (temp != NULL && temp->next != NULL) {
            if (temp->data > temp->next->data) {
                swapNode(&head, prev, temp);
                swapped = 1;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

    } while (swapped);

    return head;
}

node* createLinkedList(char* input) {
    node *head = NULL;
    node *temp = NULL;

    char *token = strtok(input, " ");

    while (token != NULL) {
        int num = atoi(token);

        if (head == NULL) {
            head = createNode(num);
            temp = head;
        } else {
            temp->next = createNode(num);
            temp = temp->next;
        }

        token = strtok(NULL, " ");
    }

    return head;
}

int main() {
    printf("Enter elements of Linked List: ");
    
    char input[200];
    fgets(input, sizeof(input), stdin);
    
    input[strcspn(input, "\n")] = '\0';
    node *head = createLinkedList(input);

    printf("Original List: ");
    printList(head);
    
    node* newhead = bubbleSort(head);
    
    printf("Sorted List: ");
    printList(newhead);

    return 0;
}
