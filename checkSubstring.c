#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(){
   char string[200];
   char substring[50];
   printf("enter string: ");
   scanf("%199[^\n]%*c",string);
   printf("\nenter substring: ");
   scanf("%49[^\n]%*c",substring);

   int index = 0;
   int index1  = 0;
   int currIndex = 0;
   while(string[index] != '\0' && substring[index1] != '\0' ){
      if(string[index] == substring[index1]){
        currIndex = index;
        while(substring[index1] != '\0'){
            if(string[currIndex] == substring[index1]){
                currIndex++;
                index1++;
            }
            else {
                index1 = 0;
                currIndex = 0;
                break;
            }
        }
      }
      index++;
   }
    if(currIndex != 0){
        index -= 1;
        printf("%d",index);}
        
        else {
            index = -1;
            printf("%d",index);
        }

    return 0;
}