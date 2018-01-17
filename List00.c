#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
/*不带头结点的链表*/
/*https://www.shiyanlou.com/courses/20*/ 
typedef int Status;
typedef int ElemType;

/*存储结构*/
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

/*初始化线性表*/
void InitList(LinkList *L){
	*L = (LinkList)malloc(sizeof(LNode));	//为结点申请内存空间 
	if(!L)									//不成就报错 
		exit(OVERFLOW);
	(*L)->next = NULL;						//建立一个带头结点的单链表 
} 
/*销毁线性表*/
void DestroyList(LinkList *L){
	LinkList temp;
	while(*L){
		temp =(*L)->next;
		free(*L);
		*L = temp;
	}
}

/*清空线性表*/ 
void ClearList(LinkList L){
	LinkList p = L->next;
	L->next = NULL;
	DestroyList(&p);
}

/*判断是否为空*/
Status isEmpty(LinkList L){
	if(L->next){
		return FALSE;
	}
	else{
		return TRUE;
	}
}

/*获取长度*/ 
int GetLength(LinkList L){
	int i = 0;
	LinkList p = L->next;
	while(p){
		i++;
		p = p->next;
	}
	return i;
}

/*比较两个元素是否相等*/
Status compare(ElemType e1, ElemType e2){
	if (e1 == e2)
		return 0;
	else if (e1 < e2)
		return -1;
	else 
		return 1;
} 	

/*根据位置获取元素*/
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

/*查找指定元素的位置*/
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

/*获取前驱元素*/
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

/*获得后继元素*/
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

/*插入元素*/
Status InsertElem(LinkList L, int i, ElemType e){
	int j = 0;
	LinkList s, p = L;
	//找到i之前结点， 
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

/*删除元素并返回值*/
Status DeleteElem(LinkList L, int i ,ElemType *e){
	int j = 0;
	LinkList q, p = L;
	//找到i之前的结点 
	while(p->next && j < i - 1){
		j++;
		p = p->next;
	}
	if(!p->next || j > i-1)
		return ERROR;
	//q指针指向i结点 
	q = p->next;
	p->next = q->next;	//把i+1结点地址付给 i-1->next 
	*e = q->data;		//提取出i结点值 
	free(q);			//释放i结点内存空间 
	return OK;	
}

/*访问元素*/
void visit(ElemType e){
	printf("%d", e);
} 

/*遍历线性表*/	
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
		printf("List is empty！\n ");
	
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
