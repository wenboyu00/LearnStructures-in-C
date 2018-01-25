#ifndef LINKBINTREE02_C
#define LINKBINTREE02_C

#include "LinkBinTree02.h"

Status CreateBinTree(BinTree *T){
	TElemType e; 
	scanf("%d",&e);
	if(e == 0)
		*T = NULL;		//ָ��ṹ���ָ��ΪNULL�գ���ָ���κζ��� 
	else{
		*T = (BinTree)malloc(sizeof(BinTNode));
		if(!T)
			exit(OVERFLOW);
		(*T)->data = e;
		CreateBinTree(&(*T)->lchild);		//�������������ݹ�������*T�޸Ľ������ 
		CreateBinTree(&(*T)->rchild);		//���������� 
	}
	return OK; 
}

/*�ǵݹ����-���򣨸����ң���ջ*/

/*
������㣬�ȴ�ӡ������ݣ�Ȼ���ٰѽ�����ջ���ٽ����������������ֱ��������Ϊ��
��ջ������㣬�ص���һ�����ٽ�����������
������������֮ǰ��ӡ������ݣ������ջ����������������ֱ��������Ϊ�յĲ���*/
Status StackPreOrderTraverse(BinTree T){
	if (T == NULL)
		return ERROR;
	BinTree tmp = T;
	Stack S = CreateStack();	/*��������ʼ����ջS*/ 
	while(tmp || !IsEmpty(S)){	/*������ or ջ��Ϊ��ʱ*/
		while(tmp){				/*�����ڣ���ӡ������ݣ��ѽ����ջ����������
								ֱ��������Ϊ��*/
			printf("%d ",tmp->data);
			Push(S, tmp);
			tmp = tmp->lchild;
		}
		if(!IsEmpty(S)){
			tmp = Pop(S);		/*����㵯��ջ*/
			tmp = tmp->rchild;	/*ת��������*/		
		}
	}
	return OK;
}

/*�ǵݹ����-��������ң���ջ*/

/*
������㣬�����ջ����������������ֱ��������Ϊ��
��ջ������㣬��ӡ������ݡ��ٽ����������ظ�while��tmp��ѭ������ 
*/
Status StackInOrderTraverse(BinTree T){
	if (T == NULL)
		return ERROR;
	BinTree tmp = T;
	Stack S = CreateStack();
	while(tmp || !IsEmpty(S)){
		while(tmp){						/*һֱ���󲢽���;���ѹ���ջ*/
			Push(S, tmp);
			tmp = tmp->lchild;
		}
		if(!IsEmpty(S)){
			tmp = Pop(S);				/*��㵯����ջ*/ 
			printf("%d ", tmp->data);	/*�����ʣ���ӡ���*/
			tmp = tmp->rchild;			/*ת��������*/ 
		}
	}
	return OK;
}

/*�ǵݹ����-�������Ҹ�����ջ*/

/*
����������ѵ����ڣ�����������������Ҫ�ж���������״̬���Ѿ����� or �����ڣ���Ȼ���ٷ��ʸ��ڵ㡣 

����һ����ǽ�㣺lastNode������Ѿ����ʵ�������״̬
 
����ʵ��˼·�� 
һֱ���󲢽���;���ѹ���ջ��ֱ��û��������
��ջ���н��ʱ�� 
	�õ���ǰ���
	����ýڵ���������ѱ����ʻ򲻴���
	��ʾ��ֱ�ӿ��Է��ʽ�����ݣ�
	�����Ϊ�����ʽ��lastNode = curNode����������Ѿ����ʵ������� 

��������δ�����ʹ���
	��Ѹ��ڵ���ջ������������
	
������������ڣ�����ջ������������������������һֱ���󲢽���;���ѹ���ջ���ظ���ԭ���Ĳ�����

...��������㣬�ж��������Ƿ�״̬...ѭ��...
 
*/
Status StackPostOrderTraverse(BinTree T){
	
	if (T == NULL)
		return ERROR;
	BinTree tmp = T;
	Stack S = CreateStack();
	BinTree lastNode = NULL;		/*��¼�����ʹ���ǰһ�����*/
	BinTree curNode = NULL; 		/*��¼��ǰ���*/
	
	while(tmp || !IsEmpty(S)){
		
		while(tmp){						/*һֱ���󲢽���;���ѹ���ջ*/
			Push(S, tmp);
			tmp = tmp->lchild;
		}
		
		while(!IsEmpty(S)){
			curNode = Pop(S);		/*��ǰ��㡪�����һ�����*/
			
			/*�жϵ�ǰ���������״̬��������Ϊ�� or �������Ѿ�������*/ 
			if(curNode->rchild == NULL || curNode->rchild == lastNode){		/*�����������������Ѿ�������*/ 
				printf("%d ",curNode->data);
				lastNode = curNode;											/*����Ѿ�������*/
			}	/*������δ�����ʹ�*/ 
			else{																
				Push(S,curNode);					/*��ջ��ǰ��㣬����������*/
				curNode = curNode->rchild;
				
				/*���ҽ���ظ�ԭ���ڵ��������һֱ���󲢽���;���ѹ���ջ*/
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
�������ǵݹ�����н���ջ
ջ�洢������һ����㣬����������ɺ󣬷�����һ������㣬Ȼ���ٽ�����һ������

*/

/*�������������ȣ��ߣ�*/
int PostOrderGetHeight(BinTree T){
	int leftHeight, rightHeight, maxHeight;
	if(T){
		leftHeight = PostOrderGetHeight(T->lchild);			//��������� 
		rightHeight = PostOrderGetHeight(T->rchild);		//��������� 
		maxHeight = leftHeight > rightHeight ? leftHeight : rightHeight;
		return (maxHeight + 1 );	//����������� 
	} 
	else
		return 0;		//�������Ϊ0 
}

/*���������*/
Status ClearBinTree(BinTree *T){
	if(*T){									//��������Ϊ�� 
		if((*T)->lchild)					//������� 
			ClearBinTree(&(*T)->lchild);
		if((*T)->rchild)					//������� 
			ClearBinTree(&(*T)->rchild);
		free(*T);							//�ͷŸý�� 		 
		*T = NULL;							//�ÿ�ָ�� 
	}
	return OK; 
} 

/*�Ƿ�Ϊ��*/
Status BinTreeEmpty(BinTree T){
	if(!T)
		return TRUE;
	else
		return FALSE;
}

/*����Tree�ĸ�*/
TElemType Root(BinTree T){
	if(BinTreeEmpty(T))
		return -1;
	else
		return T->data;
}

/*����ָ����ֵ*/
TElemType Value(BinTree T){
	return T->data;
}

/*����ָp��㸳ֵΪvalue*/
void Assign(BinTree T,TElemType value){
	T->data = value;
}
#endif 
