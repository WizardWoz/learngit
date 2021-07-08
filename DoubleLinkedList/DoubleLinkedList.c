#include <stdio.h>
#include <stdbool.h>
#include "DoubleLinkedList.h"

/*依据arr数组，和length数组长度，使用头插法/尾插法初始化双链表*/
void InitList(struct DualList* dl,int* arr,int length,int choose){
    //头结点head和尾结点tail均为dummy结点
    //统一插入/删除时由于结点数目不同，而不同的操作
    dl->head=(struct Node*)malloc(sizeof(struct Node));
    dl->tail=(struct Node*)malloc(sizeof(struct Node));
    dl->head->prev=NULL;
    dl->head->next=dl->tail;
    dl->tail->next=NULL;
    dl->tail->prev=dl->head;
    if(length==0){      //没有元素要插入，双链表无需进行初始化
        free(dl->head);
        free(dl->tail);
        return;
    }

    int i;
    if(choose==0){      //choose==0为头插法
        for(i=0;i<length;i++){
            struct Node* p=(struct Node*)malloc(sizeof(struct Node));
            p->data=*(arr+i);
            p->next=dl->head->next;
            p->prev=dl->head;
            dl->head->next->prev=p;
            dl->head->next=p;
        }
    }
    else if(choose==1){ //choose==1为尾插法
        for(i=0;i<length;i++){
            struct Node* p=(struct Node*)malloc(sizeof(struct Node));
            p->data=*(arr+i);
            p->prev=dl->tail->prev;
            dl->tail->prev->next=p;
            dl->tail->prev=p;
            p->next=dl->tail;
        }
    }
}

/*从头部/尾部开始打印双链表*/
void PrintList(struct DualList* dl,int choose){
    struct Node* p=NULL;
    printf("当前双链表：");
    if(choose==0){      //choose==0从头部开始打印
        p=dl->head->next;
        while(p!=dl->tail){
            printf("%d ",p->data);
            p=p->next;
        }
        printf("\n");
    }
    else if(choose==1){ //choose==1从尾部开始打印
        p=dl->tail->prev;
        while(p!=dl->head){
            printf("%d ",p->data);
            p=p->prev;
        }
        printf("\n");
    }
}

/*根据data值查找双链表中元素位置index*/
int SearchIndex(struct DualList* dl,int data){
    struct Node* p=NULL;
    int index=1;
    p=dl->head->next;
    //当左指针p还未到达尾结点时
    while(p!=dl->tail){
        if(p->data==data){  //当左指针p搜索到值为data的元素
            return index;   //则返回当前左指针下标
        }
        else{
            index++;
            p=p->next;
        }
    }

    return 0;   //返回0说明查找失败，双链表中无值为data的元素
}

/*根据位置index搜索双链表中的元素*/
int SearchData(struct DualList* dl,int index){
    struct Node* p=NULL;
    p=dl->head->next;
    while(p!=dl->tail){
        if(index<=0){
            break;
        }
        else if(index==1){
            return p->data;
        }
        else{
            index--;
            p=p->next;
        }
    }
    return -1;       //返回0表示位置index输入有误
}

/*往双链表位置index处中插入值为data的元素*/
bool InsertElement(struct DualList* dl,int data,int index){
    struct Node* p=NULL;
    p=dl->head->next;
    struct Node* n=NULL;
    while(p!=dl->tail){
        if(index<=0){
            return false;   //返回false说明位置index输入不对
        }
        else if(index==1){
            n=(struct Node*)malloc(sizeof(struct Node));
            n->data=data;
            n->prev=p->prev;
            p->prev->next=n;
            n->next=p;
            p->prev=n;
            return true;
        }
        else{
            index--;
            p=p->next;
        }
    }
    
    return false;
}

/*从双链表中删除位置为index的元素*/
bool DeleteElement(struct DualList* dl,int index){
    struct Node* p=NULL;
    p=dl->head->next;
    while(p!=dl->tail){
        if(index<=0){
            return false;       //双链表中不存在位置index<=0的元素，返回false
        }
        else if(index==1){
            p->prev->next=p->next;
            p->next->prev=p->prev;
            free(p);
            return true;
        }
        else{
            index--;
            p=p->next;
        }
    }

    return false;
}

/*快速排序其中一趟，按逆序排*/
struct Node* ListQuickSort(struct Node* left,struct Node* right){
    int temp;
    while(left!=right){
        //一趟排序的搜索过程是先左后右
        while(left->data>right->data){      //先从左边开始搜索
            left=left->next;
        }
        if(left!=right){            //当左边left->data值小于右边right->data值
            temp=left->data;        //并且left左指针还没有和right右指针重合
            left->data=right->data; //交换left->data和right->data
            right->data=temp;
        }
    
        while(right->data<left->data){      //再从右边开始搜索
            right=right->prev;
        }
        if(left!=right){            //当左边left->data值小于右边right->data值
            temp=left->data;        //并且left左指针还没有和right右指针重合
            left->data=right->data; //交换left->data和right->data
            right->data=temp;
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

/*销毁双链表*/
void DstroyList(struct DualList* dl){
    struct Node* p=NULL;
    struct Node* q=NULL;
    p=dl->head;
    q=p->next;
    while(p!=NULL){
        free(p);
        p=q;
        q=q->next;
    }
}