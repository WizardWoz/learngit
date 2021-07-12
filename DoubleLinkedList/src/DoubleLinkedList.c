#include <stdio.h>
#include <stdbool.h>
#include "DoubleLinkedList.h"

/*初始化双链表*/
void InitList(struct DualList* dl){
    //头结点head和尾结点tail均为dummy结点
    //统一插入/删除时由于结点数目不同，而不同的操作
    dl->head=(struct Node*)malloc(sizeof(struct Node));
    dl->tail=(struct Node*)malloc(sizeof(struct Node));

    dl->head->prev=NULL;
    dl->head->next=dl->tail;
    dl->tail->next=NULL;
    dl->tail->prev=dl->head;
}

/*头插法插入结点*/
void AddListHead(struct DualList* dl,struct Node* p){
    p->next=dl->head->next;
    p->prev=dl->head;
    dl->head->next->prev=p;
    dl->head->next=p;
}

/*尾插法插入结点*/
void AddListTail(struct DualList* dl,struct Node* p){
    p->prev=dl->tail->prev;
    p->next=dl->tail;
    dl->tail->prev->next=p;
    dl->tail->prev=p;
}

/*插入结点*/
void AddNode(struct Node* p,struct Node* q){
    p->prev->next=q;
    q->prev=p->prev;
    p->prev=q;
    q->next=p;
}

/*删除结点*/
void DeleteNode(struct Node* p){
    p->prev->next=p->next;
    p->next->prev=p->prev;
}