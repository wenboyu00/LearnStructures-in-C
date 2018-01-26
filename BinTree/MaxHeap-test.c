#include <stdio.h>
#include "MaxHeap.c"

void main(){
	/*���Դ���*/ 
	int i, n, data;
	srand(time(0)); 
	printf("�����������������볤�ȣ����������ֵ:\n");
	scanf("%d", &n);
	MaxHeap Heap = CreateHeap(n);
	
	/*���������*/ 
	for(i = 0; i < n ; i++){
		data = rand()% 100 + 1;
		Insert(Heap, data);
	}
	printf("����������:\n"); 
	InOrderTraverse_MaxHeap(Heap);
	
	/*ɾ������*/
	printf("\n\n/*�������*/\n"); 
	printf("ɾ�������Ԫ��: %d\n", DeleteMax(Heap));
	printf("����������:\n");
	InOrderTraverse_MaxHeap(Heap); 
	
	/*�������*/
	printf("\n\n/*�������*/\n"); 
	Insert(Heap, 66);
	printf("����������:\n");
	InOrderTraverse_MaxHeap(Heap); 
} 
