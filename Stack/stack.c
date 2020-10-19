#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack{
    unsigned capacity;//>0
    int top;
    int* array;

};
struct Stack* createStack(unsigned capacity){
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity=capacity;
    stack->top=-1;
    stack->array=(int*)malloc(stack->capacity*sizeof(int)); //array of size capacity.
    return stack;
}
int isEmpty(struct Stack* stack){
    return stack->top==-1;
}
int isFull(struct Stack* stack){
    return stack->top==stack->capacity-1;

}
//insert an element top of the stack
void push(struct Stack* stack,int data){
    printf("\n===========================\n");
    if(isFull(stack)){
        printf("Stack is Full\n");
    }
    else{
        stack->top++;
        stack->array[stack->top]=data;
        printf("%d is pushed to stack \n",data);

    }
    printf("===========================\n\n");
}
//return and remove top element
int pop(struct Stack* stack){
    if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}
//return top element without removing
int peek(struct Stack* stack){
    if(isEmpty(stack)){
        return NULL;
    }
    else{
        return stack->array[stack->top];
    }
}
int main(){
    int size,choice,data,i,pop_data;
    printf("Enter size/capacity of stack\n");
    scanf("%d",&size);
    struct Stack* stack=createStack(size);
    do{
        printf("1.PUSH\t2.POP\t3.PEEK\t4.Display\t5.EXIT\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("enter data:");
            scanf("%d",&data);
            push(stack,data);
            break;
        case 2:
            printf("\n===========================\n");
            pop_data=pop(stack);
            if(pop_data==INT_MIN){
                printf("Stack is Empty\n");
            }
            else{

                printf(" %d is popped from stack\n", pop_data);
            }

            printf("===========================\n");
            break;
        case 3:
            printf("\n===========================\n");
            if(peek(stack)==NULL){
                printf("Stack is empty\n");
            }
            else{
                printf("%d is peeked from stack\n",peek(stack));
            }
            printf("===========================\n\n");
            break;

        case 4:
             printf("============Stack==========\n");
            if(isEmpty(stack)){
                printf("stack is empty");
            }
            else{

                for(i=0;i<=stack->top;i++){
                    printf("%d ",stack->array[i]);
                }

            }
            printf("\n===========================\n\n");
            break;



        }

    }while(choice!=5);


}
