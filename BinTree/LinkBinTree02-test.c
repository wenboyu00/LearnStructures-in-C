#include <stdio.h>
#include "LinkBinTree02.c"

void main(){
	
	BinTree T;
	
	/*测试创建二叉树*/
	printf("创建二叉树，输入0表示空树，先序输入\n");
	CreateBinTree(&T);
	/*测试非递归遍历*/
	printf("先序遍历：");
    StackPreOrderTraverse(T); 
    printf("\n中序遍历：");
    StackInOrderTraverse(T);
	printf("\n后序遍历：");
    StackPostOrderTraverse(T);
	
	printf("\n树的高度：%d\n",PostOrderGetHeight(T));
	
    if(BinTreeEmpty(T))
        printf("空\n");
    else
    	printf("不为空\n");
    
	printf("树的根：%d\n",Root(T));  
    
}
