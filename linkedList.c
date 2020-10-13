#include<stdio.h>
#include <stdlib.h>
struct node{
    int data;
    //pointer  which point to a node
    struct node *next;
};
struct node *start=NULL;
struct node *tail=NULL;
void insert(struct node** head){

    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data:");
    int x;
    scanf("%d",&x);

    ptr->data=x;
    ptr->next=NULL;

    if(*head==NULL){
        start=tail=ptr;

    }
    else{
        tail->next=ptr;
        tail=ptr;
    }

}
void insertAtBeg(struct node** head){

    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data:");
    int x;
    scanf("%d",&x);

    ptr->data=x;
    ptr->next=*head;
    if(*head==NULL){
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
    int choice;
    do{
         printf("1.insert at END\n2.Insert at starting \n3.Display\n4.EXIT\n");
         printf("Enter your choice:");
         scanf("%d",&choice);
         switch(choice){
            case 1:
                insert(&start);
                break;
            case 2:
                insertAtBeg(&start);
                break;
            case 3:
                printList();
                break;


         }
    }while(choice!=4);


}
