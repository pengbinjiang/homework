#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 20
typedef struct BTNode{       /*节点结构声明*/
	char data ;               /*节点数据*/
	struct BTNode *lchild;
	struct BTNode *rchild ;  /*指针*/
}*BiTree;

void createBiTree(BiTree *t){ /* 先序遍历创建二叉树*/
	char s;
	BiTree q;
	printf("\nplease input data:(exit for #)");
	scanf("%c",&s);
	getchar();
	if(s=='#'){*t=NULL; return;}
	q=(BiTree)malloc(sizeof(struct BTNode));
	if(q==NULL){printf("Memory alloc failure!"); exit(0);}
	q->data=s;
	*t=q;
	createBiTree(&q->lchild); /*递归建立左子树*/
	createBiTree(&q->rchild); /*递归建立右子树*/
}

void PreOrder(BiTree p){  /* 先序遍历二叉树*/
    if ( p!= NULL ) {
       	printf("%c", p->data);
       	PreOrder( p->lchild ) ;
       	PreOrder( p->rchild) ;
    }
}
void InOrder(BiTree p){  /* 中序遍历二叉树*/
    if( p!= NULL ) {
 	 InOrder( p->lchild ) ;
   	 printf("%c", p->data);
   	 InOrder( p->rchild) ;
    }
}
void PostOrder(BiTree p){  /* 后序遍历二叉树*/
   if ( p!= NULL ) {
    	PostOrder( p->lchild ) ;
       	PostOrder( p->rchild) ;
       	printf("%c", p->data);
    }
}

void Preorder_n(BiTree p){ /*先序遍历的非递归算法*/
    BiTree stack[MAX],q;
    int top=0,i;
    for(i=0;i<MAX;i++) stack[i]=NULL;/*初始化栈*/
    q=p;
    while(q!=NULL){
        printf("%c",q->data);
        if(q->rchild!=NULL) stack[top++]=q->rchild;
        if(q->lchild!=NULL) q=q->lchild;
        else
            if(top>0) q=stack[--top];
            else q=NULL;
    }
    printf("\n");
}

void release(BiTree t){ /*释放二叉树空间*/
  	if(t!=NULL){
    	release(t->lchild);
    	release(t->rchild);
    	free(t);
  	}
}

int PreOrder_num(BiTree p){
	int j=0;
      BiTree stack[MAX],q;
    int top=0,i;
    for(i=0;i<MAX;i++) stack[i]=NULL;/*初始化栈*/
    q=p;
    while(q!=NULL){
		j++;
        if(q->rchild!=NULL) stack[top++]=q->rchild;
        if(q->lchild!=NULL) q=q->lchild;
        else
            if(top>0) q=stack[--top];
            else q=NULL;
    }
	return j;
}

int LeafNodes(BiTree p){
	int num1,num2;
	if(p==NULL)
		return 0;
	else if(p->lchild==NULL&&p->rchild==NULL)
		return 1;
	else
	{
		num1=LeafNodes(p->lchild);
        num2=LeafNodes(p->rchild);
		return (num1+num2);
	}
}

int BTNodeDepth(BiTree p){
	int lchilddep,rchilddep;
	if(p==NULL)
		return 0;
	else{
        lchilddep=BTNodeDepth(p->lchild);
        rchilddep=BTNodeDepth(p->rchild);
		return(lchilddep>rchilddep)?(lchilddep+1):(rchilddep+1);
	}
}

int main(){
    BiTree t=NULL;
    createBiTree(&t);
    printf("\n\nPreOrder the tree is:");
    PreOrder(t);
    printf("\n\nInOrder the tree is:");
    InOrder(t);
    printf("\n\nPostOrder the tree is:");
    PostOrder(t);
    printf("\n\n先序遍历序列（非递归）:");
    Preorder_n(t);
    printf("该树的结点数为%d",PreOrder_num(t));
    printf("\n");
    printf("该树的叶结点数为%d",LeafNodes(t));
    printf("\n");
    printf("该树的深度为%d",BTNodeDepth(t));
    printf("\n");
    release(t);
    return 0;

