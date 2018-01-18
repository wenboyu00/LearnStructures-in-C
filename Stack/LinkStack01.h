#ifndef LINKSTACK01_H
#define LINKSTACK01_H 
/*#ifndef是if not defined,即如果没有被定义*/
 
#include <stdio.h>
#include <stdlib.h>
#include "../Status.h" 

/*在二叉树，此类型需要重新定义*/
/*如果没有定义过LINKBINTREE02_H定义，则*/ 
#if	!defined LINKBINTREE02_H
typedef int SElemType;
#endif

struct SNode{
	SElemType data;
	struct SNode *next;
}SNode;

typedef struct SNode * PtrToSNode;	//PtrToSNode指向结点的指针
typedef PtrToSNode Stack;			//Stack指向结点的指针

/*创建栈*/
Stack CreateStack();

/*是否为空*/
Status IsEmpty(Stack S);

/*入栈*/ 
Status Push(Stack S , SElemType x);

/*出栈*/
SElemType Pop(Stack S);

#endif 
