#include <stdio.h>
#include "LinkStack01.c"

void main(){
		Stack S;
		int i;
		/*���Դ���ջ*/ 
		S = CreateStack();
		
		/*�����Ƿ�Ϊ��*/ 
		IsEmpty(S); 
	
		/*������ջ*/
		for(i=1 ; i<5 ; i++){
			printf("push=%d\n", i);
			Push(S, i);
		}
		/*���Գ�ջ*/
		for(i=1 ; i<5 ; i++)
			printf("pop=%d\n", Pop(S));
			
}
