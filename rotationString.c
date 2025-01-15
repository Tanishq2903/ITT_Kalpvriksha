#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void rotationCheck(char string[],char string1[]){
 if(strlen(string1) != strlen(string)){
        printf("False");
     }
     else{
        int index = 0;
        int index1 = 0;
        while(string[index] != '\0'){
            while(string[index] != string1[index1] && string1[index1] != '\0'){
                index1++;
            }
            if(string1[index1] == '\0'){
                printf("False");
                break;
            }
            else{
                while( string1[index1] != '\0'){
                  if(string[index] == string1[index1]){
                           index++;
                           index1++;
                  }
                  else {
                    break;
                  }
                }


                if(string1[index1] == '\0'){
                    index1 = 0;
                    while(string[index] != '\0'){
                      if(string[index] == string1[index1]){
                           index++;
                           index1++;
                  }  
                  else {
                    break;
                  }

                    }
                    if(string1[index1] != '\0'){
                        printf("True");
                    }
                }
               
            }
        }
     }
   
}


int main(){
    char string[51];
    scanf("%50[^\n]%*c", string);
    char string1[51];
    scanf("%50[^\n]%*c", string1);
    rotationCheck(string,string1);
    return 0;
}



