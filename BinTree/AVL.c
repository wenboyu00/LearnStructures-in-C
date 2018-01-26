#ifndef AVL_C
#define AVL_C

#include "AVL.h"

/*对比得最大*/
int Max(int a, int b){
	return a > b ? a : b;
}

/*得到树高*/
int GetHeight(Position p){
	if(!p)
		return -1;
	return p->height; 
}

/*左单旋——LL旋转->麻烦结点在发现者的左，左子树*/
/* 
将A与B做左单旋
	A变为B的右子树
	BR（B的右子树）是大于B小于A，因此变成A的右子树
更新A与B的高度，返回新的根结点B */ 
/* 注意：A必须有一个左子结点B */
/*A为T，B为tmp*/    
AVLTree SingleLeftRotation(AVLTree T){
	AVLTree tmp = T->lchild;
	T->lchild = tmp->rchild;
	tmp->rchild = T;
	T->height = Max(GetHeight(T->lchild), GetHeight(T->rchild)) + 1;
	tmp->height = Max(GetHeight(tmp->lchild), T->height) + 1;
	
	return tmp;
}

/*右单旋——RR旋转->麻烦结点在发现者的右，右子树*/
/* 
将A与B做右单旋
	A->right = B->left；把B左子树给A的右子树，因为B左子树大于A并小于B
	B->left = A；A变为B的右子树
更新A与B的高度，返回新的根结点B 
*/
/* 注意：A必须有一个右子结点B */ 
AVLTree SingleRightRotation(AVLTree T){
	
	AVLTree tmp = T->rchild;
	T->rchild = tmp->lchild;
	tmp->lchild = T;
	
	T->height = Max(GetHeight(T->lchild), GetHeight(T->rchild)) + 1;
	tmp->height = Max(GetHeight(tmp->rchild), T->height) + 1;
	
	return tmp;

}
/*左-右旋——LR-麻烦结点在发现者的左，右子树*/ 
/* 注意：A必须有一个左子结点B，且B必须有一个右子结点C */
/* 将A、B与C做两次单旋，返回新的根结点C */ 
AVLTree DoubleLeftRightRotation(AVLTree T){
	/*将B与C做右单旋，C被返回——C左子树是B，B右子树为CL（C左子树）*/
	T->lchild = SingleRightRotation(T->lchild);
	/*将A与C做左单旋，C被返回——C右子树为A，A左子树为CR（C右子树）*/
	return SingleLeftRotation(T); 
}

/*右-左旋——RL-麻烦结点在发现者的右，左子树*/ 
/* 将A、B与C做两次单旋，返回新的根结点C */ 
/* 注意：A必须有一个右子结点B，且B必须有一个左子结点C */
AVLTree DoubleRightLeftRotation(AVLTree T){
	/*将B与C做左单选，C被返回——C右子树是B，B左子树是CR（C右子树）*/
	T->rchild = SingleLeftRotation(T->rchild);
	/*将A与C做右单选，C被返回——C左子树是A，A右子树是Cl（C左子树）*/
	return SingleRightRotation(T); 
}

/*插入*/
AVLTree Insert(AVLTree T, TElemType X){
	
	if(!T){		/*若插入空树，则新建包含一个结点的树*/ 
		T = (AVLTree)malloc(sizeof(AVLTNode));
		T->data = X; 
		T->height = 0;
		T->lchild = T->rchild = NULL;
		printf("插入数值: %d \n",X); 
	}/*if（插入空树）结束*/
	
	else if ( X < T->data){
		T->lchild = Insert(T->lchild, X);		//插入T的左子树 
		if ( GetHeight(T->lchild) - GetHeight(T->rchild) == 2){		//需要左旋 
			if ( X < T->lchild->data)
				T = SingleLeftRotation(T);		//左单选LL
			else
				T = DoubleLeftRightRotation(T);	//左-右双旋LR 
		} /*else if 插入左子树结束*/ 
	}
	else if (X > T->data){
		T->rchild = Insert(T->rchild, X); 		//插入T的右子树
		if(GetHeight(T->lchild) - GetHeight(T->rchild) == -2){	//需要右选 
			if(X > T->rchild->data)
				T = SingleRightRotation(T);		//右单选RR
			else
				T = DoubleRightLeftRotation(T);	//右-左双旋RL 
		} /*else if 插入右子树结束*/ 
	}	
	/*else X == T->data，无需插入*/
	T->height = Max(GetHeight(T->lchild), GetHeight(T->rchild)) + 1;	//更新书高
	
	return T;  
}

///* 将X插入AVL树T中，并且返回调整后的AVL树 */
//AVLTree Insert( AVLTree T, TElemType X )
//{ 
//	if ( !T ) { /* 若插入空树，则新建包含一个结点的树 */
//		T = (AVLTree)malloc(sizeof(struct AVLTNode));
//		T->data = X;
//		T->height = 0;
//		T->lchild= T->rchild = NULL;
//	} /* if (插入空树) 结束 */
//
//	else if ( X < T->data ) {
//		T->lchild = Insert( T->lchild, X);/* 插入T的左子树 */
//		if ( GetHeight(T->lchild)-GetHeight(T->rchild) == 2 ) /* 如果需要左旋 */
//			if ( X < T->lchild->data ) 
//			T = SingleLeftRotation(T);      //左单旋 LL
//		else 
//			T = DoubleLeftRightRotation(T); //左-右双旋LR
//	} /* else if (插入左子树) 结束 */
//
//	else if ( X > T->data ) {
//	T->rchild = Insert( T->rchild, X );/* 插入T的右子树 */
//	if ( GetHeight(T->lchild)-GetHeight(T->rchild) == -2 )/* 如果需要右旋 */
//		if ( X > T->rchild->data ) 
//		T = SingleRightRotation(T);     //右单旋 RR
//		else 
//		T = DoubleRightLeftRotation(T); //右-左双旋 RL
//	} /* else if (插入右子树) 结束 */
//
//	/*else X == T->Data，无须插入 */
//	T->height = Max( GetHeight(T->lchild), GetHeight(T->rchild) ) + 1;    //更新树高 
//	return T;
//}


/*中序遍历*/
void InOrderTraverse_AVL(AVLTree T){
		if(T){
		InOrderTraverse_AVL(T->lchild);
		printf("%d\t",T->data);
		InOrderTraverse_AVL(T->rchild);
	}

}

#endif
