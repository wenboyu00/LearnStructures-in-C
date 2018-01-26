#ifndef MAXHEAP_C
#define MAXHEAP_C

#include "MaxHeap.h"

#define MaxData 100  /* ��ֵӦ���ݾ����������Ϊ���ڶ������п���Ԫ�ص�ֵ */ 

/*��������ΪMaxSize�Ŀյ�����*/
MaxHeap CreateHeap( int MaxSize){
	
	MaxHeap H = malloc(sizeof(struct HeapStruct));
	/*H->Elementsָ��һ�����飬��˸���������ռ�
	�Ѵ�С�� MaxSize + 1��0�����ڱ�*/
	H->Elements = malloc((MaxSize + 1) * sizeof(ElemType));
	H->Size = 0;				//��ǰ���� 
	H->Capacity = MaxSize;		//������� 
	H->Elements[0] = MaxData;	
	/* ���塰�ڱ���Ϊ���ڶ������п���Ԫ�ص�ֵ�������Ժ�������
	����ʱ���ڱ���Ϊ�߽�ֵʹ����ֵΪ��ǰ��ʱ���ʱ��
	����ʹ�䲻�ܳ��������±귶Χ�ͼ���ÿ��ѭ���Ƚ�*/ 
	
	return H; 
}

/*�Ƿ�����*/
Status IsFull(MaxHeap H){
	return (H->Size == H->Capacity);
} 

/*��Ԫ��X�������� H������ H->Elements[0] �Ѿ�����Ϊ�ڱ�*/
void Insert( MaxHeap H , ElemType X){
	
	if (IsFull(H)){
		printf("��������");
		return ;
	}
	/* H->Size�ǵ�ǰ�������һ��λ�ã�++�����һλ����iҪ�����λ�� 
	�൱�� H->size += 1; i = H->Size*/
	int i = ++H->Size;		/*iָ���������׷��Ԫ�ص�λ��*/ 
	/* 
	i/2 �� i�ĸ��ڵ�λ��
	�ӽڵ�͸������бȽϣ����ֲ�����������ԣ��ͶԻ�λ�ã�ѭ��ֱ������
	H->Elements[i/2] < X�����ڵ�С�ڲ���ֵ
	->����λ�� H->Elements[i] = H->Elements[i/2],i�����ڵ�λ�� i /= 2 
	*/
	for( ;H->Elements[i/2] < X ; i /= 2){
		H->Elements[i] = H->Elements[i/2];	//���¹��˽�� 
	}
	H->Elements[i] = X;						//��item���� 
}

/*�Ƿ�Ϊ��*/ 
Status IsEmpty(MaxHeap H){
	return (H->Size == 0);
}

/*������H��ȡ����ֵΪ����Ԫ�أ���ɾ��������*/
/*ɾ�����ֵ��Ȼ�������һ��ֵ���� ������㡱����ӶԱ� ����λ�ô��*/
ElemType DeleteMax( MaxHeap H){
	int Parent , Child;
	ElemType MaxItem, temp;
	if ( IsEmpty(H)){
		printf("������Ϊ��");
		return;
	}
	MaxItem = H->Elements[1];		/*ȡ������ŵ����ֵ*/
	/* �����������һ��Ԫ�شӸ���㿪ʼ���Ϲ����²���*/
	temp = H->Elements[H->Size--]; 
	for( Parent = 1; Parent * 2 <= H->Size; Parent = Child){
		Child = Parent * 2;
		if (( Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1])) 
			Child++;	/*childָ�������ӽ��Ľϴ���*/
		if( temp >= H->Elements[Child])
			break;		/*�ҵ��˺���λ��*/
		else	/*�ƶ�tempԪ�ص���һ��*/ 
			H->Elements[Parent] = H->Elements[Child];
	} 
	H->Elements[Parent] = temp;
	
	return MaxItem;
}


/*���ǣ���H����H->Elements[p]Ϊ�����Ӷѵ���Ϊ����*/
void PercDown(MaxHeap H ,int p){
	int Parent, Child;
	ElemType temp;
	
	temp = H->Elements[p];	/*ȡ��������ŵ�ֵ*/
	for ( Parent = p ; Parent * 2 <= H->Size; Parent = Child){
		Child = Parent * 2;
		if (( Child != H->Size) && (H->Elements[Child] < H->Elements[Child+1])){
			Child++;		/*Childָ�����������������*/
		}
		if( temp > H->Elements[Child])
			break;			/*�ҵ�����λ��*/
		else 	/*�ƶ�tempԪ�ص���һ��*/
			H->Elements[Parent] = H->Elements[Child]; 
	} 
	H->Elements[Parent] = temp;
}

/*��������*/
/*���� H->Elements[] �е�Ԫ�أ�ʹ�������ѵ�������*/
/*�����������H->Size��Ԫ���Ѿ����� H->Elements[]��*/
void BuildHeap(MaxHeap H){
	/*�����һ�����ĸ��ڵ㿪ʼ���������1*/
	int i = i = H->Size/2;
	for(;i > 0 ; i--)
		PercDown(H, i); 
} 

/*�������*/
void InOrderTraverse_MaxHeap(MaxHeap H){
	if(H){
		int i;
		for(i = 1; i<= H->Size; i++)
			printf("%d\t",H->Elements[i]);
	}
}
 
#endif


