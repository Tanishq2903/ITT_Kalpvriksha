#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(){
  char string[10];

  scanf("%9[^\n]%*c",string);

  int index = 0;
  int number = 0;
  int negative = 0;
  if(string[0] == '-'){
    index = 1;
    negative++;}

  while(string[index] != '\0'){
    if(string[index] >= '0' && string[index] <= '9'){
        number = number*10 + string[index]-'0';
        index++;
    }
     else {
        number = 0;
        break;
        }
  }
if(number != 0 && negative == 1){
    number = number*-1;
}
printf("%d",number);

    return 0;
}