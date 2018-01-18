#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0
#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int Status;
typedef int TElemType;

/*�������ݹ����*/
/*�洢�ṹ*/
typedef struct BinTNode{
	TElemType data;
	struct BinTNode *lchild, *rchild;
}BinTNode, *BinTree;
/*BinTree��BinTNode*��typedef(���Ͷ���)
BinTree* T����BInTNode** T���Ƕ���ָ�롪��ָ��ָ��ṹ���ָ�롱��ָ�� 
��*T����BinNode*
(*T)->lchild ==ָ��ṹ���ָ��ȡ�ṹ���Ա*/ 

/*����������������0��ʾ������������������*/
Status CreateBinTree(BinTree *T){
	TElemType e;
	scanf("%d",&e);
	if(e == 0)
		*T = NULL;		//ָ��ṹ���ָ��ΪNULL�գ���ָ���κζ��� 
	else{
		*T = (BinTree)malloc(sizeof(BinTNode));
		if(!T)
			exit(OVERFLOW);
		(*T)->data = e;
		/* &(*T)->lchild��
		(*T)->lchild��ȡ�ṹ���Ա
		lchild��ָ��ṹ���ָ��
		&(*T)->lchild��ȡָ��ṹ��ָ��ĵ�ַ*/
		CreateBinTree(&(*T)->lchild);		//�������������ݹ�������*T�޸Ľ������ 
		CreateBinTree(&(*T)->rchild);		//���������� 
	}
	return OK; 
}

/*�����������������-��-��*/
Status PreOrderTraverse(BinTree T)
{
    if (T)
    {
        printf("%d",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

/*�����������������-��-��*/
Status InOrderTraverse(BinTree T)
{
    if (T)
    {
        InOrderTraverse(T->lchild);
        printf("%d",T->data);
        InOrderTraverse(T->rchild);
    }
}

/*�����������������-��-��*/
Status PostOrderTraverse(BinTree T)
{
    if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%d",T->data);
    }
}

int main()
{
    BinTree T;
    printf("������������0Ϊ������\n");
    CreateBinTree(&T);
    printf("���������");
    PreOrderTraverse(T);
    printf("\n���������");
    InOrderTraverse(T);
    printf("\n���������");
    PostOrderTraverse(T);
    printf("\n");

    return 0;
}

