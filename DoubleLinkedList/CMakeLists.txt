cmake_minimum_required(VERSION 3.0)
project(DOUBLELINKEDLIST)
include_directories(include)
add_executable(Test src/DoubleLinkedList.c src/IOData.c ListTest.c)