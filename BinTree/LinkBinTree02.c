#ifndef LINKBINTREE02_C
#define LINKBINTREE02_C

#include "LinkBinTree02.h"

Status CreateBinTree(BinTree *T){
	TElemType e; 
	scanf("%d",&e);
	if(e == 0)
		*T = NULL;		//指向结构体的指针为NULL空，不指向任何东西 
	else{
		*T = (BinTree)malloc(sizeof(BinTNode));
		if(!T)
			exit(OVERFLOW);
		(*T)->data = e;
		CreateBinTree(&(*T)->lchild);		//创建左子树，递归中再用*T修改结点内容 
		CreateBinTree(&(*T)->rchild);		//创建右子树 
	}
	return OK; 
}

/*非递归遍历-先序（根左右）：栈*/
Status StackPreOrderTraverse(BinTree T){
	if (T == NULL)
		return ERROR;
	BinTree tmp = T;
	Stack S = CreateStack();	/*创建并初始化堆栈S*/ 
	while(tmp || !IsEmpty(S)){	/*结点存在 or 栈不为空时*/
		while(tmp){				/*结点存在，打印结点数据，把结点入栈，进入左孩子
								直到左子树为空*/
			printf("%d ",tmp->data);
			Push(S, tmp);
			tmp = tmp->lchild;
		}
		if(!IsEmpty(S)){
			tmp = Pop(S);		/*将结点弹出栈*/
			tmp = tmp->rchild;	/*转向右子树*/		
		}
	}
	return OK;
}

/*非递归遍历-中序（左根右）：栈*/
Status StackInOrderTraverse(BinTree T){
	if (T == NULL)
		return ERROR;
	BinTree tmp = T;
	Stack S = CreateStack();
	while(tmp || !IsEmpty(S)){
		while(tmp){						/*一直向左并将沿途结点压入堆栈*/
			Push(S, tmp);
			tmp = tmp->lchild;
		}
		if(!IsEmpty(S)){
			tmp = Pop(S);				/*结点弹出堆栈*/ 
			printf("%d ", tmp->data);	/*（访问）打印结点*/
			tmp = tmp->rchild;			/*转向右子树*/ 
		}
	}
	return OK;
}
#endif 
