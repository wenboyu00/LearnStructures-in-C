#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include "../Status.h"

/*BST binary Search Tree- ����������*/
typedef int TElemType;

typedef struct BinTNode{
	TElemType data;
	struct BinTNode *lchild, *rchild;
}BinTNode, *BinTree;


/*�ݹ����*/ 
BinTree Find(TElemType X, BinTree BST);

/*�ǵݹ����*/
BinTree IterFind(TElemType X, BinTree BST);

/*������С-�ݹ�*/
BinTree FindMin(BinTree BST);

/*�������-����*/
BinTree FindMax(BinTree BST);

/*����,�ؼ����ҵ�Ԫ��Ӧ�ò����λ�ã����Բ�����find���͵ķ��� */ 
BinTree Insert(TElemType X , BinTree BST);

/*ɾ��*/
BinTree Delete(TElemType X , BinTree BST);

/*ǰ����������ڴ�ӡ������ݣ��鿴���Խ��*/
BinTree InOrderTraverse(BinTree T);
#endif 
