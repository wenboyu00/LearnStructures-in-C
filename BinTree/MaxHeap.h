#ifndef MAXHEAP_H
#define MAXHEAP_H

#include<stdio.h>
#include<stdlib.h>
#include"../Status.h"

typedef int ElemType;
typedef struct HeapStruct{
	ElemType *Elements;		/*����ָ�룬�洢��Ԫ�ص�����*/
	int Size;				/*�ѵ�ǰԪ�ظ���*/
	int Capacity;			/*�ѵ��������*/ 
}HeapStruct, * MaxHeap;

/*��������ΪMaxSize�Ŀյ�����*/
MaxHeap CreateHeap( int MaxSize);

/*�Ƿ�����*/
Status IsFull(MaxHeap H);

/*��Ԫ��X�������� H*/
void Insert( MaxHeap H , ElemType X);

/*�Ƿ�Ϊ��*/ 
Status IsEmpty(MaxHeap H); 

/*������H��ȡ����ֵΪ����Ԫ�أ���ɾ��������*/
ElemType DeleteMax( MaxHeap H);

/*���ǣ���H����H->Elements[p]Ϊ�����Ӷѵ���Ϊ����*/
void PercDown(MaxHeap H ,int p);

/*��������*/
void BuildHeap(MaxHeap H);

/*�������*/
void InOrderTraverse_MaxHeap(MaxHeap H);
#endif 
