#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<ctype.h>

typedef struct Node
{
    int data;
    char *condition;
    struct Node *next;
} Node;

Node* createNode(int data,char *condition){
Node* newNode = (Node*)malloc(sizeof(Node));
newNode -> data = data;
newNode -> condition = *condition;
newNode -> next = NULL;
return newNode;
}
Node* createList(int id ,Node* head , char condition[] ){
        if(!head){
          head = createNode(id,&condition[0]);
        }
        else{
            Node* temp = head;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = createNode(id,&condition[0]);
        }
        return head;
}


int main(){
    printf("Enter number of patients");
    int numberOfPatients;
    Node* criticals = NULL;
        Node* seriouss = NULL;

    Node* stables = NULL;


    scanf("%d",&numberOfPatients);
     while(numberOfPatients >= 0){
        int id;
        char condition[20];
        scanf("%d",&id);
        fgets(condition,19,stdin);
        condition[strcspn(condition,"\n")] = '\0';
        
        if(strcmp(condition,"critical") == 0){
          criticals = createList(id,criticals,&condition[0]);
        }
        else if(strcmp(condition,"serious")){
seriouss = createList(id,seriouss,&condition[0]);
        }
        else{
     stables = createList(id,stables,&condition[0]);
        }
        numberOfPatients--;
     }



   while(seriouss){
    printf("%d %s",seriouss->data,seriouss -> condition);
   }


    return 0;
}