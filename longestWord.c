#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int helper(char string[]){
    int maximumLength = 0;
    int currentLength = 0;
    char *token = strtok(string," ");
    char *current = token;
    while(token != NULL){
        currentLength = strlen(token);
        if(maximumLength < currentLength){
            maximumLength = currentLength;
            current = token;
        }
        token = strtok(NULL," ");
    }
    printf("%s ",current);
    return maximumLength;
}

int main(){
char string[200];
scanf("%199[^\n]%*c",string);
int ans = helper(string);
printf("%d" ,ans);
    return 0;
}