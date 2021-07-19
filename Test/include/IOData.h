#ifndef IODATA_H
#define IODATA_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "DoubleLinkedList.h"

/*IOData_Pack中可以存放任意数据，不是只能存放int*/
struct IOData_Pack{
    int pack;
    //还可以与以下内容一起存放
    //char pack_c;
    //char pack_c[3];
    // float pack_f;
    //float pack_f[3];
    //double pack_d;
    //double pack_d[3];
    //struct pack_s{};
    //......
};

/*保存IOData_Pack的IOdata*/
struct IOData
{
    struct IOData_Pack data;
    struct Node list_node;
};

/*头插法建立IOData链表*/
void CreateFromHead(struct DualList* dl,const void* data);

/*尾插法建立IOData链表*/
void CreateFromTail(struct DualList* dl,const void* data);

/*查找值为data的结点的位置index*/
void SearchDataAtIndex(struct DualList* dl,const void* data);

/*将IOData结点加入双链表index位置处*/
bool AddDataToIndex(struct DualList* dl,const void* data,int index);

/*删除位置为index的IOData结点*/
bool DelDataAtIndex(struct DualList* dl,int index);

/*删除指定data值的IOData结点*/
bool DelDataOfValue(struct DualList* dl,const void* data,int length);

/*打印IOData结点*/
void PrintDataNode(struct DualList* dl);

/*销毁整个IOData链表*/
void DestroyDataList(struct DualList* dl);

/*快速排序其中一趟，按逆序排*/
struct Node* ListQuickSort(struct Node* left,struct Node* right);

/*快速排序的递归过程*/
void SortRecursion(struct Node* left,struct Node* right);

#endif