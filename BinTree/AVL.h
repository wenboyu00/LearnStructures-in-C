#ifndef AVL_H
#define AVL_H

#include<stdlib.h>
#include"../Status.h"


/*���Ͷ���*/
typedef int TElemType;
typedef struct AVLTNode{
	TElemType data;
	int height;				//���� 
	struct AVLTNode *lchild, *rchild;
}AVLTNode, *AVLTree;
typedef AVLTree Position;
//AVLTree���ڱ�ʾָ����������Position��ʾִ�е������ 

/*�Աȵ����*/
int Max(int a, int b);

/*�õ�����*/
int GetHeight(Position p);

/*����*/
AVLTree SingleLeftRotation(AVLTree T);

/*�ҵ���*/
AVLTree SingleRightRotation(AVLTree T);

/*��-����*/ 
AVLTree DoubleRightLeftRotation(AVLTree T);

/*��-����*/ 
AVLTree DoubleLeftRightRotation(AVLTree T);

/*����*/
AVLTree Insert(AVLTree T, TElemType X);
 
/*�������*/
void InOrderTraverse_AVL(AVLTree T);


#endif
