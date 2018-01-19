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
#endif
