#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(){
    char string[20];
    scanf("%19[^\n]%*c",string);
    int count;
    int index = 0;
    while(string[index] != '\0'){
        char ch = string[index];
        count = 1;
        index++;
        while(string[index] == ch){
            count++;
            index++;
        }

      if(count >1){
        
        printf("%c%d",ch,count);

      }
      else{
        printf("%c",ch);
      }

    }
    return 0;
}