#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

/*带头结点的链表
头指针指向头结点
头结点的指针 指向第一个数据结点*/
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

/*根据位置获取元素
初始化条件：顺序线性表L已经存在，1 <=i<=ListLength(l)
操作结果：用e返回L中第i个数据元素的值*/
Status GetElem(LinkList L, int i, ElemType *e){
	int j = 1;				/*j为计数器*/ 
	LinkList p = L->next;	/*声明一个指针节点p,p=l->next，即第一个节点*/
	while(p && j < i){		/*p不为空或计时器还没有等于i时，循环*/
		j++;				/*计数器+1*/ 
		p = p->next;		/*让p指向下一个节点*/
	}
	if(!p || j > i)
		return ERROR;
	*e = p->data;
	return OK;
	/*从头开始找，知道找到第i个元素为止。最坏情况O(n)*/
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
	return FALSE;
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


/*插入元素
初始条件：顺序线性表L已经存在， 1 <=i<=Listlength(L)
操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1*/
Status ListInsert(LinkList *L, int i , ElemType e){
	int j;
	LinkList p,s;	/*新建2个指向节点的指针*/
	p = *L;			/*p=头指针*/ 
	j = 1;
	
	while(p && j < i){	/*依次查找第i个节点*/ 
		p = p->next;
		++j;
	}
	
	if(!p || j > i){	/*p为空，查找到列表尾时或j大于i超过要查找元素的位置时
						返回错误提示。第i个元素不存在*/
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(LNode));		/*生成新的节点，申请内存（C函数）*/ 
	s->data = e;							/*把e值赋值给s节点的数据上*/ 
	s->next = p->next;						/*将p的后继节点地址赋值给s的后继
											将s赋值为p的后继*/
	p->next = s;
	return OK;
}


/*删除元素并返回值*/
Status DeleteElem(LinkList *L, int i ,ElemType *e){
	int j = 1;
	LinkList q, p;
	p = *L;
	//找到第i个结点 
	while(p->next && j < i - 1){
		j++;
		p = p->next;
	}
	if(!p->next || j > i-1)		/*p->next为空表示没有下一个元素*/
		return ERROR;
	//q指针指向i结点 
	q = p->next;
	p->next = q->next;			/*将q的后继赋值给给p的后继*/ 
	*e = q->data;				/*将q节点中的数据给e* */ 
	free(q);					/*释放内存*/
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

/*随机产生n个元素的值，建立带表头节点的单链表L（尾插法）*/ 
/* LinkList是指针，指向struct LNode结构，LNode别名LNode 
LinkList *L是指向LinkList的指针，也就是指整个链表，做为头指针 
*L就是这一个地址上的内容 
*L指向的对象的值（内容）也就是ListList，linkList是Node *，指向的是一个结构体*/ 
void CreateListTail(LinkList *L, int n){
	LinkList p,r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(LNode));	/*L指向整个链表，为链表头结点*/
	r = *L;
										/*r为指向尾部的节点，*/ 
	for(i=0; i < n; i++){
		p = (LNode *)malloc(sizeof(LNode));	/*生成新节点*/ 
		p->data = rand() % 10 +1;
		r->next=p;							/*将表尾终端节点的指针指向新节点*/ 
		r=p; 								/*将当前的新节点定义为表尾终端节点*/ 
	}
	r->next = NULL;							/*表示当前链表，把尾结点指针设置为NULL*/ 
	/*L与 r 的关系，L是指整个单链表，而r是指向尾节点的变量；
	r 会随着循环不断地变化节点
	L则是随着循环增长 为一个多节点的链表
	
	指针也是变量iq是另一个指向整型的指针 iq = ip将把ip中的值拷贝到iq中，这样iq也将指向ip指向的对象*/ 
}

void main(){
	LinkList L;	//声明一个LinkList 
	CreateListTail(&L, 10);	//传入这个LinkList的地址 
	ElemType e;
	int i;
	
	if(L)
		printf("init success!\n");
	if(isEmpty(L))
		printf("List is empty！\n ");
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
