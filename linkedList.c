#include<stdio.h>
#include <stdlib.h>
struct node{
    int data;
    //pointer  which point to a node
    struct node *next;
};
struct node *start=NULL;
struct node *tail=NULL;
void insert(int pos){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data:");
    int x;
    scanf("%d",&x);
    ptr->data=x;
    if(start==NULL){
        start=tail=ptr;
        ptr->next=NULL;
    }
    else{
        int i=0;
        struct node *temp=start;
        while(i<pos){temp=temp->next;i++;}

        ptr->next=temp->next;
        temp->next=ptr;

    }

}
//insert at end
void append(){

    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data:");
    int x;
    scanf("%d",&x);
    ptr->data=x;
    ptr->next=NULL;
    if(start==NULL){
        start=tail=ptr;
    }
    else{
        tail->next=ptr;
        tail=ptr;
    }
}
//insert at start
void push(){

    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data:");
    int x;
    scanf("%d",&x);

    ptr->data=x;
    ptr->next=start;
    if(start==NULL){
        start=tail=ptr;
    }
    else{
            start=ptr;
    }
}
void printList(){
    struct node *temp=start;
    while(temp->next!=NULL || start==NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
     printf("%d\n",temp->data);
}
int main(){
    int choice,pos;
    do{
         printf("1.insert at END\n2.Insert at starting \n3.insert after node no.(starting node 0)\n4.Display\n5.EXIT\n");
         printf("Enter your choice:");
         scanf("%d",&choice);
         switch(choice){
            case 1:
                append();
                break;
            case 2:
                push();
                break;
            case 3:

                printf("Enter the node number");
                scanf("%d",&pos);
                insert(pos);
                break;
            case 4:
                printList();
                break;


         }
    }while(choice!=5);


}
