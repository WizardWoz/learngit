#include <stdio.h>
#include <stdbool.h>
#include "DoubleLinkedList.h"
#include "IOData.h"

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
    arr=(int*)malloc(length*sizeof(int));

    //需要修改：所有函数只能有一个出口
    //判断内存是否分配成功
    if(NULL==dl){
        printf("内存分配失败");
        
    }
    if(NULL==arr){

    }

    //查看各种数据大小
    printf("%ld %ld\n",sizeof(int*),sizeof(int));
    printf("%ld %ld\n",sizeof(struct Node*),sizeof(struct Node));
    printf("%ld %ld\n",sizeof(struct IOData*),sizeof(struct IOData));
    //开始测试
    printf("请输入双链表的长度：");
    scanf("%d",&length);
    printf("请输入完整数组：");
    for(i=0;i<length;i++){
        scanf("%d",&arr[i]);
    }
    //数组元素转化为IOData结点
    InitList(dl);
    for(i=0;i<length;i++){
        CreateFromHead(dl,arr[i]);
    }
    printf("顺序打印双链表：");
    PrintDataNode(dl);

    printf("往双链表位置index插入值为data的元素：");
    scanf("%d %d",&index,&data);
    if(AddDataToIndex(dl,data,index)){
        printf("位置index插入值为data的元素成功\n");
    }
    else{
        printf("位置index插入值为data的元素失败\n");
    }
    printf("顺序打印双链表：");
    PrintDataNode(dl);

    printf("删除双链表位置index的元素：");
    scanf("%d",&index);
    if(DelDataAtIndex(dl,index)){
        printf("删除位置index的元素成功\n");
    }
    else{
        printf("删除位置index的元素失败\n");
    }
    printf("顺序打印双链表：");
    PrintDataNode(dl);

    printf("对双链表进行快速排序（逆序）......\n");
    SortRecursion(dl->head->next,dl->tail->prev);
    printf("顺序打印双链表：");
    PrintDataNode(dl);

    printf("销毁双链表......\n");
    DestroyDataList(dl);

    free(arr);

    return 0;
}