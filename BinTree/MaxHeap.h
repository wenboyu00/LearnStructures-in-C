#ifndef MAXHEAP_H
#define MAXHEAP_H

#include<stdio.h>
#include<stdlib.h>
#include"../Status.h"

typedef int ElemType;
typedef struct HeapStruct{
	ElemType *Elements;		/*数组指针，存储堆元素的数组*/
	int Size;				/*堆当前元素个数*/
	int Capacity;			/*堆的最大容量*/ 
}HeapStruct, * MaxHeap;

/*创建容量为MaxSize的空的最大堆*/
MaxHeap CreateHeap( int MaxSize);

/*是否已满*/
Status IsFull(MaxHeap H);

/*将元素X插入最大堆 H*/
void Insert( MaxHeap H , ElemType X);

/*是否为空*/ 
Status IsEmpty(MaxHeap H); 

/*从最大堆H中取出键值为最大的元素，并删除这个结点*/
ElemType DeleteMax( MaxHeap H);

/*下虑：将H中以H->Elements[p]为根的子堆调整为最大堆*/
void PercDown(MaxHeap H ,int p);

/*建立最大堆*/
void BuildHeap(MaxHeap H);

/*中序遍历*/
void InOrderTraverse_MaxHeap(MaxHeap H);
#endif 
