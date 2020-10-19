#include<stdio.h>
typedef struct node{
   	 int data;
   	 struct node *next;
    }node;
node *head=NULL,*t,*p,*last;
int so(){
    int op;
    t=head;
    printf("Your Queue is: ");
    while(t!=NULL){printf("%d ", t->data); t=t->next;}    
    printf("Enter 1 to push, 2 to pop a node or 0 to end");
    scanf("%d", &op);
    switch(op){
   		 case 1: equeue(); break;
   		 case 2: dqueue    (); break;
   		 case 0: return 0; break;
   		 default: printf(" Error");
   	 }
    so();
}
equeue(){
   	 p=(node*)malloc(sizeof(node));
   	 printf("Enter data for new node");
   	 scanf("%d", &p->data);
   	 last->next=p;
   	 last=p;
   	 so();
}
dqueue(){
   	 t=head;
   	 head=head->next;
   	 t->next=NULL;
   	 free(t);
   	 so();
} 
int main(){
    int i,size,value;
    printf("Enter the size"); scanf("%d", &size);
    for(i=0;i<size;i++){
   	 p=(node*)malloc(sizeof(node));
   	 p->next=NULL;
   	 printf("Enter data for this node");
   	 scanf("%d", &p->data);
   	 if(head==NULL){head=p;}
   	 else{
   		 last->next=p;
   		 p->next=NULL;    
   		 }
   	 last=p;    
   	 }
    
    so();
}				
