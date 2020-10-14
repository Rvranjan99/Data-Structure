#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *lc;
	struct node *rc;
}node;

node *root = NULL,*t;

node *ct(){
	int d;
	node *p;
	scanf("%d", &d);
	if(d==-1){ return NULL; } /*End a branch*/
	p=(node*)malloc(sizeof(node));
	p->data=d;
	printf("\n Enter left child's data : ");
	p->lc=ct();
	printf("\n Enter right child's data : ");
	p->rc=ct();
	return p;
}
void inorder(node *t)
{	if(t!=NULL)  {	inorder(t->lc);
			printf("  %d",t->data);
			inorder(t->rc); } }
void preorder(node *t)
{ 	if(t!=NULL) {	printf("  %d",t->data);
			preorder(t->lc);
			preorder(t->rc);  } }
void postorder(node *t)
{	 if(t!=NULL)  {	postorder(t->lc);
			postorder(t->rc);
			printf("  %d",t->data); } }

int main()
{
	printf("Enter the value of Root\n");
	root = ct();
	if(root!= NULL){printf("Tree is not empty\n");}
	printf("The INORDER output of the given binary tree goes like this: \n");
	inorder(root);
	printf("\nThe PREORDER output of the given binary tree goes like this: \n");
	preorder(root);
	printf("\nThe POSTORDER output of the given binary tree goes like this: \n");
	postorder(root);
}
