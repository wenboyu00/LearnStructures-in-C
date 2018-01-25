#include <stdio.h>
#include "BST.c"

void main(){
	int i,e,l;
	BinTree tmp;
	/*��ʼ���������,*/
	srand(time(0));
	printf("��������������-��ֵ�������,�����볤��:\n");
	BinTree BST = NULL;		//���������ڵ� 
	scanf("%d",&l);
	/*����+�������*/
	for(i = 1; i <= l; i++){ 
		e = rand() % 100 + 1;		/*�������100���ڵ����ָ�ֵ���ṹ��data*/          
		BST = Insert(e,BST);
	}
	printf("����������:\n");
	InOrderTraverse(BST);
	
	/*�������*/
	printf("\n\n/*�������*/\n"); 
	BST = Insert(55, BST);
	printf("����������:\n");
	InOrderTraverse(BST);
	
	/*ɾ������*/
	printf("\n\n/*ɾ������*/\n");
	BST = Delete(24, BST);
	printf("����������:\n");
	InOrderTraverse(BST);
	
	/*���Ҳ���*/
	printf("\n\n/*���Ҳ���*/\n");
	printf("�ݹ���ң�30����"); 
	tmp = Find(30, BST);
	if(tmp)
		printf("���ҵ���%d\n",tmp->data);
	else
		printf("δ�ҵ�");
	
	printf("\n�ǵݹ���ң�40����"); 
	tmp = Find(30, BST);
	if(tmp)
		printf("���ҵ���%d\n",tmp->data);
	else
		printf("δ�ҵ�"); 

	tmp = FindMax(BST);
	printf("\n�������%d",tmp->data);
	
	tmp = FindMin(BST);
	printf("\n������С��%d",tmp->data);  
}
