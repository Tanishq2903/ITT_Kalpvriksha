#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int pre(char operator){
    if(operator == '+' || operator == '-')return 1;
    else return 2;
}
int calculations(int num , int num1 , char operator){
    int ans = 0;
    if(operator == '+'){
        ans = num + num1;
    }
    else if(operator == '-'){
        ans = num - num1;
    }
     else if(operator == '*'){
        ans = num * num1;
    } else if(operator == '/'){
       if(num1 != 0){
         ans = num / num1;}
       else{
        printf("error:Division by zero");
        exit(1);
       }
    }
    return ans;
}

int cal(char *exp){
int ans= 0;
int number = 0;
int numbersarray[100];
char operatorarray[100];
int n = 0;
int o = -1;
int i = 0;
while(i < strlen(exp)){
    if(isdigit(exp[i])){
        int num = 0;
        while(i < strlen(exp) && isdigit(exp[i])){
            num = num*10 + (exp[i]-'0');
            i++;
        }
        numbersarray[n++] = num;

    }
    else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'  ){
        if(o >= 0 && pre(exp[i]) <= pre(operatorarray[o]) ){
            ans = calculations(numbersarray[n-2],numbersarray[n-1],operatorarray[o]);
            numbersarray[n-2] = ans;
            n--;
            o--;
        }
        operatorarray[++o] = exp[i];
        i++;
    }else if(exp[i] == ' '){
        i++;
    }
    else {
        printf("Please enter valid string");
        exit(1);
    }


}


while(o >= 0){
    ans = calculations(numbersarray[n-2],numbersarray[n-1],operatorarray[o]);
            numbersarray[n-2] = ans;
            n--;
            o--;
}
return numbersarray[0];
}

int main(){
    char exp[200];
    printf("Enter the string :");
    scanf("%[^\n]s",exp);//this %[^\n]s means input is taken till new line
    int result = cal(exp);
    printf("%d",result);
    return 0;
}