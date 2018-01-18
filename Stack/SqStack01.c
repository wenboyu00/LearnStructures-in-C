#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INIT_SIZE 20
#define INCREMENT_SIZE 5

typedef int SElemType;
typedef int Status;

/*�洢�ṹ*/
typedef struct{
	SElemType *base;	//ջβָ��
	SElemType *top;		//ջ��ָ��
	int size;			//ջ�Ĵ�С 
}SqStack;

/*��ʼ��ջ*/
Status InitStack(SqStack *S){
	S->base = (SElemType *)malloc(INIT_SIZE * sizeof(SElemType));
	if (!S->base)
		exit(OVERFLOW);
	S->top = S->base;
	S->size = INIT_SIZE;
	return OK; 
}

/*����ջ*/
Status DestroyStack(SqStack *S){
	free(S->base);
	S->base = NULL;
	S->top = NULL;
	S->size = 0;
	return OK;
}

/*���ջ*/
Status ClearStack(SqStack *S){
	S->top = S->base;
	return OK;
} 

/*�ж�ջ�Ƿ�Ϊ��*/
Status IsEmpty(SqStack S){
	if(S.top == S.base)
		return True;
	else
		return False;
}

/*��ȡջ�ĳ���*/
int GetLength(SqStack S){
	return S.top - S.base;
}

	
/*��ȡջ��Ԫ��*/
Status GetTop(SqStack S, SElemType *e)
{
    if (S.top > S.base)
    {	
    	printf("%d\n",*(--S.top));
		printf("%d\n",*S.base);
		--S.top;
        *e = *S.top;	//*e ָ�룬����*e ��ȡe��ֵ 
        return OK;
    }
    else
    {
        return ERROR;
    }
}

/*ѹջ*/
/*realloc���malloc������ڴ���д�С�ĵ���.��һ���Ѿ������˵�ַ��ָ�����·���ռ�
void* realloc(void* ptr, unsigned newsize);  
����ptrΪԭ�еĿռ��ַ,newsize����������ĵ�ַ����.*/ 
Status Push(SqStack *S, SElemType e){
	
	//ջ��׷�Ӵ洢�ռ� 
	if((S->top - S->base)/sizeof(SElemType) >= S->size){
		S->base = (SElemType *)realloc(S->base, (S->size + INCREMENT_SIZE) * sizeof(SElemType));
		
		if (!S->base)
			exit(OVERFLOW);	
			
		S->top = S->base+S->size;	//realloc���ܷ����µĵ�ַ������top�ĵ�ַ������ȷ�� 
		S->size += INCREMENT_SIZE;	//����size��ֵ 
	}
	*S->top = e;
	S->top++;
	return OK;
} 

/*��ջ*/
Status Pop(SqStack *S, SElemType *e){
	if (S->top == S->base)
		return ERROR;
	S->top--;
	*e = *S->top;
	return OK;
}

/*����Ԫ��*/
void visit(SElemType e){
	printf("%d", e);
}	 

/*����ջ*/
Status TraverseStack(SqStack S , void(*visit)(SElemType)){
	while(S.top>S.base){
		visit(*S.base);
		S.base++;
	}
	return OK;
}

void main(){
	SqStack S;
	if(InitStack(&S)){
		SElemType e;	
		int i;
		printf("Init_Success\n");
		
		if(IsEmpty(S))
			printf("Stack is empty\n");
			
		for(i=0; i<10; i++)
			Push(&S,i);
		
		printf("������һ��:\n"); 
		TraverseStack(S, *visit);
		
		GetTop(S, &e);
		printf("The first element is %d \n", e);
		
		printf("Length is %d \n", GetLength(S));
		
		Pop(&S,&e);
		printf("Pop element is %d\n",e);
		
		printf("�����ڶ���:\n"); 
		TraverseStack(S, *visit);
		if (DestroyStack(&S)){
			printf("\nDestroy_success\n");
		}
	}

} 
