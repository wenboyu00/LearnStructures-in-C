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
    
}
