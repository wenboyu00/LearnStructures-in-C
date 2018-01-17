#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2


typedef int QElemType;
typedef int Status;

/*�洢�ṹ*/
typedef struct QNode{
	QElemType data;
	struct QNode *next; 
}QNode, *QueuePtr;

typedef struct{
	QueuePtr front;		//��ͷָ�� 
	QueuePtr rear;		//��βָ�� 
}LinkQueue;

/*��ʼ������*/
Status InitQueue(LinkQueue *Q){
	/*Ϊ��β�Ͷ���ָ������ռ�*/ 
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
		exit(OVERFLOW);
		
	Q->front->next = NULL;		//����ָ���ÿ� 
	return OK;
} 

/*���ٶ���*/ 
Status DestroyQueue(LinkQueue *Q){
	while(Q->front){
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK; 
}

/*��ն���*/
Status ClearQueue(LinkQueue *Q){
	DestroyQueue(Q);
	InitQueue(Q);
	return OK; 
} 

/*�ж϶����Ƿ�Ϊ��*/
Status IsEmpty(LinkQueue Q){
	if(Q.front->next == NULL)
		return True;
	else
		return False; 
} 

/*��ö��еĳ���*/
int GetLength(LinkQueue Q){
	int i = 0;
	QueuePtr p = Q.front;
	while(Q.rear != p){
		i++;
		p = p->next;
	}
	return i;
}

/*��ȡ��ͷԪ��*/
Status GetHead(LinkQueue Q, QElemType *e){
	QueuePtr p;
	if(Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	*e = p->data;
	return OK; 
} 

/*���*/
Status EnQueue(LinkQueue *Q, QElemType e){
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	
	if(!p)					/* �洢����ʧ�� */
		exit(OVERFLOW);
	
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;		/* ���½��p��ֵΪԭ��β���ĺ�̣�ԭ��βָ���¶�β*/
	Q->rear = p;			/* �ѵ�ǰ��p����Ϊ��β��㣬rearָ��p */
	return OK; 
} 

/*����*/
/* �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR */ 
Status DeQueue(LinkQueue *Q, QElemType *e){
	QueuePtr p;
	
	if (Q->front == Q->rear)
		return ERROR;
	
	p = Q->front->next;			/* ��Ҫɾ���Ķ�ͷ����ݴ��p */
	*e = p->data;				/* ��Ҫɾ���Ķ�ͷ����ֵ��ֵ��e */
	Q->front->next = p->next;	/* ��ԭ��ͷ���ĺ��p->next��ֵ��ͷ�����*/	
	
	if(Q->rear == p){			 /* ����ͷ���Ƕ�β����ɾ����rearָ��ͷ���*/
		Q->rear = Q->front;
	}
	free(p);
	return OK;
}

/*����Ԫ��*/
void visit(QElemType e)
{
    printf("%d ", e);
}

/*��������*/
Status TraverseQueue(LinkQueue Q, void(*visit)(QElemType)){
	QueuePtr p = Q.front->next;
	while(p){
		visit(p->data);
		p = p->next;
	}
	return OK;
}

/*����*/ 
void main(){
	LinkQueue Q;
	if (InitQueue(&Q)){
		QElemType e;
		int i;
		printf("init_success!\n");
		
		/*���� �Ƿ�Ϊ��*/ 
		if(IsEmpty(Q)){
			printf("queue is empty\n");
		}
		/*���� ��ӣ�ѭ�����10��ֵ*/ 
		for(i = 0;i < 10;i++)
			EnQueue(&Q, i);
		
		/*���� ��ȡ��ͷ*/
		GetHead(Q, &e);
		printf("The first element is %d\n",e);
		
		/*���� ��ȡ����*/
		printf("Lenght is %d\n", GetLength(Q));
		
		/*���� ����*/ 
		DeQueue(&Q, &e);
		printf("Delete element is %d\n",e);
		
		/*���� ����*/
		TraverseQueue(Q, *visit);
		
		/*���� ���ٶ���*/
		if (DestroyQueue(&Q)) 
			printf("\nDestroy_success!\n");
	}
} 
