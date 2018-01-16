#ifndef search_h
#define search_h

#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 25
#define P 13
#define OK 1
#define ERROR 0
#define DUPLICATE -1
#define TRUE 1
#define FALSE 0

typedef struct{
    /*哈希表元素结构*/
    int key;  /*关键字值*/
    int flag; /*是否存放元素*/
} ElemType;

typedef struct {
    ElemType data[MAXSIZE] ;
    int count;      /*元素个数*/
    int sizeindex;  /*当前哈希表容量*/
} HashTable;

void dataset(int ds[] ,int *len);
int InsertHash(HashTable *H,int e,int d[]) ;
int CreateHash(HashTable *H,int ds[] ,int len,int d[]);
int SearchHash(HashTable *H, int e,int d[]);
void menu();

#endif
