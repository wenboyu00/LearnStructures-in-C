#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

/*��ͷ��������
ͷָ��ָ��ͷ���
ͷ����ָ�� ָ���һ�����ݽ��*/
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

/*����λ�û�ȡԪ��
��ʼ��������˳�����Ա�L�Ѿ����ڣ�1 <=i<=ListLength(l)
�����������e����L�е�i������Ԫ�ص�ֵ*/
Status GetElem(LinkList L, int i, ElemType *e){
	int j = 1;				/*jΪ������*/ 
	LinkList p = L->next;	/*����һ��ָ��ڵ�p,p=l->next������һ���ڵ�*/
	while(p && j < i){		/*p��Ϊ�ջ��ʱ����û�е���iʱ��ѭ��*/
		j++;				/*������+1*/ 
		p = p->next;		/*��pָ����һ���ڵ�*/
	}
	if(!p || j > i)
		return ERROR;
	*e = p->data;
	return OK;
	/*��ͷ��ʼ�ң�֪���ҵ���i��Ԫ��Ϊֹ������O(n)*/
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
	return FALSE;
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


/*����Ԫ��
��ʼ������˳�����Ա�L�Ѿ����ڣ� 1 <=i<=Listlength(L)
�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1*/
Status ListInsert(LinkList *L, int i , ElemType e){
	int j;
	LinkList p,s;	/*�½�2��ָ��ڵ��ָ��*/
	p = *L;			/*p=ͷָ��*/ 
	j = 1;
	
	while(p && j < i){	/*���β��ҵ�i���ڵ�*/ 
		p = p->next;
		++j;
	}
	
	if(!p || j > i){	/*pΪ�գ����ҵ��б�βʱ��j����i����Ҫ����Ԫ�ص�λ��ʱ
						���ش�����ʾ����i��Ԫ�ز�����*/
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(LNode));		/*�����µĽڵ㣬�����ڴ棨C������*/ 
	s->data = e;							/*��eֵ��ֵ��s�ڵ��������*/ 
	s->next = p->next;						/*��p�ĺ�̽ڵ��ַ��ֵ��s�ĺ��
											��s��ֵΪp�ĺ��*/
	p->next = s;
	return OK;
}


/*ɾ��Ԫ�ز�����ֵ*/
Status DeleteElem(LinkList *L, int i ,ElemType *e){
	int j = 1;
	LinkList q, p;
	p = *L;
	//�ҵ���i����� 
	while(p->next && j < i - 1){
		j++;
		p = p->next;
	}
	if(!p->next || j > i-1)		/*p->nextΪ�ձ�ʾû����һ��Ԫ��*/
		return ERROR;
	//qָ��ָ��i��� 
	q = p->next;
	p->next = q->next;			/*��q�ĺ�̸�ֵ����p�ĺ��*/ 
	*e = q->data;				/*��q�ڵ��е����ݸ�e* */ 
	free(q);					/*�ͷ��ڴ�*/
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

/*�������n��Ԫ�ص�ֵ����������ͷ�ڵ�ĵ�����L��β�巨��*/ 
/* LinkList��ָ�룬ָ��struct LNode�ṹ��LNode����LNode 
LinkList *L��ָ��LinkList��ָ�룬Ҳ����ָ����������Ϊͷָ�� 
*L������һ����ַ�ϵ����� 
*Lָ��Ķ����ֵ�����ݣ�Ҳ����ListList��linkList��Node *��ָ�����һ���ṹ��*/ 
void CreateListTail(LinkList *L, int n){
	LinkList p,r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(LNode));	/*Lָ����������Ϊ����ͷ���*/
	r = *L;
										/*rΪָ��β���Ľڵ㣬*/ 
	for(i=0; i < n; i++){
		p = (LNode *)malloc(sizeof(LNode));	/*�����½ڵ�*/ 
		p->data = rand() % 10 +1;
		r->next=p;							/*����β�ն˽ڵ��ָ��ָ���½ڵ�*/ 
		r=p; 								/*����ǰ���½ڵ㶨��Ϊ��β�ն˽ڵ�*/ 
	}
	r->next = NULL;							/*��ʾ��ǰ������β���ָ������ΪNULL*/ 
	/*L�� r �Ĺ�ϵ��L��ָ������������r��ָ��β�ڵ�ı�����
	r ������ѭ�����ϵر仯�ڵ�
	L��������ѭ������ Ϊһ����ڵ������
	
	ָ��Ҳ�Ǳ���iq����һ��ָ�����͵�ָ�� iq = ip����ip�е�ֵ������iq�У�����iqҲ��ָ��ipָ��Ķ���*/ 
}

void main(){
	LinkList L;	//����һ��LinkList 
	CreateListTail(&L, 10);	//�������LinkList�ĵ�ַ 
	ElemType e;
	int i;
	
	if(L)
		printf("init success!\n");
	if(isEmpty(L))
		printf("List is empty��\n ");
	/ 
//	for (i =0; i < 10; i++)
//		ListInsert(&L, i + 1 ,i);
	
	if(GetElem(L, 1, &e)){
		printf("The first element is %d\n", e);
	}
		
	printf("length is %d\n", GetLength(L));
	
	printf("The 5 at %d\n", FindElem(L, 5 ,*compare));
	
	PreElem(L, 6, &e);
	printf("The 6's previos element is %d\n", e);
	
	DeleteElem(&L, 1, &e);
	printf("Delete first element is %d\n",e);
	
	printf("list:");
	TraverseList(L, visit);
	
	DestroyList(&L);
	if(!L){
		printf("\ndestroy sucess\n");
	} 
}
