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

/*存储结构*/
typedef struct{
	SElemType *base;	//栈尾指针
	SElemType *top;		//栈顶指针
	int size;			//栈的大小 
}SqStack;

/*初始化栈*/
Status InitStack(SqStack *S){
	S->base = (SElemType *)malloc(INIT_SIZE * sizeof(SElemType));
	if (!S->base)
		exit(OVERFLOW);
	S->top = S->base;
	S->size = INIT_SIZE;
	return OK; 
}

/*销毁栈*/
Status DestroyStack(SqStack *S){
	free(S->base);
	S->base = NULL;
	S->top = NULL;
	S->size = 0;
	return OK;
}

/*清空栈*/
Status ClearStack(SqStack *S){
	S->top = S->base;
	return OK;
} 

/*判断栈是否为空*/
Status IsEmpty(SqStack S){
	if(S.top == S.base)
		return True;
	else
		return False;
}

/*获取栈的长度*/
int GetLength(SqStack S){
	return S.top - S.base;
}

	
/*获取栈顶元素*/
Status GetTop(SqStack S, SElemType *e)
{
    if (S.top > S.base)
    {	
    	printf("%d\n",*(--S.top));
		printf("%d\n",*S.base);
		--S.top;
        *e = *S.top;	//*e 指针，再用*e 是取e的值 
        return OK;
    }
    else
    {
        return ERROR;
    }
}

/*压栈*/
/*realloc则对malloc申请的内存进行大小的调整.给一个已经分配了地址的指针重新分配空间
void* realloc(void* ptr, unsigned newsize);  
参数ptr为原有的空间地址,newsize是重新申请的地址长度.*/ 
Status Push(SqStack *S, SElemType e){
	
	//栈满追加存储空间 
	if((S->top - S->base)/sizeof(SElemType) >= S->size){
		S->base = (SElemType *)realloc(S->base, (S->size + INCREMENT_SIZE) * sizeof(SElemType));
		
		if (!S->base)
			exit(OVERFLOW);	
			
		S->top = S->base+S->size;	//realloc可能返回新的地址，所有top的地址需重新确定 
		S->size += INCREMENT_SIZE;	//更新size的值 
	}
	*S->top = e;
	S->top++;
	return OK;
} 

/*退栈*/
Status Pop(SqStack *S, SElemType *e){
	if (S->top == S->base)
		return ERROR;
	S->top--;
	*e = *S->top;
	return OK;
}

/*访问元素*/
void visit(SElemType e){
	printf("%d", e);
}	 

/*遍历栈*/
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
		
		printf("遍历第一遍:\n"); 
		TraverseStack(S, *visit);
		
		GetTop(S, &e);
		printf("The first element is %d \n", e);
		
		printf("Length is %d \n", GetLength(S));
		
		Pop(&S,&e);
		printf("Pop element is %d\n",e);
		
		printf("遍历第二遍:\n"); 
		TraverseStack(S, *visit);
		if (DestroyStack(&S)){
			printf("\nDestroy_success\n");
		}
	}

} 
