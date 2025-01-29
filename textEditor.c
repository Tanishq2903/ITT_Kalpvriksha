#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *editString(char *string)
{
    int counter = 0;
    for (int index = 0; index < strlen(string); index++)
    {
        if (string[index] == '#' && counter == 0)
            continue;
        else if (string[index] == '#' && counter > 0)
        {
            counter--;
            continue;
        }
        string[counter++] = string[index];
    }
    string[counter] = '\0';
    return string;
}
int main()
{
    char *string1 = (char *)malloc(200 * sizeof(char));

    char *string2 = (char *)malloc(200 * sizeof(char));

    printf("Enter first string: \n");
    scanf("%199[^\n]%*c", string1);
    printf("Enter second string: \n");

    scanf("%199[^\n]%*c", string2);

    string1 = editString(string1);
    string2 = editString(string2);

    if (strcmp(string1, string2) == 0)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    return 0;
}