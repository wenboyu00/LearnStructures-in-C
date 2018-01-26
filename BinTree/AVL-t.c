/* 将X插入AVL树T中，并且返回调整后的AVL树 */
AVLTree Insert( AVLTree T, TElemType X )
{ 
	if ( !T ) { /* 若插入空树，则新建包含一个结点的树 */
		T = (AVLTree)malloc(sizeof(struct AVLTNode));
		T->data = X;
		T->height = 0;
		T->lchild= T->rchild = NULL;
	} /* if (插入空树) 结束 */

	else if ( X < T->data ) {
		T->lchild = Insert( T->lchild, X);/* 插入T的左子树 */
		if ( GetHeight(T->lchild)-GetHeight(T->rchild) == 2 ) /* 如果需要左旋 */
			if ( X < T->lchild->data ) 
			T = SingleLeftRotation(T);      //左单旋 LL
		else 
			T = DoubleLeftRightRotation(T); //左-右双旋LR
	} /* else if (插入左子树) 结束 */

	else if ( X > T->data ) {
	T->rchild = Insert( T->rchild, X );/* 插入T的右子树 */
	if ( GetHeight(T->lchild)-GetHeight(T->rchild) == -2 )/* 如果需要右旋 */
		if ( X > T->rchild->data ) 
		T = SingleRightRotation(T);     //右单旋 RR
		else 
		T = DoubleRightLeftRotation(T); //右-左双旋 RL
	} /* else if (插入右子树) 结束 */

	/*else X == T->Data，无须插入 */
	T->height = Max( GetHeight(T->lchild), GetHeight(T->rchild) ) + 1;    //更新树高 
	return T;
}