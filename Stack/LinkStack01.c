#ifndef LINKSTACK01_C 
#define LINKSTACK01_C
 
#include"LinkStack01.h"

/*����ջ*/ 
Stack CreateStack(){
	Stack S;
	S = (PtrToSNode)malloc(sizeof(SNode));
	S->next = NULL;
	return S;
}

/*�Ƿ�Ϊ��*/
Status IsEmpty(Stack S){
	int i = (S->next == NULL);
	if(i){
		printf("\nջ�ѿ�\n"); 
	}
	return (S->next == NULL);
}

/*��ջ*/ 
Status Push(Stack S , SElemType x){
	/*��ʱָ��+����ռ�*/ 
	PtrToSNode tmpCell;
	tmpCell = (PtrToSNode)malloc(sizeof(SNode));
	
	tmpCell->data = x;			//�õ���ջֵ 
	tmpCell->next = S->next;	//��ʱָ��ָ��ԭջ�� 
	S->next = tmpCell; 			//ջ������ָ���½�� 
	return OK;
}

/*��ջ*/
SElemType Pop(Stack S){
	PtrToSNode firstCell;
	SElemType topElem;
	
	/*�ж��Ƿ�Ϊ�գ���Ϊ�գ��޷���ջ*/ 
	if(IsEmpty(S)){
		printf("�޷���ջ\n");
		return ERROR; 
	}
	else{
		firstCell = S->next;		//���ջ�� 
		topElem = firstCell->data;	//�õ�ջ����ֵ 
		S->next = firstCell->next;	//ʹջ��ָ������һλ��ָ���һ����� 
		free(firstCell);			//�ͷž�ջ��Ԫ�� 
		return topElem; 			//���ؾ�ջ��ֵ 
	}
}

#endif
