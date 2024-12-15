#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int precedence(char operator)
{
    if (operator== '+' || operator== '-')
        return 1;
    else
        return 2;
}


int calculations(int num, int num1, char operator)
{
    
    if (operator== '+')
    {
        return num + num1;
    }
    else if (operator== '-')
    {
        return num - num1;
    }
    else if (operator== '*')
    {
        return num * num1;
    }
    else if (operator== '/')
    {
        if (num1 != 0)
        {
           return  num / num1;
        }
        else
        {
            printf("error:Division by zero");
            return -1;
        }
    }
    return 0;
}

int calculateString(char *expression)
{
    int ans = 0;
    int number = 0;
    int numbersarray[100];
    char operatorarray[100];
    int numtop = 0;
    int operatortop = -1;
    int i = 0;
    while (i < strlen(expression))
    {
        if (isdigit(expression[i]))
        {
            int num = 0;
            while (i < strlen(expression) && isdigit(expression[i]))
            {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            numbersarray[numtop++] = num;
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
        {
            if (i == 0 || !isdigit(expression[i-1]) )
            {
                printf("invalid string");
                return -1;
            }
            while (operatortop >= 0 && precedence(expression[i]) <= precedence(operatorarray[operatortop]))
            {
                ans = calculations(numbersarray[numtop - 2], numbersarray[numtop - 1], operatorarray[operatortop]);
                if(ans == -1)return -1;
                numbersarray[numtop - 2] = ans;
                numtop--;
                operatortop--;
            }
            operatorarray[++operatortop] = expression[i];
            i++;
        }
        else if (expression[i] == ' ')
        {
            i++;
        }
        else
        {
            printf("Please enter valid string");
            return -1;
        }
    }

    while (operatortop >= 0)
    {
        ans = calculations(numbersarray[numtop - 2], numbersarray[numtop - 1], operatorarray[operatortop]);
        if(ans == -1)return -1;
        numbersarray[numtop - 2] = ans;
        numtop--;
        operatortop--;
    }
    return numbersarray[0];
}

int main()
{
    char expression[200];
    printf("Enter the string :");
    scanf("%[^\n]s", expression); // this %[^\n]s means input is taken till new line
    int result = calculateString(expression);
    if(result == -1){
        printf("some error occured");
    }
    else printf("result: %d",result);
    return 0;
}
