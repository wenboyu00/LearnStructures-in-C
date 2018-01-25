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

/*
遇到结点，先打印结点数据，然后再把结点存入栈，再进入结点的左子树——直到左子树为空
从栈弹出结点，回到上一级，再进入右子树。
对右子树进行之前打印结点数据，结点入栈，进入左子树——直到左子树为空的操作*/
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

/*
遇到结点，结点入栈，进入左子树——直到左子树为空
从栈弹出结点，打印结点数据。再进入右子树重复while（tmp）循环内容 
*/
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

/*非递归遍历-后序（左右根）：栈*/

/*
后序遍历的难点在于：访问完左子树后，需要判断右子树的状态（已经访问 or 不存在），然后再访问根节点。 

增加一个标记结点：lastNode。标记已经访问的右子树状态
 
代码实现思路： 
一直向左并将沿途结点压入堆栈，直到没有左子树
当栈内有结点时： 
	得到当前结点
	如果该节点的右子树已被访问或不存在
	表示此直接可以访问结点数据；
	并标记为最后访问结点lastNode = curNode，用来标记已经访问的右子树 

若右子树未被访问过，
	则把根节点入栈，进入右子树
	
如果右子树存在，则入栈右子树，并进入其左子树，一直向左并将沿途结点压入堆栈（重复对原树的操作）

...弹出最后结点，判断右子树是否状态...循环...
 
*/
Status StackPostOrderTraverse(BinTree T){
	
	if (T == NULL)
		return ERROR;
	BinTree tmp = T;
	Stack S = CreateStack();
	BinTree lastNode = NULL;		/*记录被访问过的前一个结点*/
	BinTree curNode = NULL; 		/*记录当前结点*/
	
	while(tmp || !IsEmpty(S)){
		
		while(tmp){						/*一直向左并将沿途结点压入堆栈*/
			Push(S, tmp);
			tmp = tmp->lchild;
		}
		
		while(!IsEmpty(S)){
			curNode = Pop(S);		/*当前结点——最后一个结点*/
			
			/*判断当前结点右子树状态，右子树为空 or 右子树已经被访问*/ 
			if(curNode->rchild == NULL || curNode->rchild == lastNode){		/*无右子树或右子树已经被访问*/ 
				printf("%d ",curNode->data);
				lastNode = curNode;											/*标记已经被访问*/
			}	/*右子树未被访问过*/ 
			else{																
				Push(S,curNode);					/*入栈当前结点，进入右子树*/
				curNode = curNode->rchild;
				
				/*对右结点重复原树节点操作——一直向左并将沿途结点压入堆栈*/
				while(curNode){
					Push(S, curNode);
					curNode = curNode->lchild;
				} 
			}
		}
	}
	return OK;
}

/*
二叉树非递归遍历中结点和栈
栈存储的是上一个结点，子树操作完成后，返回上一个跟结点，然后再进入另一个子树

*/

/*后序遍历求树深度（高）*/
int PostOrderGetHeight(BinTree T){
	int leftHeight, rightHeight, maxHeight;
	if(T){
		leftHeight = PostOrderGetHeight(T->lchild);			//左子树深度 
		rightHeight = PostOrderGetHeight(T->rchild);		//右子树深度 
		maxHeight = leftHeight > rightHeight ? leftHeight : rightHeight;
		return (maxHeight + 1 );	//返回树的深度 
	} 
	else
		return 0;		//空树深度为0 
}

/*清理二叉树*/
Status ClearBinTree(BinTree *T){
	if(*T){									//二叉树不为空 
		if((*T)->lchild)					//清空左树 
			ClearBinTree(&(*T)->lchild);
		if((*T)->rchild)					//清空右树 
			ClearBinTree(&(*T)->rchild);
		free(*T);							//释放该结点 		 
		*T = NULL;							//置空指针 
	}
	return OK; 
} 

/*是否为空*/
Status BinTreeEmpty(BinTree T){
	if(!T)
		return TRUE;
	else
		return FALSE;
}

/*返回Tree的根*/
TElemType Root(BinTree T){
	if(BinTreeEmpty(T))
		return -1;
	else
		return T->data;
}

/*返回指结点的值*/
TElemType Value(BinTree T){
	return T->data;
}

/*给所指p结点赋值为value*/
void Assign(BinTree T,TElemType value){
	T->data = value;
}
#endif 
