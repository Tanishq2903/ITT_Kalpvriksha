
#include <stdio.h>

#include <string.h>

void nonRepeating(char *input, int end)
{
    int arr[26] = {0};
    for (int iterator = 0; iterator <= end; iterator++)
    {

        arr[input[iterator] - 'a']++;
    }

    for (int iterator = 0; iterator < 26; iterator++)
    {
        if (arr[iterator] == 1)
        {
            int characterInInteger = 'a' + iterator;
            printf("%c", characterInInteger);
            return;
        }
    }
    printf("-1");
}

int main()
{

    char input[100];
    scanf("%[^\n]%*c", input);
    for (int iterator = 0; iterator < strlen(input); iterator++)
    {
        nonRepeating(input, iterator);
    }

    return 0;
}