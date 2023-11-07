#include<stdio.h>
#include<conio.h>
void seqSrch(int a[],int key, int n){
    int i = 0;
    int flag=0;
    while(i<n){
        if(a[i]==key){
            flag=1;
        }
        
        i++;
    }
    if(flag==1){
        printf("found %d",key) ;
        }
    else{
        printf("not found %d",key) ;
        }
}
void main(){
    int arr[6]={1,2,6,8,10,4};
    int l=6;
    int k =14;
    seqSrch( arr, k, l);
}
