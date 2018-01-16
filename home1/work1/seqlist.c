#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1

#define INIT_SIZE 5     /*初始分配的顺序表长度*/
#define INCREM 5        /*溢出时，顺序表长度的增量*/
typedef  int ElemType;  /*定义表元素的类型*/
typedef struct Sqlist{
    ElemType *slist;      /*存储空间的基地址*/
    int length;           /*顺序表的当前长度*/
    int listsize;         /*当前分配的存储空间*/
} Sqlist;

int InitList_sq(Sqlist *L) ; /*      初始化顺序表         */
int CreateList_sq(Sqlist *L,int n) ; /*     创建顺序表        */
int ListInsert_sq(Sqlist *L,int i,ElemType e) ;/*  将新元素e插入表第i个位置  */
int PrintList_sq(Sqlist *L) ;  /*输出顺序表的元素*/
int ListDelete_sq(Sqlist *L,int i) ; /*删除第i个元素*/
int ListLocate(Sqlist *L,ElemType e) ; /*查找值为e的元素*/

int InitList_sq(Sqlist *L) {
    L->slist=(ElemType*) malloc(INIT_SIZE*sizeof(ElemType) ) ;
    if(!L->slist)  return ERROR;      
    L->length=0;                     
    L->listsize=INIT_SIZE;           
    return OK;                   
} /*InitList*/

int CreateList_sq(Sqlist *L,int n) {
    ElemType e;
    int i;
    for(i=0;i<n;i++) {
	printf("input data %d:",i+1) ;
	scanf("%d",&e) ;
	if(!ListInsert_sq(L,i+1,e) ) 
	    return ERROR;
    } 
    return OK;
} /*CreateList*/

/*输出顺序表中的元素*/
int PrintList_sq(Sqlist *L) {
    int i;
    for(i=1;i<=L->length;i++) 
	printf("%5d",L->slist[i-1] ) ;
    return OK;
} /*PrintList*/

/*将新元素e插入表第i个位置。若插入成功函数返回OK;否则返回ERROR*/
int ListInsert_sq(Sqlist *L,int i,ElemType e) {
    int k;
    if(i<1||i>L->length+1)  
	return ERROR;    
    if(L->length>=L->listsize) {
	L->slist=(ElemType*) realloc(L->slist,(INIT_SIZE+INCREM) *sizeof(ElemType) ) ;
	if(!L->slist)  
	    return ERROR; 
	L->listsize+=INCREM;                
    } 
    for(k=L->length-1;k>=i-1;k--) {
	L->slist[k+1] = L->slist[k] ;
    } 
    L->slist[i-1] =e;                     
    L->length++;                         
    return OK;
} /*ListInsert*/

/*在顺序表中删除第i个元素*/
int ListDelete_sq(Sqlist *L,int i) {
    if(!L->length) return ERROR;
    if(i<1||i>L->length) return ERROR;
    for (int j=i;j<L->length;j++) L->slist[j-1] = L->slist[j];
    L->length--;
    return OK;
} 

/*在顺序表中查找指定值元素，返回其序号*/
int ListLocate(Sqlist *L,ElemType e) {
    for(int i=0;i<L->length;i++)
	if(L->slist[i] == e) return i;
    return -1;
} 

int main() {
    Sqlist sl;
    int n,m,k,d,s;
    printf("please input size:") ;  /*输入顺序表的元素个数*/
    scanf("%d",&n) ;
    if(n>0) {
	printf("\n1-Create Sqlist:\n") ;
	InitList_sq(&sl) ;
	CreateList_sq(&sl,n) ;
	printf("2-Print Sqlist:\n") ;
	PrintList_sq(&sl) ;
	printf("\n") ;
	printf("\n3-Insert") ;
	printf("\nplease input insert location and data(location,data):");
	scanf("%d,%d",&m,&k) ;
	ListInsert_sq(&sl,m,k) ;
	printf("4-Print Sqlist:\n") ;
	PrintList_sq(&sl) ;
	printf("\n") ;
	printf("\n5-Delete") ;
	printf("\nplease input delete data's location:");
	scanf("%d",&d);
	ListDelete_sq(&sl,d);
	printf("6-Print Sqlist:\n") ;
	PrintList_sq(&sl) ;
	printf("\n") ;
	printf("\n7-Search") ;
	printf("\nplease input search data:");
	scanf("%d",&s);
	printf("The search data's location is %d\n",ListLocate(&sl,s) + 1);
    } 
    else
	printf("ERROR") ;
    return 0;
}
