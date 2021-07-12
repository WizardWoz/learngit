#include <stdio.h>
#include <stdlib.h>
#include "IOData.h"
#include "DoubleLinkedList.h"

/*头插法建立IOData链表*/
void CreateFromHead(struct DualList* dl,int data){
    struct IOData* iod=(struct IOData*)malloc(sizeof(struct IOData));
    iod->data=data;
    AddListHead(dl,&iod->list_node);
}

/*尾插法建立IOData链表*/
void CreateFromTail(struct DualList* dl,int data){
    struct IOData* iod=(struct IOData*)malloc(sizeof(struct IOData));
    iod->data=data;
    AddListTail(dl,&iod->list_node);
}

/*将IOData结点加入双链表index位置处*/
bool AddDataToIndex(struct DualList* dl,int data,int index){
    struct IOData* iod=(struct IOData*)malloc(sizeof(struct IOData));
    iod->data=data;
    struct Node* p=NULL;
    list_foreach_head(p,dl->head,dl->tail){
        if(index<=0){
            return false;
        }
        else if(index==1){
            AddNode(p,&iod->list_node);
            return true;
        }
        else{
            index--;
        }
    }
    return false;
}

/*删除位置为index的IOData结点*/
bool DelDataAtIndex(struct DualList* dl,int index){
    struct Node* p=NULL;
    list_foreach_head(p,dl->head,dl->tail){
        if(index<=0){
            return false;
        }
        else if(index==1){
            DeleteNode(p);
            free(first_addr(struct IOData,p));
            return true;
        }
        else{
            index--;
        }
    }
    return false;
}

/*删除指定data值的IOData结点*/
bool DelDataOfValue(struct DualList* dl,int data){
    struct Node* p=NULL;
    int count=0;
    list_foreach_head(p,dl->head,dl->tail){
        if((first_addr(struct IOData,p))->data==data){
            DeleteNode(p);
            free(first_addr(struct IOData,p));
            count++;
        }
    }
    if(count!=0){
        return true;
    }
    return false;
}

/*打印IOData结点*/
void PrintDataNode(struct DualList* dl){
    struct Node* p=NULL;
    list_foreach_head(p,dl->head,dl->tail){
        printf("%d ",(first_addr(struct IOData,p))->data);
    }
    printf("\n");
}

/*销毁整个IOData链表*/
void DestroyDataList(struct DualList* dl){
    struct Node* p=dl->head->next;
    list_foreach_head(p,dl->head,dl->tail){
        printf("%p %p\n",dl->head,dl->tail);
        printf("%p %p\n",dl->head->next,dl->tail->prev);
        printf("%p %p\n",first_addr(struct IOData,dl->head->next),first_addr(struct IOData,dl->tail->prev));
        DeleteNode(p);
        free(first_addr(struct IOData,p));
    }
}

/*快速排序其中一趟，按逆序排*/
struct Node* ListQuickSort(struct Node* left,struct Node* right){
    int temp=0;
    while(left!=right){
        //一趟排序的搜索过程是先左后右
        //先从左边开始搜索，left!=right是为了排除双链表中有多个相同元素的影响
        while(left!=right&&(first_addr(struct IOData,left))->data>=(first_addr(struct IOData,right))->data){      
            left=left->next;
        }
        if(left!=right){            //当左边left->data值小于右边right->data值
            temp=(first_addr(struct IOData,left))->data;        //并且left左指针还没有和right右指针重合
            (first_addr(struct IOData,left))->data=(first_addr(struct IOData,right))->data; //交换left->data和right->data
            (first_addr(struct IOData,right))->data=temp;
        }
    
        while(left!=right&&(first_addr(struct IOData,right))->data<=(first_addr(struct IOData,left))->data){      //再从右边开始搜索
            right=right->prev;
        }
        if(left!=right){            //当左边left->data值小于右边right->data值
            temp=(first_addr(struct IOData,left))->data;        //并且left左指针还没有和right右指针重合
            (first_addr(struct IOData,left))->data=(first_addr(struct IOData,right))->data; //交换left->data和right->data
            (first_addr(struct IOData,right))->data=temp;
        }
        //检查left是否与right重合，若不重合继续先左后右搜索，
    }
    return left;
}

/*快速排序的递归过程*/
void SortRecursion(struct Node* left,struct Node* right){
    //当出现左指针left与右指针right重合
    //或者右指针right转移到left左边时，返回到上一层
    if(left==right||left->prev==right){
        return;
    }
    else{
        //pivot轴值为一趟排序后的返回值，作为后面分治递归的依据
        struct Node* pivot=ListQuickSort(left,right);
        SortRecursion(left,pivot->prev);
        SortRecursion(pivot->next,right);
    }
}