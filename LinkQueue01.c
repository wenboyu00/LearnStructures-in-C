#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2


typedef int QElemType;
typedef int Status;

/*存储结构*/
typedef struct QNode{
	QElemType data;
	struct QNode *next; 
}QNode, *QueuePtr;

typedef struct{
	QueuePtr front;		//队头指针 
	QueuePtr rear;		//队尾指针 
}LinkQueue;

/*初始化队列*/
Status InitQueue(LinkQueue *Q){
	/*为队尾和队首指针申请空间*/ 
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
		exit(OVERFLOW);
		
	Q->front->next = NULL;		//队首指向置空 
	return OK;
} 

/*销毁队列*/ 
Status DestroyQueue(LinkQueue *Q){
	while(Q->front){
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK; 
}

/*清空队列*/
Status ClearQueue(LinkQueue *Q){
	DestroyQueue(Q);
	InitQueue(Q);
	return OK; 
} 

/*判断队列是否为空*/
Status IsEmpty(LinkQueue Q){
	if(Q.front->next == NULL)
		return True;
	else
		return False; 
} 

/*获得队列的长度*/
int GetLength(LinkQueue Q){
	int i = 0;
	QueuePtr p = Q.front;
	while(Q.rear != p){
		i++;
		p = p->next;
	}
	return i;
}

/*获取对头元素*/
Status GetHead(LinkQueue Q, QElemType *e){
	QueuePtr p;
	if(Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	*e = p->data;
	return OK; 
} 

/*入队*/
Status EnQueue(LinkQueue *Q, QElemType e){
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	
	if(!p)					/* 存储分配失败 */
		exit(OVERFLOW);
	
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;		/* 把新结点p赋值为原队尾结点的后继，原队尾指向新队尾*/
	Q->rear = p;			/* 把当前的p设置为队尾结点，rear指向p */
	return OK; 
} 

/*出队*/
/* 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR */ 
Status DeQueue(LinkQueue *Q, QElemType *e){
	QueuePtr p;
	
	if (Q->front == Q->rear)
		return ERROR;
	
	p = Q->front->next;			/* 将要删除的队头结点暂存给p */
	*e = p->data;				/* 将要删除的队头结点的值赋值给e */
	Q->front->next = p->next;	/* 将原队头结点的后继p->next赋值给头结点后继*/	
	
	if(Q->rear == p){			 /* 若队头就是队尾，则删除后将rear指向头结点*/
		Q->rear = Q->front;
	}
	free(p);
	return OK;
}

/*访问元素*/
void visit(QElemType e)
{
    printf("%d ", e);
}

/*遍历队列*/
Status TraverseQueue(LinkQueue Q, void(*visit)(QElemType)){
	QueuePtr p = Q.front->next;
	while(p){
		visit(p->data);
		p = p->next;
	}
	return OK;
}

/*测试*/ 
void main(){
	LinkQueue Q;
	if (InitQueue(&Q)){
		QElemType e;
		int i;
		printf("init_success!\n");
		
		/*测试 是否为空*/ 
		if(IsEmpty(Q)){
			printf("queue is empty\n");
		}
		/*测试 入队，循环入队10个值*/ 
		for(i = 0;i < 10;i++)
			EnQueue(&Q, i);
		
		/*测试 获取队头*/
		GetHead(Q, &e);
		printf("The first element is %d\n",e);
		
		/*测试 获取长度*/
		printf("Lenght is %d\n", GetLength(Q));
		
		/*测试 出队*/ 
		DeQueue(&Q, &e);
		printf("Delete element is %d\n",e);
		
		/*测试 遍历*/
		TraverseQueue(Q, *visit);
		
		/*测试 销毁队列*/
		if (DestroyQueue(&Q)) 
			printf("\nDestroy_success!\n");
	}
} 
