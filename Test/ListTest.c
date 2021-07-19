#include <stdio.h>
#include <stdbool.h>
#include "DoubleLinkedList.h"
#include "IOData.h"

int main(void)
{
    //变量声明/赋值分开
    //变量初始化为0，指针初始化为NULL
    struct DualList *dl = NULL;
    struct IOData_Pack* iop=NULL;
    int length = 0; //双链表长度
    int index = 0;  //用户需要查找的位置
    int i = 0;      //下标
    bool dl_success = true;
    bool iop_success = true;

    //所有函数只能有一个出口
    do
    {
        dl = (struct DualList *)malloc(sizeof(struct DualList));
        iop=(struct IOData_Pack*)malloc(sizeof(struct IOData_Pack));
         //判断内存是否分配成功
        if(NULL==iop){
            iop_success=false;
            printf("IOData_Pack内存分配失败\n");
            break;
        }
        if (NULL == dl)
        {
            dl_success = false;
            printf("双链表头结点&尾结点内存分配失败\n");
            break;
        }

        //开始测试
        InitList(dl);
        printf("请输入双链表的长度：");
        scanf("%d", &length);

        //为IOData_Pack结点数据域赋值
        printf("请输入每个结点的数据data：");
        for (i = 0; i < length; i++)
        {
            scanf("%d",&iop->pack);
            CreateFromHead(dl, iop);
            // CreateFromTail(dl,iop);
        }
        printf("顺序打印双链表：");
        PrintDataNode(dl);

        printf("查找双链表中值为data的元素：");
        scanf("%d",&iop->pack);
        SearchDataAtIndex(dl,iop);

        printf("往双链表位置index插入值为data的元素：");
        scanf("%d%d", &index, &iop->pack);
        if (AddDataToIndex(dl, iop, index))
        {
            printf("位置index插入值为data的元素成功\n");
        }
        else
        {
            printf("位置index插入值为data的元素失败\n");
        }
        printf("顺序打印双链表：");
        PrintDataNode(dl);

        printf("删除双链表位置index的元素：");
        scanf("%d", &index);
        if (DelDataAtIndex(dl, index))
        {
            printf("删除位置index的元素成功\n");
        }
        else
        {
            printf("删除位置index的元素失败\n");
        }
        printf("顺序打印双链表：");
        PrintDataNode(dl);

        printf("删除双链表中值为data的元素：");
        scanf("%d", &iop->pack);
        if (DelDataOfValue(dl, iop,sizeof(struct IOData_Pack)))
        {
            printf("删除值为data的元素成功\n");
        }
        else
        {
            printf("双链表中无值为%d的结点\n",iop->pack);
        }
        printf("顺序打印双链表：");
        PrintDataNode(dl);

        printf("对双链表进行快速排序（逆序）......\n");
        SortRecursion(dl->head->next, dl->tail->prev);
        printf("顺序打印双链表：");
        PrintDataNode(dl);

        printf("销毁双链表......\n");
        DestroyDataList(dl);

    } while (0);

    if(dl_success==true){
        free(dl);
    }
    if(iop_success==true){
        free(iop);
    }

    return 0;
}
