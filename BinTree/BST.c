#ifndef BST_C
#define BST_C

#include "BST.H"


/*递归查找*/ 
BinTree Find(TElemType X, BinTree BST){
	if(!BST)
		return NULL;		//查找失败 
	if(X < BST->data)
		return Find(X, BST->lchild);		//在左子树中继续查找 
	else if (X > BST->data)
		return Find(X, BST->rchild);		//在右子树中继续查找 
	else	//X == BST->data;
		return BST;				//查找成功，返回结点的找到结点的地址 
	} 

/*非递归查找*/
BinTree IterFind(TElemType X, BinTree BST){
	while(BST){
		if(X > BST->data)
			BST = BST->rchild;			//向右子树移动，继续查找
		else if(X < BST->data)
			BST = BST->lchild;			//向左子树移动，继续查找
		else
			return BST;			//查找成功，返回结点的找到结点的地址  				 
	}
	return NULL;		//查找失败 
}

/*查找最小-递归*/
BinTree FindMin(BinTree BST){
	if(!BST) return NULL;		//空二叉树，返回NULL 
	else if (!BST->lchild)
		return BST;				//找到最左结点并返回 
	else
		return FindMin(BST->lchild); 	//沿左分支继续查找 
} 

/*查找最大-迭代*/
BinTree FindMax(BinTree BST){
	if(BST)
		while(BST->rchild)
			BST = BST->rchild;
		
	return BST; 
}

/*插入*/
/*
关键是找到元素应该插入的位置，可以采用与find类型的方法 
*/ 
BinTree Insert(TElemType X , BinTree BST){
	
	if(!BST){
		printf("插入元素%d\n",X); 
		BST = (BinTree)malloc(sizeof(BinTNode));
		if(!BST)
			exit(OVERFLOW);
		BST->data = X;
		BST->lchild = BST->rchild = NULL;
	}	//开始找要插入元素的位置 
	if (X < BST->data)
		BST->lchild = Insert(X, BST->lchild);		//递归左子树
		 
	else if (X > BST->data)
		BST->rchild = Insert(X, BST->rchild); 		//递归右子树
	//else x 已经存在，什么都不做 

	return BST;
}

/*删除*/
/*
考虑三种情况：
	要删除的是叶节点：直接删除。并再修改其父节点指针——置为NULL
	要删除的节点只有一个孩子的节点：
		将其父节点的指针指向要删除节点的孩子节点
	要删除的节点有左、右两棵子树：
		用另一个节点替代被删除节点：右子树的最小元素或左子树的最大元素
*/
BinTree Delete(TElemType X , BinTree BST){
	BinTree tmp;
	if(!BST)
		printf("要删除的数据: %d 未找到\n",X);
	else if (X < BST->data)
		BST->lchild = Delete(X, BST->lchild);
	else if (X > BST->data)
		BST->rchild = Delete(X, BST->rchild);
	else	//找到要删除的结点
		if(BST->lchild && BST->rchild){
			tmp = FindMin(BST->rchild);			//找到右子树最小的元素填充删除结点
			
			BST->data = tmp->data;				//把右子树的值赋值给父结点，然后再把刚右子树删除掉 
			BST->rchild = Delete(BST->data,BST->rchild);	// 在删除结点的右子树中删除最小元素 
		}else{	//被删除结点有一个或无子结点 
			tmp = BST;
			if(!BST->lchild)			//左孩子是空的话，把右孩子地址返回，递归的情况下父结点指向孙子 
				BST = BST->rchild;
			else if (!BST->rchild)		//如果右孩子是空，把左孩子地址返回 
				BST = BST->lchild;
			//如果左右结点都为空时，BST = BST->rchild(null) BST就等null，父结点执行NULl 
			free(tmp);
			printf("删除数据: %d\n",X); 
		}
	return BST;
}


/*中序遍历，用于打印结点数据，查看测试结果，因为搜索树的原因，中序变量从小到大*/
BinTree InOrderTraverse(BinTree T){
	if(T){
		InOrderTraverse(T->lchild);
		printf("%d\t", T->data);
		InOrderTraverse(T->rchild);
	}

} 
#endif
