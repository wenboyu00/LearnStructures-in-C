#ifndef LINKBINTREE02_H
#define LINKBINTREE02_H

#include <stdio.h>
#include <stdlib.h>
#include "../Status.h"

/*二叉树存储定义-非递归遍历*/
typedef int TElemType;

typedef struct BinTNode{
	TElemType data;
	struct BinTNode *lchild, *rchild;
}BinTNode, *BinTree;

/*栈元素类型*/
typedef BinTree SElemType;
#include "../Stack/LinkStack01.c"			//重新定义栈元素类型，并引入栈 

/*创建二叉树*/
Status CreateBinTree(BinTree *T);

/*非递归遍历-先序：栈*/
Status StackPreOrderTraverse(BinTree T);
/*非递归遍历-中序：栈*/
Status StackInOrderTraverse(BinTree T);
/*非递归遍历-后序：栈*/
Status StackPostOrderTraverse(BinTree T);

/*清理二叉树*/
Status ClearBinTree(BinTree *T);
/*是否为空*/
Status BinTreeEmpty(BinTree T);
/*返回Tree的根*/
TElemType Root(BinTree T);
/*返回指结点的值*/
TElemType Value(BinTree T);
/*给所指p结点赋值为value*/
void Assign(BinTree T,TElemType value); 

#endif
