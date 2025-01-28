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
node* insertAtEnd(node* head, node* newNode) {
   if (head == NULL) {
       head = newNode;
   } else {
       node* temp = head;
       while (temp->next != NULL) {
           temp = temp->next;
       }
       temp->next = newNode;
   }
   return head;
}
node* helperFunction(node* head) {
   node* evenHead = NULL;
   node* oddHead = NULL;
   node* evenTail = NULL;
   node* oddTail = NULL;
   node* temp = head;
   while (temp != NULL) {
       node* newNode = createNode(temp->data);
       if (temp->data % 2 == 0) {
           evenHead = insertAtEnd(evenHead, newNode);
           if (evenTail == NULL) {
               evenTail = evenHead;
           } else {
               evenTail->next = newNode;
               evenTail = newNode;
           }
       } else {
           oddHead = insertAtEnd(oddHead, newNode);
           if (oddTail == NULL) {
               oddTail = oddHead;
           } else {
               oddTail->next = newNode;
               oddTail = newNode;
           }
       }
       temp = temp->next;
   }
   if (evenTail) {
       evenTail->next = oddHead;
       return evenHead;
   }
   return oddHead;
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
   node* newHead = helperFunction(head);
   printf("Manipulated List: ");
   printList(newHead);
   return 0;
}