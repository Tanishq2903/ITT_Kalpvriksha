#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int rows,cols;
    printf("Enter number of rows:");
    scanf("%d",&rows);
    printf("Enter number of columns:");
    scanf("%d",&cols);

    if(rows >= 1 && rows <= 10  && cols >= 1 && cols <= 101){
        
    
    char*** nameMatrix = (char***)malloc(rows*sizeof(char***));
    for(int row = 0 ; row < rows ; row++){
        nameMatrix[row] = (char**)malloc(cols*sizeof(char*));
        for(int col = 0 ; col < cols ; col++){
            nameMatrix[row][col] = (char*)malloc(50*sizeof(char));
        }
    }
     printf("Enter names:");
      for(int row = 0 ; row < rows ; row++){
         for(int col = 0 ; col < cols ; col++){
             printf("Name at (%d,%d): ", row, col);
            scanf("%49s", nameMatrix[row][col]);
         }
      }
   

     printf("\nThe 2D array of names is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s ", nameMatrix[i][j]);
        }
        printf("\n");
    }

int vowelCount = 0;
int longNameRow  = 0, longNameCol = 0;
int currentLength = 0;
   for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char firstChar = nameMatrix[i][j][0];  
            
            if(firstChar == 'A' ||firstChar =='E'||firstChar =='I'||firstChar =='O'||firstChar =='U' || firstChar == 'a' ||firstChar =='e'||firstChar =='i'||firstChar =='o'||firstChar =='u'){
                vowelCount++;
            }
               if(strlen(nameMatrix[i][j]) > currentLength){
                currentLength = strlen(nameMatrix[i][j]);
                longNameRow = i;
                longNameCol = j;
               } 
            
        }
    }

    printf("Number of names starting with a vowel: %d\n", vowelCount);
printf("Longest Name : %s",nameMatrix[longNameRow][longNameCol]);

 for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            free(nameMatrix[row][col]);
        }
        free(nameMatrix[row]);
    }
    free(nameMatrix);
    }
return 0;
    
}