
#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
typedef  int ElemType; /*定义表元素的类型*/
typedef struct LNode{  /*线性表的单链表存储*/
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

LinkList CreateList(int n); /*                                   */
void PrintList(LinkList L); /*输出带头结点单链表的所有元素*/
int GetElem(LinkList L,int i,ElemType *e); /*               */
void delete(LinkList,int);
void Insert(LinkList,int,ElemType);
LNode *Locate(LinkList,int);

LinkList CreateList(int n){
    LNode *p,*q,*head;
    int i;
    head=(LinkList)malloc(sizeof(LNode));        head->next=NULL;
    p=head;
    for(i=0;i<n;i++){
       q=(LinkList)malloc(sizeof(LNode));       printf("input data %i:",i+1);
       scanf("%d",&q->data);            /*输入元素值*/
       q->next=NULL;                    /*结点指针域置空*/
       p->next=q;                       /*新结点连在表末尾*/
       p=q;
    }
    return head;
}/*CreateList*/

void PrintList(LinkList L){
    LNode *p;
    p=L->next;  /*p指向单链表的第1个元素*/
    while(p!=NULL){
        printf("%5d",p->data);
        p=p->next;
    }
}/*PrintList*/

int GetElem(LinkList L,int i,ElemType *e){
    LNode *p;int j=1;
    p=L->next;
    while(p&&j<i){                      
        p=p->next;j++;
    }
    if(!p||j>i)
        return ERROR;                  
*e=p->data;                       
return OK;
}/*GetElem*/

////删除链表中的节点
//void delete(LinkList L, int i){
//    LNode *q,*p;
//    int k;
//    if(i == 0){ 
//	printf("%d是无效的删除位置!\n",i); 
//	return;
//    }
//    else if(i ==1) {q = L; L = L->next;}
//    else{
//	p = L; k= 1;
//	while(p != NULL && k < i-1)
//	{
//	    p = p->next; k++;
//	}
//	if(p == NULL || p->next == NULL){
//	    printf("%d是无效的删除位置!\n",i);
//	    return;
//	}
//	q = p->next;
//    }
//    free(q);
//    return ;
//}
//
void delete(LinkList L,int i){
    LNode *p = Locate(L,i-1);
    if(p == NULL) return;
    LNode *s = (LinkList)malloc(sizeof(LNode));
    s->next = p->next;p->next = s;
    return;
}

LNode *Locate(LinkList L,int i){
    if(i<0) return NULL;
    LNode *p = L;int k = 0;
    while(p != NULL&&k<i){
	p = p->next;
	k++;
    }
    return p;
}

void Insert(LinkList L,int i,ElemType x){
    if(L == NULL || i == 1){
	LNode *newNode = (LinkList)malloc(sizeof(LNode));
	newNode->data = x;
	newNode->next = L;
	L = newNode;
    }
    else{
	LNode *p = L,*pr; int k = 1;
	while(p != NULL && k < i-1)
	{
	    pr = p; 
	    p = p->next;
	    k++;
	}
	if(p == NULL && L != NULL) p = pr;
	LNode *newNode = (LinkList)malloc(sizeof(LNode));
	newNode->data = x;
	newNode->next = p->next;
	p->next = newNode;
    }
    return;
}

int main(){
    int n,i,m,j,k;ElemType e;
    LinkList L=NULL;            /*定义指向单链表的指针*/
    printf("please input n:");  /*输入单链表的元素个数*/
    scanf("%d",&n);
    if(n>0){
        printf("\n1-Create LinkList:\n");
        L=CreateList(n);        
        printf("\n2-Print LinkList:\n");
        PrintList(L);           
        printf("\n3-GetElem from LinkList:\n");
        printf("input i=");
        scanf("%d",&i);
        if(GetElem(L,i,&e))     
            printf("No%i is %d",i,e);
        else
            printf("not exists");
	printf("\n4-Insert\n");
	printf("please input insert location and data (location,data):\n");
	scanf("%d,%d",&m,&j);
	Insert(L,m,j);
        printf("\n5-Print LinkList:\n");
        PrintList(L);           
	printf("\n6-Delete\n");
	printf("please input delete data's location:");
	scanf("%d",&k);
	delete(L,k);
        printf("\n7-Print LinkList:\n");
        PrintList(L);           
    }else
        printf("ERROR");
    printf("\n");
    return 0;
}
