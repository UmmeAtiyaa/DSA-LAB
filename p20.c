#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int prio;
    int info;
    struct node *link;
}n;
n *front =NULL;

void insert(int data,int prio){
    n *temp,*q;
    temp = (n*)malloc(sizeof(n));
    temp->info=data;
    temp->prio=prio;

    if(front == NULL || prio < front->prio){
        temp->link=front;
        front=temp;
    }
    else{
        q=front;
        while(q->link != NULL && q->link->prio <= prio){
            q=q->link;
        }
        temp->link=q->link;
        q->link=temp;
    }
}
void del(){
    n *temp;
    if(front == NULL){
        printf("Queue iunderflow\n");
    }
    else{
        temp=front;
        printf("deleted item is %d \n",temp->info);
        front =front->link;
        free(temp);
    }
}
void disp(){
    n *ptr;
    ptr =front;
    if(front == NULL){
        printf("queue is empty \n");
    }
    else{
        printf("queue is : \n");
        printf("priority item \n");

        while(ptr != NULL){
            printf("%d %d \n",ptr->prio, ptr->info);
            ptr=ptr->link;
        }
    }
}
int main(){
    int choice , data, prio;
    do{
        printf("1. insert \n");
        printf("2. delete \n");
        printf("3. display \n");
        printf("4. quit \n");
        printf("Enter your choice:");
        scanf("%d" ,& choice);

        switch (choice)
        {
        case 1:
            printf("enter data which is to be added in the queue: ");
            scanf("%d",&data);
            printf("enter its priority: ");
            scanf("%d", &prio);
            break;
        case 2:
            del();
            break;
        case 3:
            disp();
            break;
        default:
            printf("wrong choice \n");            
        }
    }while(choice != 4);
    return 0;
}
