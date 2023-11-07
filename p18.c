#include<stdio.h>
#include<stdlib.h>
#define max 20

 int stack[max];
 int top=-1;
 
 void push(int item){
    if(top >= max -1){
        printf("\n stack overflown ");
        return;
    }
    top ++;
    stack[top]=item;
 }
 
 int pop(){
    if(top < 0){
        printf("\n stack overflown ");
        return -1;
    }
    int item =stack[top];
    top --;
    return item;
 }
 
 int isOp(char symbol){
    if(symbol=='+' || symbol=='-' || symbol=='*' || symbol=='/'){
        return 1;
    }
    return 0;
 }
 
 int evaluate(char* exp){
    int i=0;
    char ch=exp[i];
    int op1,op2,res;
    
    while(ch != '\0'){
        if(ch >= '0' && ch <='9'){
            int num = ch - '0';
            push(num);      
        }
        else if( isOp(ch) ){
            op2=pop();
            op1=pop();
            
            switch(ch){
                case '+': 
                    res = op1+op2; 
                    break;
                case '-': 
                    res = op1-op2; 
                    break;
                case '*': 
                    res = op1*op2; 
                    break;
                case '/': 
                    res = op1/op2; 
                    break;
                
            }
            push(res);
        }
        i++;
        ch=exp[i];
    }
    res=pop();
    return res;
 }
 
 int main(){
    char exp[]="22+";
    int res = evaluate(exp);
    printf("result = %d \n", res );
    return 0;
 }