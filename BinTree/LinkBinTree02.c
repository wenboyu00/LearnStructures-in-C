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
#endif 
