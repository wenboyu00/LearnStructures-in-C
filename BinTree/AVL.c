#ifndef AVL_C
#define AVL_C

#include "AVL.h"

/*�Աȵ����*/
int Max(int a, int b){
	return a > b ? a : b;
}

/*�õ�����*/
int GetHeight(Position p){
	if(!p)
		return -1;
	return p->height; 
}

/*��������LL��ת->�鷳����ڷ����ߵ���������*/
/* 
��A��B������
	A��ΪB��������
	BR��B�����������Ǵ���BС��A����˱��A��������
����A��B�ĸ߶ȣ������µĸ����B */ 
/* ע�⣺A������һ�����ӽ��B */
/*AΪT��BΪtmp*/    
AVLTree SingleLeftRotation(AVLTree T){
	AVLTree tmp = T->lchild;
	T->lchild = tmp->rchild;
	tmp->rchild = T;
	T->height = Max(GetHeight(T->lchild), GetHeight(T->rchild)) + 1;
	tmp->height = Max(GetHeight(tmp->lchild), T->height) + 1;
	
	return tmp;
}

/*�ҵ�������RR��ת->�鷳����ڷ����ߵ��ң�������*/
/* 
��A��B���ҵ���
	A->right = B->left����B��������A������������ΪB����������A��С��B
	B->left = A��A��ΪB��������
����A��B�ĸ߶ȣ������µĸ����B 
*/
/* ע�⣺A������һ�����ӽ��B */ 
AVLTree SingleRightRotation(AVLTree T){
	
	AVLTree tmp = T->rchild;
	T->rchild = tmp->lchild;
	tmp->lchild = T;
	
	T->height = Max(GetHeight(T->lchild), GetHeight(T->rchild)) + 1;
	tmp->height = Max(GetHeight(tmp->rchild), T->height) + 1;
	
	return tmp;

}
/*��-��������LR-�鷳����ڷ����ߵ���������*/ 
/* ע�⣺A������һ�����ӽ��B����B������һ�����ӽ��C */
/* ��A��B��C�����ε����������µĸ����C */ 
AVLTree DoubleLeftRightRotation(AVLTree T){
	/*��B��C���ҵ�����C�����ء���C��������B��B������ΪCL��C��������*/
	T->lchild = SingleRightRotation(T->lchild);
	/*��A��C��������C�����ء���C������ΪA��A������ΪCR��C��������*/
	return SingleLeftRotation(T); 
}

/*��-��������RL-�鷳����ڷ����ߵ��ң�������*/ 
/* ��A��B��C�����ε����������µĸ����C */ 
/* ע�⣺A������һ�����ӽ��B����B������һ�����ӽ��C */
AVLTree DoubleRightLeftRotation(AVLTree T){
	/*��B��C����ѡ��C�����ء���C��������B��B��������CR��C��������*/
	T->rchild = SingleLeftRotation(T->rchild);
	/*��A��C���ҵ�ѡ��C�����ء���C��������A��A��������Cl��C��������*/
	return SingleRightRotation(T); 
}

/*����*/
AVLTree Insert(AVLTree T, TElemType X){
	
	if(!T){		/*��������������½�����һ��������*/ 
		T = (AVLTree)malloc(sizeof(AVLTNode));
		T->data = X; 
		T->height = 0;
		T->lchild = T->rchild = NULL;
		printf("������ֵ: %d \n",X); 
	}/*if���������������*/
	
	else if ( X < T->data){
		T->lchild = Insert(T->lchild, X);		//����T�������� 
		if ( GetHeight(T->lchild) - GetHeight(T->rchild) == 2){		//��Ҫ���� 
			if ( X < T->lchild->data)
				T = SingleLeftRotation(T);		//��ѡLL
			else
				T = DoubleLeftRightRotation(T);	//��-��˫��LR 
		} /*else if ��������������*/ 
	}
	else if (X > T->data){
		T->rchild = Insert(T->rchild, X); 		//����T��������
		if(GetHeight(T->lchild) - GetHeight(T->rchild) == -2){	//��Ҫ��ѡ 
			if(X > T->rchild->data)
				T = SingleRightRotation(T);		//�ҵ�ѡRR
			else
				T = DoubleRightLeftRotation(T);	//��-��˫��RL 
		} /*else if ��������������*/ 
	}	
	/*else X == T->data���������*/
	T->height = Max(GetHeight(T->lchild), GetHeight(T->rchild)) + 1;	//�������
	
	return T;  
}

///* ��X����AVL��T�У����ҷ��ص������AVL�� */
//AVLTree Insert( AVLTree T, TElemType X )
//{ 
//	if ( !T ) { /* ��������������½�����һ�������� */
//		T = (AVLTree)malloc(sizeof(struct AVLTNode));
//		T->data = X;
//		T->height = 0;
//		T->lchild= T->rchild = NULL;
//	} /* if (�������) ���� */
//
//	else if ( X < T->data ) {
//		T->lchild = Insert( T->lchild, X);/* ����T�������� */
//		if ( GetHeight(T->lchild)-GetHeight(T->rchild) == 2 ) /* �����Ҫ���� */
//			if ( X < T->lchild->data ) 
//			T = SingleLeftRotation(T);      //���� LL
//		else 
//			T = DoubleLeftRightRotation(T); //��-��˫��LR
//	} /* else if (����������) ���� */
//
//	else if ( X > T->data ) {
//	T->rchild = Insert( T->rchild, X );/* ����T�������� */
//	if ( GetHeight(T->lchild)-GetHeight(T->rchild) == -2 )/* �����Ҫ���� */
//		if ( X > T->rchild->data ) 
//		T = SingleRightRotation(T);     //�ҵ��� RR
//		else 
//		T = DoubleRightLeftRotation(T); //��-��˫�� RL
//	} /* else if (����������) ���� */
//
//	/*else X == T->Data��������� */
//	T->height = Max( GetHeight(T->lchild), GetHeight(T->rchild) ) + 1;    //�������� 
//	return T;
//}


/*�������*/
void InOrderTraverse_AVL(AVLTree T){
		if(T){
		InOrderTraverse_AVL(T->lchild);
		printf("%d\t",T->data);
		InOrderTraverse_AVL(T->rchild);
	}

}

#endif
