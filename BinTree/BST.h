#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include "../Status.h"

/*BST binary Search Tree- 二叉搜索树*/
typedef int TElemType;

typedef struct BinTNode{
	TElemType data;
	struct BinTNode *lchild, *rchild;
}BinTNode, *BinTree;


/*递归查找*/ 
BinTree Find(TElemType X, BinTree BST);

/*非递归查找*/
BinTree IterFind(TElemType X, BinTree BST);

/*查找最小-递归*/
BinTree FindMin(BinTree BST);

/*查找最大-迭代*/
BinTree FindMax(BinTree BST);

/*插入,关键是找到元素应该插入的位置，可以采用与find类型的方法 */ 
BinTree Insert(TElemType X , BinTree BST);

/*删除*/
BinTree Delete(TElemType X , BinTree BST);

/*前序遍历，用于打印结点数据，查看测试结果*/
BinTree InOrderTraverse(BinTree T);
#endif 
