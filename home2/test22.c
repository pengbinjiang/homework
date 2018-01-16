#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct node{
    DataType data;
    struct node *next;
}LStackNode, *LinkStack;

void Coversion_10_2(int N){
    LStackNode *p;
    LStackNode *top = NULL;
    do{
	p = (LStackNode *)malloc(sizeof(LStackNode));   /*动态生成新的结点*/
	p->data = N%2;   /*将余数送入新结点的数据域*/
	p->next = top;   /*将新结点插入到原栈顶结点之前,先使其成为新的栈顶*/
	top = p;         /*栈顶指针指向刚插入链表的结点,使之成为栈顶*/
	N = N/2;
    }while(N != 0);
    while(top != NULL){
	p = top;	 /*p指向栈顶*/
	printf("%d", p->data);	      /*输出栈顶元素*/
	top = top->next;	/*栈顶结点元素出栈*/
	free(p);	/*释放栈顶结点*/
    }

    return;
}

int main(int argc, char **argv)
{
    int n;
    printf("请输入一个十进制数:\n");
    scanf("%d", &n);
    printf("转换后的二进制数:\n");
    Coversion_10_2(n);
    printf("\n");

    return 0;
}
