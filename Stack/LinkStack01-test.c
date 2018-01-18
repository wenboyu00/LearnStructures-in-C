#include <stdio.h>
#include "LinkStack01.c"

void main(){
		Stack S;
		int i;
		/*测试创建栈*/ 
		S = CreateStack();
		
		/*测试是否为空*/ 
		IsEmpty(S); 
	
		/*测试入栈*/
		for(i=1 ; i<5 ; i++){
			printf("push=%d\n", i);
			Push(S, i);
		}
		/*测试出栈*/
		for(i=1 ; i<5 ; i++)
			printf("pop=%d\n", Pop(S));
			
}
