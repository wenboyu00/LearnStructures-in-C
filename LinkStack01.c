#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;

struct SNode{
	ElemType data;
	struct SNode *next;
}SNode;

typedef struct SNode * PtrToSNode;	//PtrToSNodeָ�����ָ��
typedef PtrToSNode Stack;			//Stackָ�����ָ�� 

Stack CreateStack(){
	Stack S;
	S = (PtrToSNode)malloc(sizeof(SNode));
	S->next = NULL;
	return S;
}

Status IsEmpty(Stack S){
	int i = (S->next == NULL);
	if(i){
		printf("ջ��\n"); 
	}
	return (S->next == NULL);
}

Status Push(Stack S , ElemType x){
	/*��ʱָ��+����ռ�*/ 
	PtrToSNode tmpCell;
	tmpCell = (PtrToSNode)malloc(sizeof(SNode));
	
	tmpCell->data = x;			//�õ���ջֵ 
	tmpCell->next = S->next;	//��ʱָ��ָ��ԭջ�� 
	S->next = tmpCell; 			//ջ������ָ���½�� 
	return OK;
}

ElemType Pop(Stack S){
	PtrToSNode firstCell;
	ElemType topElem;
	
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

void main(){
	Stack S;
	S = CreateStack();
	IsEmpty(S);
	Pop(S); 

	int i;
	for(i=1;i<10;i++){
		printf("push=%d\n",i);
		Push(S,i);
	}
		
	for(i=1;i<10;i++)
		printf("pop=%d\n",Pop(S));
		
}
