#ifndef LINKSTACK01_C 
#define LINKSTACK01_C
 
#include"LinkStack01.h"

/*创建栈*/ 
Stack CreateStack(){
	Stack S;
	S = (PtrToSNode)malloc(sizeof(SNode));
	S->next = NULL;
	return S;
}

/*是否为空*/
Status IsEmpty(Stack S){
	int i = (S->next == NULL);
	if(i){
		printf("\n栈已空\n"); 
	}
	return (S->next == NULL);
}

/*入栈*/ 
Status Push(Stack S , SElemType x){
	/*临时指针+申请空间*/ 
	PtrToSNode tmpCell;
	tmpCell = (PtrToSNode)malloc(sizeof(SNode));
	
	tmpCell->data = x;			//得到入栈值 
	tmpCell->next = S->next;	//临时指针指向原栈顶 
	S->next = tmpCell; 			//栈顶重新指向新结点 
	return OK;
}

/*出栈*/
SElemType Pop(Stack S){
	PtrToSNode firstCell;
	SElemType topElem;
	
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

#endif
