#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoubleLinkedList.h"
#include "IOData.h"

/*头插法建立IOData链表*/
//利用一些变量记录函数执行期间的各种异常情况，统一在函数出口处进行判断
void CreateFromHead(struct DualList* dl,const void* data){
    struct IOData* iod=NULL;
    iod=(struct IOData*)malloc(sizeof(struct IOData));
    if(NULL==iod){
        printf("IOData内存申请失败");
        return;
    }
    memset(iod,0,sizeof(struct IOData));
    memcpy(&iod->data,data,sizeof(struct IOData_Pack));
    AddListHead(dl,&iod->list_node);
}

/*尾插法建立IOData链表*/
void CreateFromTail(struct DualList* dl,const void* data){
    struct IOData* iod=NULL;
    iod=(struct IOData*)malloc(sizeof(struct IOData));
    if(NULL==iod){
        printf("IOData内存申请失败");
        return;
    }
    memset(iod,0,sizeof(struct IOData));
    memcpy(&iod->data,data,sizeof(struct IOData_Pack));
    AddListTail(dl,&iod->list_node);
}

/*将值为data的IOData结点加入双链表index位置处*/
bool AddDataToIndex(struct DualList* dl,const void* data,int index){
    struct IOData* iod=(struct IOData*)malloc(sizeof(struct IOData));
    memset(iod,0,sizeof(struct IOData));
    memcpy(&iod->data,data,sizeof(struct IOData_Pack));
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

/*删除所有指定data值的IOData结点*/
bool DelDataOfValue(struct DualList* dl,const void* data,int length){
    struct Node* p=NULL;
    //check：记录当前每个字节的比较状态
    bool check=false;
    list_foreach_head(p,dl->head,dl->tail){
        //若存储的值相同，则删除当前p指向的结点
        if(memcmp(data,first_addr(struct IOData,p),sizeof(struct IOData_Pack))==0){
            DeleteNode(p);
            free(first_addr(struct IOData,p));
            check=true;
        }
    }
    return check;
}

/*查找值为data的结点的位置index*/
void SearchDataAtIndex(struct DualList* dl,const void* data){
    struct Node* p=NULL;
    int index=1;
    printf("值为data的结点的位置index：");
    list_foreach_head(p,dl->head,dl->tail){
        if(memcmp(data,first_addr(struct IOData,p),sizeof(struct IOData_Pack))==0){
            printf("%d ",index);
        }
        index++;
    }
    printf("\n");
}

/*打印IOData结点*/
void PrintDataNode(struct DualList* dl){
    struct Node* p=NULL;
    list_foreach_head(p,dl->head,dl->tail){
        printf("%d ",((first_addr(struct IOData,p))->data).pack);
    }
    printf("\n");
}

/*销毁整个IOData链表*/
void DestroyDataList(struct DualList* dl){
    struct Node* p=NULL;
    list_foreach_head(p,dl->head,dl->tail){
        DeleteNode(p);
        free(first_addr(struct IOData,p));
    }
}

/*快速排序其中一趟，按逆序排*/
struct Node* ListQuickSort(struct Node* left,struct Node* right){
    struct IOData_Pack temp;
    int check=0;
    while(left!=right){
        //一趟排序的搜索过程是先左后右
        //先从左边开始搜索，left!=right是为了排除双链表中有多个相同元素的影响
        while(left!=right&&memcmp(first_addr(struct IOData,left),first_addr(struct IOData,right),sizeof(struct IOData_Pack))>=0){      
            left=left->next;
        }
        if(left!=right){            //当左边left->data值小于右边right->data值
            memcpy(&temp,first_addr(struct IOData,left),sizeof(struct IOData_Pack));        //并且left左指针还没有和right右指针重合
            memcpy(first_addr(struct IOData,left),first_addr(struct IOData,right),sizeof(struct IOData_Pack)); //交换left->data和right->data
            memcpy(first_addr(struct IOData,right),&temp,sizeof(struct IOData_Pack));
        }
    
        while(left!=right&&memcmp(first_addr(struct IOData,left),first_addr(struct IOData,right),sizeof(struct IOData_Pack))>=0){      //再从右边开始搜索
            right=right->prev;
        }
        if(left!=right){            //当左边left->data值小于右边right->data值
            memcpy(&temp,first_addr(struct IOData,left),sizeof(struct IOData_Pack));        //并且left左指针还没有和right右指针重合
            memcpy(first_addr(struct IOData,left),first_addr(struct IOData,right),sizeof(struct IOData_Pack)); //交换left->data和right->data
            memcpy(first_addr(struct IOData,right),&temp,sizeof(struct IOData_Pack));
        }
        //检查left是否与right重合，若不重合继续先左后右搜索
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
