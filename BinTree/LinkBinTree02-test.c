#include <stdio.h>
#include "LinkBinTree02.c"

void main(){
	
	BinTree T;
	
	/*���Դ���������*/
	printf("����������������0��ʾ��������������\n");
	CreateBinTree(&T);
	/*���Էǵݹ����*/
	printf("���������");
    StackPreOrderTraverse(T); 
    printf("\n���������");
    StackInOrderTraverse(T);
	printf("\n���������");
    StackPostOrderTraverse(T);
	
	printf("\n���ĸ߶ȣ�%d\n",PostOrderGetHeight(T));
	
    if(BinTreeEmpty(T))
        printf("��\n");
    else
    	printf("��Ϊ��\n");
    
	printf("���ĸ���%d\n",Root(T));  
    
}
