#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int id;
    int age;
    char name[50];
}User;

void display(User user){

printf("id: %d , age: %d , name: %s\n", user.id, user.age, user.name);

}

void printinFile(FILE* fptr , User user){
 fprintf(fptr,"%d %d %s\n",user.id,user.age,user.name);
}


void createFile(){
    FILE* fptr;
    fptr=fopen("users.txt","r");
    if(!fptr){
        fptr = fopen("users.txt","w");
        printf("file is created now");
    }
    fclose(fptr);
}
void create(int id,int age , char name[]){
   createFile();
    FILE* fptr;
    fptr=fopen("users.txt","a");
    User user;
    user.id = id;
    user.age = age;
    strcpy(user.name,name);
      printinFile(fptr,user);

    fclose(fptr);
}


void delete(int id){
    FILE* file1 = fopen("users.txt","r");
     FILE* file2 = fopen("temp.txt","w");
     if(!file1 || !file2){
        printf("could not open file please create file manually if not created");
        return;
     }
     User user;
     while(fscanf(file1,"%d %d %49s\n",&user.id,&user.age,user.name) == 3){
        if(user.id != id){
            printinFile(file2,user);
        }
     }
     fclose(file1);
     fclose(file2);
     remove("users.txt");
     rename("temp.txt","users.txt");
}



void read(){
    FILE* file1 = fopen("users.txt","r");
     User user;
     while(fscanf(file1,"%d %d %s\n",&user.id,&user.age,user.name)  == 3){
       
         display(user);
        
     }
     fclose(file1);
}

void update(int newid , int newage , char newname[]){
          FILE* file1 = fopen("users.txt","r");
     FILE* file2 = fopen("temp.txt","w");
      if(!file1 || !file2){
        printf("could not open file please create file manually if not created");
        return;
     }
     User user;
     while(fscanf(file1,"%d %d %s\n",&user.id,&user.age,user.name) == 3){
        if(user.id != newid){
          printinFile(file2,user);
        }
        else {
         User updateduser;
         updateduser.id = newid;
         updateduser.age = newage;
          strcpy(updateduser.name,newname);
      printinFile(file2,updateduser);
        }
     }
     fclose(file1);
     fclose(file2);
     remove("users.txt");
     rename("temp.txt","users.txt");
}

void input(int* id , int* age , char name[]){
             printf("add id :");
              scanf("%d",id);
              printf("add age :");
              scanf("%d",age);
              printf("add name :");
              scanf("%s",name);
}



int main(){
    int age;
    int id;
    char name[50];
    int options;
    printf("to add user press 1 \n to delete user press 2 \n to view user press 3\n to update user press 4\n");
    scanf("%d" , &options);
    switch(options){
     case 1 :  input(&id,&age,name);
      create(id,age,name);
              printf("task done");
              break;
              
     case 2 : printf("delete id :");
              scanf("%d" , &id);
              delete(id);
              printf("task done");
              break;

     case 3 : read();
              break;

     case 4 :  input(&id,&age,name);
              update(id,age,name);
              printf("task done");
              break;
     default : printf("enter valid number");
    }
}