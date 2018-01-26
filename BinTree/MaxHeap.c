#ifndef MAXHEAP_C
#define MAXHEAP_C

#include "MaxHeap.h"

#define MaxData 100  /* 该值应根据具体情况定义为大于堆中所有可能元素的值 */ 

/*创建容量为MaxSize的空的最大堆*/
MaxHeap CreateHeap( int MaxSize){
	
	MaxHeap H = malloc(sizeof(struct HeapStruct));
	/*H->Elements指向一个数组，因此给数组申请空间
	堆大小是 MaxSize + 1，0放置哨兵*/
	H->Elements = malloc((MaxSize + 1) * sizeof(ElemType));
	H->Size = 0;				//当前容量 
	H->Capacity = MaxSize;		//最大容量 
	H->Elements[0] = MaxData;	
	/* 定义“哨兵”为大于堆中所有可能元素的值，便于以后更快操作
	插入时，哨兵作为边界值使插入值为当前堆时最大时，
	限制使其不能超过数组下标范围和减少每次循环比较*/ 
	
	return H; 
}

/*是否已满*/
Status IsFull(MaxHeap H){
	return (H->Size == H->Capacity);
} 

/*将元素X插入最大堆 H，其中 H->Elements[0] 已经定义为哨兵*/
void Insert( MaxHeap H , ElemType X){
	
	if (IsFull(H)){
		printf("最大堆已满");
		return ;
	}
	/* H->Size是当前堆中最后一个位置，++向后移一位就是i要插入的位置 
	相当于 H->size += 1; i = H->Size*/
	int i = ++H->Size;		/*i指向插入后堆中追个元素的位置*/ 
	/* 
	i/2 是 i的父节点位置
	子节点和父结点进行比较，发现不符合最大特性，就对换位置，循环直到符合
	H->Elements[i/2] < X，父节点小于插入值
	->交换位置 H->Elements[i] = H->Elements[i/2],i到父节点位置 i /= 2 
	*/
	for( ;H->Elements[i/2] < X ; i /= 2){
		H->Elements[i] = H->Elements[i/2];	//向下过滤结点 
	}
	H->Elements[i] = X;						//将item插入 
}

/*是否为空*/ 
Status IsEmpty(MaxHeap H){
	return (H->Size == 0);
}

/*从最大堆H中取出键值为最大的元素，并删除这个结点*/
/*删除最大值，然后拿最后一个值依次 “跟结点”最大孩子对比 交换位置存放*/
ElemType DeleteMax( MaxHeap H){
	int Parent , Child;
	ElemType MaxItem, temp;
	if ( IsEmpty(H)){
		printf("最大堆已为空");
		return;
	}
	MaxItem = H->Elements[1];		/*取出结点存放的最大值*/
	/* 用最大堆中最后一个元素从根结点开始向上过滤下层结点*/
	temp = H->Elements[H->Size--]; 
	for( Parent = 1; Parent * 2 <= H->Size; Parent = Child){
		Child = Parent * 2;
		if (( Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1])) 
			Child++;	/*child指向左右子结点的较大着*/
		if( temp >= H->Elements[Child])
			break;		/*找到了合适位置*/
		else	/*移动temp元素到下一层*/ 
			H->Elements[Parent] = H->Elements[Child];
	} 
	H->Elements[Parent] = temp;
	
	return MaxItem;
}


/*下虑：将H中以H->Elements[p]为根的子堆调整为最大堆*/
void PercDown(MaxHeap H ,int p){
	int Parent, Child;
	ElemType temp;
	
	temp = H->Elements[p];	/*取出跟结点存放的值*/
	for ( Parent = p ; Parent * 2 <= H->Size; Parent = Child){
		Child = Parent * 2;
		if (( Child != H->Size) && (H->Elements[Child] < H->Elements[Child+1])){
			Child++;		/*Child指向左右子树结点最大的*/
		}
		if( temp > H->Elements[Child])
			break;			/*找到合适位置*/
		else 	/*移动temp元素到下一层*/
			H->Elements[Parent] = H->Elements[Child]; 
	} 
	H->Elements[Parent] = temp;
}

/*建立最大堆*/
/*调整 H->Elements[] 中的元素，使满足最大堆的有序性*/
/*这里假设所有H->Size个元素已经存在 H->Elements[]中*/
void BuildHeap(MaxHeap H){
	/*从最后一个结点的父节点开始，到跟结点1*/
	int i = i = H->Size/2;
	for(;i > 0 ; i--)
		PercDown(H, i); 
} 

/*中序遍历*/
void InOrderTraverse_MaxHeap(MaxHeap H){
	if(H){
		int i;
		for(i = 1; i<= H->Size; i++)
			printf("%d\t",H->Elements[i]);
	}
}
 
#endif


