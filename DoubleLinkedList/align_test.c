#include <stdio.h>
#include "include/DoubleLinkedList.h"

struct Data_Pack{
    int data_1;
    char data_2;
    float data_3;
    char data_4;
    double data_5;
};

struct Data{
    struct Data_Pack dp;
    struct Node test_node;
};

int main(void){
    struct Data test;
    test.dp.data_1=1;
    test.dp.data_2='a';
    test.dp.data_3=1.0;
    test.dp.data_4='a';
    test.dp.data_5=1.0;
    printf("%p %p\n",&test.dp,&test.test_node);
    return 0;
}