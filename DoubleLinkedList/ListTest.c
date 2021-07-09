#include <stdio.h>
#include <stdbool.h>
#include "DoubleLinkedList.h"

int main(void){
    //修改：变量声明/赋值分开
    //修改：声明时最好初始化
    struct DualList* dl=NULL;
    int* arr=NULL;
    int choose=0;     //存储用户选择
    int length=0;     //数组长度
    int data=0;       //用户需要查找的元素值
    int index=0;      //用户需要查找的下标
    int i=0;          //数组下标

    dl=(struct DualList*)malloc(sizeof(struct DualList));
    //需要修改：所有函数只能有一个出口
    //判断内存是否分配成功
    if(NULL==dl){
        printf("内存分配失败");
        
    }
    printf("%ld %ld\n",sizeof(int*),sizeof(int));
    printf("%ld\n",sizeof(struct Node));
    printf("请输入你想要转化成双链表的数组长度：");
    scanf("%d",&length);
    //每次调用函数都要手动检测返回值
    arr=(int*)malloc(length*sizeof(int));
    if(NULL==arr){

    }

    printf("请输入完整数组：");
    for(i=0;i<length;i++){
        scanf("%d",&arr[i]);
    }

    printf("使用何种方法初始化双链表（0为头插法，1为尾插法）：");
    scanf("%d",&choose);
    InitList(dl,arr,length,choose);
    
    printf("顺序打印双链表：");
    PrintList(dl);

    printf("查找元素data对应的位置index：");
    scanf("%d",&data);
    if(SearchIndex(dl,data)){
        printf("值为data的元素对应的位置index为：%d\n",SearchIndex(dl,data));
    }
    else{
        printf("双链表中不存在值为%d的元素\n",data);
    }

    printf("查找位置index对应的元素data：");
    scanf("%d",&index);
    if(SearchData(dl,index)!=-1){
        printf("位置为index的元素对应的值data为：%d\n",SearchData(dl,index));
    }
    else{
        printf("位置下标输入有误\n");
    }
    

    printf("往双链表位置index插入值为data的元素：");
    scanf("%d %d",&index,&data);
    if(InsertElement(dl,data,index)){
        printf("位置index插入值为data的元素成功\n");
    }
    else{
        printf("位置index插入值为data的元素失败\n");
    }

    printf("顺序打印双链表：");
    PrintList(dl);

    printf("删除双链表位置index的元素：");
    scanf("%d",&index);
    if(DeleteElement(dl,index)){
        printf("删除位置index的元素成功\n");
    }
    else{
        printf("删除位置index的元素失败\n");
    }

    printf("顺序打印双链表：");
    PrintList(dl);

    printf("对双链表进行快速排序（逆序）......\n");
    SortRecursion(dl->head->next,dl->tail->prev);

    printf("顺序打印双链表：");
    PrintList(dl);

    printf("销毁双链表......\n");
    DestroyList(dl->head,dl->head->next);

    free(arr);

    return 0;
}