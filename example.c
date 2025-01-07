#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long helper(long base,long exponent,long modulus){
   long result = 1;

   base = base%modulus;//to make base smaller than modulus for less large number calculations
   while(exponent > 0){
      
      if(exponent % 2 !=0){
         result = (result*base)%modulus;
      }
      
      
base = (base*base)%modulus;
       exponent /= 2;
         
               
      
   }
   return result;
}

int main(){

   long base;
   long exponent;
   long modulus;
   printf("Enter base");
   scanf("%ld",&base);
   printf("Enter exponent");
   scanf("%ld",&exponent);
   printf("Enter modulus");
   scanf("%ld",&modulus);



    int result = helper(base,exponent,modulus);
    printf("%ld",result);
    return 0;
}
