#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int calculations(int i, int j, char ch){
    if (ch == '+'){
        return i + j;
    }
    else if (ch == '-'){
        return i - j;
    }
    else if (ch == '*'){
        return i * j;
    }
    else if (ch == '/' && j != 0){
        return i / j;
    }
    else if (ch == '/' && j == 0){
        printf("Error:Division by zero");
        exit(1);
    }
    return 0;
}

int pre(char op){
    if (op =='+' || op == '-'){
            return 1;
            }
    if (op =='*' || op =='/'){    
        return 2;
        }
    return 0;
}

int cal(char *str){
    int digits[100];
    char operators[30];
    int d = 0;
    int o = -1;

    int i = 0;

 while (i < strlen(str)) {
        if (str[i] == ' '){
            i++;
            continue;
        } if (isdigit(str[i])){
            int cur = 0;
            while (i < strlen(str) && isdigit(str[i])){
                cur = cur * 10 + (str[i] - '0');
                i++;
            }
            digits[d] = cur;
            d++;
        }else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            while (o >= 0 && pre(operators[o]) >= pre(str[i])) {
                int first = digits[--d];
                int second = digits[--d];
                char operation = operators[o--];
                digits[d] = calculations(first, second, operation);
                d++;
            }
            o++;
            operators[o] = str[i];
            i++;
        }else{
            printf("Error: Invalid expression");
            exit(1);
        }
    } while (o != -1){
        int first = digits[--d];
        int second = digits[--d];
        char operation = operators[o--];
        digits[d] = calculations(first, second, operation);
        d++;
    }
    return digits[d - 1];
}

int main(){
    printf("Please enter the string");
    char exp[200];
    scanf("%[^\n]",exp);
   int ans = cal(exp);
   printf("%d", ans);

    return 0;
}

