#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <stdlib.h>

//类函数宏
/*正向迭代*/
#define list_foreach_head(pos,head,tail)\
    for(pos=head->next;pos!=tail;pos=pos->next)

/*反向迭代*/
#define list_foreach_tail(pos,head,tail)\
    for(pos=tail->prev;pos!=head;pos=poss->prev)
    
/*寻找每个IOData的首地址*/
#define first_addr(type,p)\
    (type*)((void*)(p)+sizeof(struct Node)-sizeof(type))

/*双链表结点*/
//增强双链表通用性
struct Node
{
    struct Node* prev;      //指向前一个结点的指针
    struct Node* next;      //指向后一个结点的指针
};

struct DualList{
    struct Node* head;      //指向双链表头部结点的指针
    struct Node* tail;      //指向双链表尾部结点的指针
};

/*初始化双链表的头结点和尾结点*/
void InitList(struct DualList* dl);

/*头插法插入结点*/
void AddListHead(struct DualList* dl,struct Node* p);

/*尾插法插入结点*/
void AddListTail(struct DualList* dl,struct Node* p);

/*插入结点*/
void AddNode(struct Node* p,struct Node* q);

/*删除结点*/
void DeleteNode(struct Node* p);

#endif