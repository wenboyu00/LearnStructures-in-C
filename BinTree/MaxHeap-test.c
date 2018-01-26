#include <stdio.h>
#include "MaxHeap.c"

void main(){
	/*测试创建*/ 
	int i, n, data;
	srand(time(0)); 
	printf("创建二叉树，请输入长度，随机生成数值:\n");
	scanf("%d", &n);
	MaxHeap Heap = CreateHeap(n);
	
	/*插入随机数*/ 
	for(i = 0; i < n ; i++){
		data = rand()% 100 + 1;
		Insert(Heap, data);
	}
	printf("遍历二叉树:\n"); 
	InOrderTraverse_MaxHeap(Heap);
	
	/*删除测试*/
	printf("\n\n/*插入测试*/\n"); 
	printf("删除的最大元素: %d\n", DeleteMax(Heap));
	printf("遍历二叉树:\n");
	InOrderTraverse_MaxHeap(Heap); 
	
	/*插入测试*/
	printf("\n\n/*插入测试*/\n"); 
	Insert(Heap, 66);
	printf("遍历二叉树:\n");
	InOrderTraverse_MaxHeap(Heap); 
} 
