#include <stdio.h>
#include<string.h>
#include<stdlib.h>
 
 
int main() {
   int noDuplicates = 0;
   int rows,cols;
   scanf("%d %d",&rows,&cols);
   char*** matrix = (char***)malloc(rows*sizeof(char**));
   for(int i = 0; i < rows;i++){
   matrix[i] = (char**)malloc(cols*sizeof(char*));
   }
  
   for(int i = 0 ; i < rows;i++){
   for(int j = 0 ; j < cols ; j++){
   matrix[i][j] = (char*)malloc(sizeof(char)*30);
    scanf("%s",matrix[i][j]);
    }
}
 
 
char name[50];
  for(int i = 0 ; i < rows;i++){
  for(int j = 0 ; j < cols ; j++){
  if(matrix[i][j] != NULL)strcpy(name,matrix[i][j]);
   int count = 0;
   for(int a = 0 ; a < rows ; a++){
       for(int b =0  ; b < cols ; b++){
           if(matrix[a][b] != NULL){
               if(strcmp(matrix[a][b] , name) == 0){
              matrix[a][b] = NULL;
               count++;
           }
           }
       } //b loop ends here
   } //a loop ends here

 if(count > 1) printf("%s -%d\n" , name,count);
 else noDuplicates++;
    
  } //j loop ends here
}//first i loop ends here
  
if(noDuplicates == rows*cols)printf("No duplicates found");
 
    return 0;
}
