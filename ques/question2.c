
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>





int noDuplicate(char *string1, char *string2)
{
    int arr[26] = {0};
    for (int iterator = 0; iterator < strlen(string1); iterator++)
    {
        arr[string1[iterator] - 'a']++;
    }

    for (int iterator = 0; iterator < strlen(string2); iterator++)
    {
        if (arr[string2[iterator] - 'a'] != 0)
            return 0;
    }
    return 1;
}

int main()
{
    int result = 0;
    int size = 10;
    char input[10000];

    char **arr;
    arr = (char **)malloc(sizeof(char *) * size);

    for (int iterator = 0; iterator < size; iterator++)
    {
        arr[iterator] = (char *)malloc(sizeof(char) * 20);
    }

    scanf("%[^\n]%*c", input);
    int index = 0;

    int start = 0;
    for (int iterator = 0; iterator < strlen(input); iterator++)
    {
        if (input[iterator] == ' ' || input[iterator] == '\0')
        {
            strncpy(arr[index], input + start, iterator - start);
            start = iterator + 1;
            index++;
        }
    }

    for (int iterator = 0; iterator < index - 1; iterator++)
    {
        for (int iterator2 = iterator + 1; iterator2 < index; iterator2++)
        {
            if (noDuplicate(arr[iterator], arr[iterator2]))
            {
                result = result > (strlen(arr[iterator]) * strlen(arr[iterator2])) ? result : (strlen(arr[iterator]) * strlen(arr[iterator2]));
            }
        }
    }

    printf("%d", result);
    return 0;
}
