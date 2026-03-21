#include"LeftHeap.h"

struct TreeNode
{
	ElementType Element;
	PriorityQueue Left;
	PriorityQueue Right;
	ElementType		Npl; /* Null Path Length */
};

PriorityQueue
Initialize(void)
{
	PriorityQueue H = malloc(sizeof(struct TreeNode));
	if (H == NULL)
	{
		perror("Out of space!!!");
		return H;
	}
	
	H->Left = H->Right = NULL;
	H->Npl = 0;
	H->Element = INT_MIN;/* Initialized with minimum element */

	return H;
}

int 
IsEmpty(PriorityQueue H)
{
	return H == NULL;
}

ElementType
FindMin(PriorityQueue H)
{
	return H->Element;
}

static void
SwapChild(PriorityQueue H)
{
	struct TreeNode* tmp = H->Left;
	H->Left = H->Right;
	H->Right = tmp;
}

PriorityQueue
Merge(PriorityQueue H1, PriorityQueue H2)
{
	if (H1 == NULL)
		return H2;
	if (H2 == NULL)
		return H1;
	if (H1->Element < H2->Element)
		return Merge1(H1, H2);
	else
		return Merge1(H2, H1);
}
static PriorityQueue
Merge1(PriorityQueue H1, PriorityQueue H2)
{
	if (H1->Left == NULL) /* Single node */
		H1->Left = H2;	  /* H->Right is already NULL
							 H1->Npl is already 0 */
	else
	{
		H1->Right = Merge(H1->Right, H2);
		if (H1->Left->Npl < H1->Right->Npl)
			SwapChild(H1);

		H1->Npl = H1->Right->Npl + 1;
	}
	return H1;
}

PriorityQueue
Insert1(ElementType X, PriorityQueue H)
{
	PriorityQueue SingleNode;

	SingleNode = malloc(sizeof(struct TreeNode));
	if (SingleNode == NULL)
		perror("Out of space!!!");
	else
	{
		SingleNode->Element = X;
		SingleNode->Left = SingleNode->Right = NULL;
		SingleNode->Npl = 0;

		H = Merge(H, SingleNode);
	}
	return H;
}

/* DleteMin1 return the new tree */
/* To get the minimum, use FindMin */
/* this is for convenience */

PriorityQueue
DeleteMin1(PriorityQueue H)
{
	PriorityQueue LeftHeap, RightHeap;

	if (IsEmpty(H))
	{
		perror("Priority queue is empty");
		return H;
	}
	
	LeftHeap = H->Left;
	RightHeap = H->Right;
	free(H);
	return Merge(LeftHeap, RightHeap);
}