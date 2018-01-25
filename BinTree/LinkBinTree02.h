#ifndef LINKBINTREE02_H
#define LINKBINTREE02_H

#include <stdio.h>
#include <stdlib.h>
#include "../Status.h"

/*�������洢����-�ǵݹ����*/
typedef int TElemType;

typedef struct BinTNode{
	TElemType data;
	struct BinTNode *lchild, *rchild;
}BinTNode, *BinTree;

/*ջԪ������*/
typedef BinTree SElemType;
#include "../Stack/LinkStack01.c"			//���¶���ջԪ�����ͣ�������ջ 

/*����������*/
Status CreateBinTree(BinTree *T);

/*�ǵݹ����-����ջ*/
Status StackPreOrderTraverse(BinTree T);
/*�ǵݹ����-����ջ*/
Status StackInOrderTraverse(BinTree T);
/*�ǵݹ����-����ջ*/
Status StackPostOrderTraverse(BinTree T);

/*���������*/
Status ClearBinTree(BinTree *T);
/*�Ƿ�Ϊ��*/
Status BinTreeEmpty(BinTree T);
/*����Tree�ĸ�*/
TElemType Root(BinTree T);
/*����ָ����ֵ*/
TElemType Value(BinTree T);
/*����ָp��㸳ֵΪvalue*/
void Assign(BinTree T,TElemType value); 

#endif
