#include<stdio.h>
#include "AVL.c"


void main(){
	int i, n, data;
	srand(time(0)); 
	AVLTree T = NULL;
	printf("�����������������볤�ȣ����������ֵ:\n");
	scanf("%d", &n);
	/*����+��ƽ�����*/ 
	for(i = 0; i < n ; i++){
		data = rand()% 100 + 1;
		T = Insert(T, data);
	}
	printf("����������:\n"); 
	InOrderTraverse_AVL(T);
	
	/*�������*/
	printf("\n\n/*�������*/\n"); 
	T = Insert(T, 55);
	printf("����������:\n");
	InOrderTraverse_AVL(T); 
} 
