#include<stdio.h>
void main{}

int fact(n){
    if(n==1){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}