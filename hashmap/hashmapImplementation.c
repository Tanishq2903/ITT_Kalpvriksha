#include <stdio.h>
#include <stdlib.h>

#define size 10

typedef struct node
{
    int key;
    int value;
    struct node *next;
} node;

node **hashMap;

node *createNode(int key, int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

int hashcode(int key)
{
    return key % size;
}

void insertInMap(int key, int value)
{
    int index = hashcode(key);
    if (hashMap[index] == NULL)
    {
        hashMap[index] = createNode(key, value);
    }
    else
    {
        node *temp = hashMap[index];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                temp->value = value;
                return;
            }
            if (temp->next == NULL)
                break;
            temp = temp->next;
        }
        temp->next = createNode(key, value);
    }
}

void removeFromMap(int keyValue)
{
    int index = hashcode(keyValue);
    node *temp = hashMap[index];
    node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->key == keyValue)
        {
            if (prev == NULL)
            { // Remove the first node
                hashMap[index] = temp->next;
            }
            else
            { // Remove from middle or end
                prev->next = temp->next;
            }
            printf("Element deleted\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Key not found\n");
}

void searchInMap(int keytoSearch)
{
    int index = hashcode(keytoSearch);
    node *temp = hashMap[index];
    while (temp != NULL)
    {
        if (temp->key == keytoSearch)
        {
            printf("Value is %d\n", temp->value);
            return;
        }
        temp = temp->next;
    }
    printf("Key is not present\n");
}

void print()
{
    for (int index = 0; index < size; index++)
    {
        node *temp = hashMap[index];
        if (temp != NULL)
        {
            while (temp != NULL)
            {
                printf("key : %d value : %d", temp->key, temp->value);
                temp = temp->next;
            }
        }
        printf("\n");
    }
}

int main()
{
    hashMap = (node **)calloc(size, sizeof(node *));
    printf("Operations:\n");
    printf("1: Insert\n");
    printf("2: Remove\n");
    printf("3: Search\n");
    printf("4: Print \n");
    printf("5: Exit\n");

    int exit = 0;
    while (!exit)
    {
        printf("enter your choice:");
        int operation = 0;
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
        {
            printf("Enter key to insert:\n");
            int key;
            int value;
            scanf("%d", &key);
            printf("Enter value to insert:\n");
            scanf("%d", &value);

            insertInMap(key, value);
            break;
        }
        case 2:
        {
            printf("Enter key to delete:\n");
            int keyValue;
            scanf("%d", &keyValue);
            removeFromMap(keyValue);
            break;
        }
        case 3:
        {
            printf("Enter key to search:\n");
            int keytoSearch;
            scanf("%d", &keytoSearch);
            searchInMap(keytoSearch);
            break;
        }
        case 4:
            print();
            break;
        case 5:
            exit = 1;
            break;
        default:
            printf("Invalid\n");
            break;
        }
    }
    return 0;
}
