#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0
#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int Status;
typedef int TElemType;

/*二叉树递归遍历*/
/*存储结构*/
typedef struct BinTNode{
	TElemType data;
	struct BinTNode *lchild, *rchild;
}BinTNode, *BinTree;
/*BinTree是BinTNode*的typedef(类型定义)
BinTree* T就是BInTNode** T，是二级指针——指向“指向结构体的指针”的指针 
那*T就是BinNode*
(*T)->lchild ==指向结构体的指针取结构体成员*/ 

/*创建二叉树，输入0表示创建空树，先序输入*/
Status CreateBinTree(BinTree *T){
	TElemType e;
	scanf("%d",&e);
	if(e == 0)
		*T = NULL;		//指向结构体的指针为NULL空，不指向任何东西 
	else{
		*T = (BinTree)malloc(sizeof(BinTNode));
		if(!T)
			exit(OVERFLOW);
		(*T)->data = e;
		/* &(*T)->lchild：
		(*T)->lchild，取结构体成员
		lchild，指向结构体的指针
		&(*T)->lchild，取指向结构体指针的地址*/
		CreateBinTree(&(*T)->lchild);		//创建左子树，递归中再用*T修改结点内容 
		CreateBinTree(&(*T)->rchild);		//创建右子树 
	}
	return OK; 
}

/*先序遍历二叉树：根-左-右*/
Status PreOrderTraverse(BinTree T)
{
    if (T)
    {
        printf("%d",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

/*中序遍历二叉树：左-根-右*/
Status InOrderTraverse(BinTree T)
{
    if (T)
    {
        InOrderTraverse(T->lchild);
        printf("%d",T->data);
        InOrderTraverse(T->rchild);
    }
}

/*后序遍历二叉树：左-右-根*/
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
    printf("创建树，输入0为空树：\n");
    CreateBinTree(&T);
    printf("先序遍历：");
    PreOrderTraverse(T);
    printf("\n中序遍历：");
    InOrderTraverse(T);
    printf("\n后序遍历：");
    PostOrderTraverse(T);
    printf("\n");

    return 0;
}

