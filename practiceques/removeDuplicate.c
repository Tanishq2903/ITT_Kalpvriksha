#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(){

    char str[51];
    scanf("%50[^\n]%*c", str);

    int array[26] = {0};
    int ARRAY[26] = {0};
    

    for(int index = 0 ; str[index] != '\0';index++){
        if(str[index] >= 'a' && str[index] <= 'z'){
               if(array[str[index] - 'a'] == 0){
                printf("%c" , str[index]);
                array[str[index] - 'a']++;
               }
        } 

        else if(str[index] >= 'A' && str[index] <= 'Z'){
               if(ARRAY[str[index] - 'A'] == 0){
                printf("%c" , str[index]);
                ARRAY[str[index] - 'A']++;
               }
        }
    }
    return 0;
}