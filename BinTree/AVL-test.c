#include<stdio.h>
#include "AVL.c"


void main(){
	int i, n, data;
	srand(time(0)); 
	AVLTree T = NULL;
	printf("创建二叉树，请输入长度，随机生成数值:\n");
	scanf("%d", &n);
	/*插入+自平衡测试*/ 
	for(i = 0; i < n ; i++){
		data = rand()% 100 + 1;
		T = Insert(T, data);
	}
	printf("遍历二叉树:\n"); 
	InOrderTraverse_AVL(T);
	
	/*插入测试*/
	printf("\n\n/*插入测试*/\n"); 
	T = Insert(T, 55);
	printf("遍历二叉树:\n");
	InOrderTraverse_AVL(T); 
} 
