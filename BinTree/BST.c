#ifndef BST_C
#define BST_C

#include "BST.H"


/*�ݹ����*/ 
BinTree Find(TElemType X, BinTree BST){
	if(!BST)
		return NULL;		//����ʧ�� 
	if(X < BST->data)
		return Find(X, BST->lchild);		//���������м������� 
	else if (X > BST->data)
		return Find(X, BST->rchild);		//���������м������� 
	else	//X == BST->data;
		return BST;				//���ҳɹ������ؽ����ҵ����ĵ�ַ 
	} 

/*�ǵݹ����*/
BinTree IterFind(TElemType X, BinTree BST){
	while(BST){
		if(X > BST->data)
			BST = BST->rchild;			//���������ƶ�����������
		else if(X < BST->data)
			BST = BST->lchild;			//���������ƶ�����������
		else
			return BST;			//���ҳɹ������ؽ����ҵ����ĵ�ַ  				 
	}
	return NULL;		//����ʧ�� 
}

/*������С-�ݹ�*/
BinTree FindMin(BinTree BST){
	if(!BST) return NULL;		//�ն�����������NULL 
	else if (!BST->lchild)
		return BST;				//�ҵ������㲢���� 
	else
		return FindMin(BST->lchild); 	//�����֧�������� 
} 

/*�������-����*/
BinTree FindMax(BinTree BST){
	if(BST)
		while(BST->rchild)
			BST = BST->rchild;
		
	return BST; 
}

/*����*/
/*
�ؼ����ҵ�Ԫ��Ӧ�ò����λ�ã����Բ�����find���͵ķ��� 
*/ 
BinTree Insert(TElemType X , BinTree BST){
	
	if(!BST){
		printf("����Ԫ��%d\n",X); 
		BST = (BinTree)malloc(sizeof(BinTNode));
		if(!BST)
			exit(OVERFLOW);
		BST->data = X;
		BST->lchild = BST->rchild = NULL;
	}	//��ʼ��Ҫ����Ԫ�ص�λ�� 
	if (X < BST->data)
		BST->lchild = Insert(X, BST->lchild);		//�ݹ�������
		 
	else if (X > BST->data)
		BST->rchild = Insert(X, BST->rchild); 		//�ݹ�������
	//else x �Ѿ����ڣ�ʲô������ 

	return BST;
}

/*ɾ��*/
/*
�������������
	Ҫɾ������Ҷ�ڵ㣺ֱ��ɾ���������޸��丸�ڵ�ָ�롪����ΪNULL
	Ҫɾ���Ľڵ�ֻ��һ�����ӵĽڵ㣺
		���丸�ڵ��ָ��ָ��Ҫɾ���ڵ�ĺ��ӽڵ�
	Ҫɾ���Ľڵ�����������������
		����һ���ڵ������ɾ���ڵ㣺����������СԪ�ػ������������Ԫ��
*/
BinTree Delete(TElemType X , BinTree BST){
	BinTree tmp;
	if(!BST)
		printf("Ҫɾ��������: %d δ�ҵ�\n",X);
	else if (X < BST->data)
		BST->lchild = Delete(X, BST->lchild);
	else if (X > BST->data)
		BST->rchild = Delete(X, BST->rchild);
	else	//�ҵ�Ҫɾ���Ľ��
		if(BST->lchild && BST->rchild){
			tmp = FindMin(BST->rchild);			//�ҵ���������С��Ԫ�����ɾ�����
			
			BST->data = tmp->data;				//����������ֵ��ֵ������㣬Ȼ���ٰѸ�������ɾ���� 
			BST->rchild = Delete(BST->data,BST->rchild);	// ��ɾ��������������ɾ����СԪ�� 
		}else{	//��ɾ�������һ�������ӽ�� 
			tmp = BST;
			if(!BST->lchild)			//�����ǿյĻ������Һ��ӵ�ַ���أ��ݹ������¸����ָ������ 
				BST = BST->rchild;
			else if (!BST->rchild)		//����Һ����ǿգ������ӵ�ַ���� 
				BST = BST->lchild;
			//������ҽ�㶼Ϊ��ʱ��BST = BST->rchild(null) BST�͵�null�������ִ��NULl 
			free(tmp);
			printf("ɾ������: %d\n",X); 
		}
	return BST;
}


/*������������ڴ�ӡ������ݣ��鿴���Խ������Ϊ��������ԭ�����������С����*/
BinTree InOrderTraverse(BinTree T){
	if(T){
		InOrderTraverse(T->lchild);
		printf("%d\t", T->data);
		InOrderTraverse(T->rchild);
	}

} 
#endif
