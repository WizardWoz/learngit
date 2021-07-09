#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <stdlib.h>
#define PRINT()

/*双链表结点*/
//增强双链表通用性
struct Node
{
    int data;             //void*，可指向任意数据类型
    struct Node* prev;      //指向前一个结点的指针
    struct Node* next;      //指向后一个结点的指针
};

/*双链表*/
struct DualList
{
    struct Node* head;      //指向双链表头部结点的指针
    struct Node* tail;      //指向双链表尾部结点的指针
    
    /*函数指针，可以识别结点中存储的不同数据类型*/
};


/*依据arr数组，和length数组长度，使用头插法/尾插法建立双链表*/
void InitList(struct DualList* dl,int* arr,int length,int choose);

/*从头部开始打印双链表*/
void PrintList(struct DualList* dl);

/*根据data值查找双链表中元素位置index*/
int SearchIndex(struct DualList* dl,int data);

/*根据位置index搜索双链表中的元素*/
int SearchData(struct DualList* dl,int index);

/*往双链表位置index中插入值为data的元素*/
bool InsertElement(struct DualList* dl,int data,int index);

/*从双链表中删除位置为index的元素*/
bool DeleteElement(struct DualList* dl,int index);

/*快速排序其中的一趟排序，按逆序排*/
struct Node* ListQuickSort(struct Node* left,struct Node* right);

/*快速排序的递归过程*/
void SortRecursion(struct Node* left,struct Node* right);

/*销毁双链表*/
void DestroyList(struct Node* p,struct Node* q);

#endif