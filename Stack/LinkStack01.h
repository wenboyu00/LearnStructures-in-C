#ifndef LINKSTACK01_H
#define LINKSTACK01_H 
/*#ifndef��if not defined,�����û�б�����*/
 
#include <stdio.h>
#include <stdlib.h>
#include "../Status.h" 

/*�ڶ���������������Ҫ���¶���*/
/*���û�ж����LINKBINTREE02_H���壬��*/ 
#if	!defined LINKBINTREE02_H
typedef int SElemType;
#endif

struct SNode{
	SElemType data;
	struct SNode *next;
}SNode;

typedef struct SNode * PtrToSNode;	//PtrToSNodeָ�����ָ��
typedef PtrToSNode Stack;			//Stackָ�����ָ��

/*����ջ*/
Stack CreateStack();

/*�Ƿ�Ϊ��*/
Status IsEmpty(Stack S);

/*��ջ*/ 
Status Push(Stack S , SElemType x);

/*��ջ*/
SElemType Pop(Stack S);

#endif 
