#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h>

typedef struct Node
{
    int data;
    char *condition;
    struct Node *next;
} Node;

Node *createNode(int data, char *condition)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->condition = condition;
    newNode->next = NULL;
    return newNode;
}

Node *createList(int id, Node *head, char condition[])
{
    if (!head)
    {
        head = createNode(id, &condition[0]);
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = createNode(id, &condition[0]);
    }
    return head;
}

int main()
{
    printf("Enter number of patients");
    int numberOfPatients;
    Node *criticals = NULL;
    Node *seriouss = NULL;

    Node *stables = NULL;

    scanf("%d", &numberOfPatients);
    int patients[numberOfPatients];
    int index = 0;

    while (numberOfPatients > 0)
    {
        printf("\nenter id\n");
        int id;
        scanf("%d", &id);
        getchar();

        int idChecker = 0;

        for (int i = 0; i < index; i++)
        {
            if (patients[i] == id)
            {
                printf("you entered multiple id twice\n");
                idChecker = 1;
                break;
            }
        }

        int stringChecker = 0;

        do
        {
            if (idChecker == 0)//do if id is not repeated
            {
                printf("enter condition\n");
                char condition[20];
                fgets(condition, 19, stdin);
                condition[strcspn(condition, "\n")] = '\0';

                if (strcmp(condition, "critical") == 0)
                {
                    criticals = createList(id, criticals, &condition[0]);
                    stringChecker = 0;
                }

                else if (strcmp(condition, "serious") == 0)
                {
                    seriouss = createList(id, seriouss, &condition[0]);
                    stringChecker = 0;
                }
                else if (strcmp(condition, "stable") == 0)
                {
                    stables = createList(id, stables, &condition[0]);
                    stringChecker = 0;
                }
                else
                {
                    printf("you entered invalid string\n");
                    stringChecker = 1;
                }
            }

            else if (idChecker == 1) //if id is repeated then again take input for same patient
            {
                numberOfPatients++;
            }
        } while (stringChecker);//do until correct string is not entered

        patients[index] = id;
        index++;

        numberOfPatients--;
    }

    while (criticals)
    {
        printf("%d critical \n", criticals->data);
        criticals = criticals->next;
    }
    while (seriouss)
    {
        printf("%d serious \n", seriouss->data);
        seriouss = seriouss->next;
    }
    while (stables)
    {
        printf("%d stable \n", stables->data);
        stables = stables->next;
    }

    return 0;
}