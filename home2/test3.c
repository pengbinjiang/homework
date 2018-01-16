#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MaxSize 50
typedef int ElemType;
typedef struct
{
  ElemType  data[MaxSize];
    int top;
} Stack;

void InitStack(Stack *S)  {  S->top=-1;
 } 

int Push(Stack *S,ElemType x){ if(S->top==MaxSize-1){  
 printf("\n Stack is full!"); 
     return 0; }
  S->top++;
  S->data[S->top]=x;
  return 1; 
}
int Empty(Stack *S)
 { 
  return (S->top==-1);
 }
int Pop(Stack *S,ElemType *x)    
 { if(Empty(S)){   
      printf("\n Stack is free!"); 
       return 0;
     }
   *x=S->data[S->top];
   S->top--;
   return 1;
  }

void conversion(int N){
    int e;
    Stack *S=(Stack*)malloc(sizeof(Stack));
    InitStack(S); 
    while(N){
	Push(S,N%2); 
	N=N/2;
    }
    while(!Empty(S)){
	Pop(S,&e);
	printf("%d ",e);
    }
}

void main(){ int n;
 printf("please input the data:\n");
    scanf("%d",&n);
 conversion(n);
    printf("\n");
}
