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

typedef struct SNode * PtrToSNode;	//PtrToSNode指向结点的指针
typedef PtrToSNode Stack;			//Stack指向结点的指针 

Stack CreateStack(){
	Stack S;
	S = (PtrToSNode)malloc(sizeof(SNode));
	S->next = NULL;
	return S;
}

Status IsEmpty(Stack S){
	int i = (S->next == NULL);
	if(i){
		printf("栈空\n"); 
	}
	return (S->next == NULL);
}

Status Push(Stack S , ElemType x){
	/*临时指针+申请空间*/ 
	PtrToSNode tmpCell;
	tmpCell = (PtrToSNode)malloc(sizeof(SNode));
	
	tmpCell->data = x;			//得到入栈值 
	tmpCell->next = S->next;	//临时指针指向原栈顶 
	S->next = tmpCell; 			//栈顶重新指向新结点 
	return OK;
}

ElemType Pop(Stack S){
	PtrToSNode firstCell;
	ElemType topElem;
	
	/*判断是否为空，若为空，无法出栈*/ 
	if(IsEmpty(S)){
		printf("无法出栈\n");
		return ERROR; 
	}
	else{
		firstCell = S->next;		//变成栈顶 
		topElem = firstCell->data;	//得到栈顶的值 
		S->next = firstCell->next;	//使栈顶指针下移一位，指向后一个结点 
		free(firstCell);			//释放旧栈顶元素 
		return topElem; 			//返回旧栈顶值 
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
