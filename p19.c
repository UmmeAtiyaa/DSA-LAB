#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 20

int precedence(char op){
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    
    case '*':
    case '/':
        return 2;

    case '^':
        return 3;

    default:
        return -1;
    }
}
int isOp(char c){
    return (c=='+' ||c=='-' ||c=='*' ||c=='/' ||c=='^');
}
char* infixToP(char* infix){
    int i,j;
    int len=strlen(infix);
    char* postfix = (char*)malloc(sizeof(char) * (len+2));
    char stack[max];
    int top=-1;

    for(i=0,j=0; i < len; i++){
        if(infix[i] == ' ' || infix[i] == '\t'){
            continue;
        }
        if(isalnum(infix[i])){
            postfix[j++]=infix[i];
        }
        else if(infix[i] == '(') {
            stack[++top] = infix[i];
        }
        else if(infix[i] == ')'){
            while (top >-1 && stack[top] != '(')
            {
                postfix[j++]=stack[top--];
                
                if(top > -1 && stack[top] != '('){
                    return "invalid expression";
                }
                else{
                    top --;
                }
            }
            
        }
        else if( isOp(infix[i])){
            while(top >-1 && precedence(stack[top]) >= precedence(infix[i])){
                postfix[++j]=stack[top --];
            }
            stack[++top]=infix[i];
        }
    }
    postfix[j]='\0';
    return postfix;
}
int main(){
    char infix[max]="(a+b)*(c*d)";
    char* postfix= infixToP(infix);
    printf("%s \n",postfix);
    free(postfix);
    return 0;
}
