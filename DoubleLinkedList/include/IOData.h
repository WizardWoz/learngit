#ifndef IODATA_H
#define IODATA_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "DoubleLinkedList.h"

//拓展：使所有类型的IOData都通用
/*以字节(byte)为单位，将数据data从源地址src复制到目标地址dst*/
#define copy_data(src,dst,end,length)\
    memcpy(src,dst,length); dst+=length;\
    while(dst!=end) {*dst=*src; dst++; src++;}\
/*以字节(byte)为单位，对比源地址src与目的地址dst的数据data*/
#define compare_data(src,dst,end,check)\
    while(dst!=end)\
    {if(*src!=*dst){check=false;break;} else{src++;dst++;}}

/*保存不同类型data数据（不一定是int类型）的IOdata，位于内存的另一块区域*/
/*可以有struct IOData0,struct IOData1,struct IOData2......*/
struct IOData
{
    int data;
    struct Node list_node;
    /*函数指针，可以识别结点中存储的不同数据类型*/
};

/*头插法建立IOData链表*/
void CreateFromHead(struct DualList* dl,int data);

/*尾插法建立IOData链表*/
void CreateFromTail(struct DualList* dl,int data);

/*将IOData结点加入双链表index位置处*/
bool AddDataToIndex(struct DualList* dl,int data,int index);

/*删除位置为index的IOData结点*/
bool DelDataAtIndex(struct DualList* dl,int index);

/*删除指定data值的IOData结点*/
bool DelDataOfValue(struct DualList* dl,int data);

/*打印IOData结点*/
void PrintDataNode(struct DualList* dl);

/*销毁整个IOData链表*/
void DestroyDataList(struct DualList* dl);

/*快速排序其中一趟，按逆序排*/
struct Node* ListQuickSort(struct Node* left,struct Node* right);

/*快速排序的递归过程*/
void SortRecursion(struct Node* left,struct Node* right);

#endif