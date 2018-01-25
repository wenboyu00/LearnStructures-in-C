#include <stdio.h>
#include "BST.c"

void main(){
	int i,e,l;
	BinTree tmp;
	/*初始化随机种子,*/
	srand(time(0));
	printf("创建二叉搜索树-数值随机生成,请输入长度:\n");
	BinTree BST = NULL;		//二叉树根节点 
	scanf("%d",&l);
	/*创建+插入测试*/
	for(i = 1; i <= l; i++){ 
		e = rand() % 100 + 1;		/*随机生成100以内的数字赋值给结构体data*/          
		BST = Insert(e,BST);
	}
	printf("遍历二叉树:\n");
	InOrderTraverse(BST);
	
	/*插入测试*/
	printf("\n\n/*插入测试*/\n"); 
	BST = Insert(55, BST);
	printf("遍历二叉树:\n");
	InOrderTraverse(BST);
	
	/*删除测试*/
	printf("\n\n/*删除测试*/\n");
	BST = Delete(24, BST);
	printf("遍历二叉树:\n");
	InOrderTraverse(BST);
	
	/*查找测试*/
	printf("\n\n/*查找测试*/\n");
	printf("递归查找：30——"); 
	tmp = Find(30, BST);
	if(tmp)
		printf("查找到：%d\n",tmp->data);
	else
		printf("未找到");
	
	printf("\n非递归查找：40——"); 
	tmp = Find(30, BST);
	if(tmp)
		printf("查找到：%d\n",tmp->data);
	else
		printf("未找到"); 

	tmp = FindMax(BST);
	printf("\n查找最大：%d",tmp->data);
	
	tmp = FindMin(BST);
	printf("\n查找最小：%d",tmp->data);  
}
