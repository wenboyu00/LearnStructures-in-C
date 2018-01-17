#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
/*����ͷ��������*/
/*https://www.shiyanlou.com/courses/20*/ 
typedef int Status;
typedef int ElemType;

/*�洢�ṹ*/
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

/*��ʼ�����Ա�*/
void InitList(LinkList *L){
	*L = (LinkList)malloc(sizeof(LNode));	//Ϊ��������ڴ�ռ� 
	if(!L)									//���ɾͱ��� 
		exit(OVERFLOW);
	(*L)->next = NULL;						//����һ����ͷ���ĵ����� 
} 
/*�������Ա�*/
void DestroyList(LinkList *L){
	LinkList temp;
	while(*L){
		temp =(*L)->next;
		free(*L);
		*L = temp;
	}
}

/*������Ա�*/ 
void ClearList(LinkList L){
	LinkList p = L->next;
	L->next = NULL;
	DestroyList(&p);
}

/*�ж��Ƿ�Ϊ��*/
Status isEmpty(LinkList L){
	if(L->next){
		return FALSE;
	}
	else{
		return TRUE;
	}
}

/*��ȡ����*/ 
int GetLength(LinkList L){
	int i = 0;
	LinkList p = L->next;
	while(p){
		i++;
		p = p->next;
	}
	return i;
}

/*�Ƚ�����Ԫ���Ƿ����*/
Status compare(ElemType e1, ElemType e2){
	if (e1 == e2)
		return 0;
	else if (e1 < e2)
		return -1;
	else 
		return 1;
} 	

/*����λ�û�ȡԪ��*/
Status GetElem(LinkList L, int i, ElemType *e){
	int j = 1;
	LinkList p = L->next;
	while(p && j < i){
		j++;
		p = p->next;
	}
	if(!p || j > i)
		return ERROR;
	*e = p->data;
	return OK;
}

/*����ָ��Ԫ�ص�λ��*/
int FindElem(LinkList L , ElemType e, Status(*compare)(ElemType, ElemType)){
	int i = 0;
	LinkList p = L->next;
	while(p){
		i++;
		if(!compare(p->data, e)){
			return i;
		}
		p = p->next; 
	}
	return 0;
} 

/*��ȡǰ��Ԫ��*/
Status PreElem(LinkList L ,ElemType cur_e, ElemType *pre_e){
	LinkList q,p = L->next;
	while(p->next){
		q = p->next;
		if(q->data == cur_e){
			*pre_e = p->data;
			return OK;
		}
		p = q;
	}
	return ERROR;
}

/*��ú��Ԫ��*/
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e){
	LinkList p = L->next;
	while(p->next){
		if (p->data == cur_e){
			*next_e = p->next->data;
			return OK; 
		}
		p = p->next;
	}
	return ERROR;
}

/*����Ԫ��*/
Status InsertElem(LinkList L, int i, ElemType e){
	int j = 0;
	LinkList s, p = L;
	//�ҵ�i֮ǰ��㣬 
	while(p && j < i - 1){
		j++;
		p = p->next;
	}
	if(!p || j > i - 1)
		return ERROR;
	
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;	
}

/*ɾ��Ԫ�ز�����ֵ*/
Status DeleteElem(LinkList L, int i ,ElemType *e){
	int j = 0;
	LinkList q, p = L;
	//�ҵ�i֮ǰ�Ľ�� 
	while(p->next && j < i - 1){
		j++;
		p = p->next;
	}
	if(!p->next || j > i-1)
		return ERROR;
	//qָ��ָ��i��� 
	q = p->next;
	p->next = q->next;	//��i+1����ַ���� i-1->next 
	*e = q->data;		//��ȡ��i���ֵ 
	free(q);			//�ͷ�i����ڴ�ռ� 
	return OK;	
}

/*����Ԫ��*/
void visit(ElemType e){
	printf("%d", e);
} 

/*�������Ա�*/	
void TraverseList(LinkList L , void(*vist)(ElemType)){
	LinkList p = L->next;
	while(p){
		visit(p->data);
		p = p->next;
	}
}

void main(){
	LinkList L;
	InitList(&L);
	ElemType e;
	int i;
	if(L){
		printf("init success!\n");
	}
	if(isEmpty(L))
		printf("List is empty��\n ");
	
	for (i =0; i < 10; i++)
		InsertElem(L, i + 1 ,i);
	
	if(GetElem(L, 1, &e)){
		printf("The first element is %d\n", e);
	}
		
	printf("length is %d\n", GetLength(L));
	
	printf("The 5 at %d\n", FindElem(L, 5 ,*compare));
	
	PreElem(L, 6, &e);
	printf("The 6's previos element is %d\n", e);
	
	DeleteElem(L, 1, &e);
	printf("Delete first element is %d\n",e);
	
	printf("list:");
	TraverseList(L, visit);
	
	DestroyList(&L);
	if(!L){
		printf("\n destroy sucess\n");
	} 
}
