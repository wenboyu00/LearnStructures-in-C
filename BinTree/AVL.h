#ifndef AVL_H
#define AVL_H

#include<stdlib.h>
#include"../Status.h"


/*类型定义*/
typedef int TElemType;
typedef struct AVLTNode{
	TElemType data;
	int height;				//树高 
	struct AVLTNode *lchild, *rchild;
}AVLTNode, *AVLTree;
typedef AVLTree Position;
//AVLTree用于表示指向整个树，Position表示执行单个结点 

/*对比得最大*/
int Max(int a, int b);

/*得到树高*/
int GetHeight(Position p);

/*左单旋*/
AVLTree SingleLeftRotation(AVLTree T);

/*右单旋*/
AVLTree SingleRightRotation(AVLTree T);

/*右-左旋*/ 
AVLTree DoubleRightLeftRotation(AVLTree T);

/*左-右旋*/ 
AVLTree DoubleLeftRightRotation(AVLTree T);

/*插入*/
AVLTree Insert(AVLTree T, TElemType X);
 
/*中序遍历*/
void InOrderTraverse_AVL(AVLTree T);


#endif
