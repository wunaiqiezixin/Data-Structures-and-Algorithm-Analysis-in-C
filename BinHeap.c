#include"BinHeap.h"

//Print an error message and exits the program 
//with failure status 
void error_die(const char* message)
{
	perror(message);
	exit(EXIT_FAILURE);
}


struct HeapStruct
{
	int Capacity;
	int Size;
	ElementType* Elements;
};

PriorityQueue
Initialize(ElementType MaxElements)
{
	PriorityQueue H;

	if (MaxElements < MinPQSize)
		error_die("Priority queue size is too small");

	H = malloc(sizeof(struct HeapStruct));
	if (H == NULL)
		error_die("Out of space!!!");

	/*Allocate the array plus one extra for sentinel*/
	H->Elements = malloc((MaxElements + 1) * sizeof(ElementType));
	if (H->Elements == NULL)
		error_die("Out of space!!!");

	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = INT_MIN;
	
	return H;
}

void
Destroy(PriorityQueue H)
{
	MakeEmpty(H);
	free(H->Elements);
	free(H);
}

void
MakeEmpty(PriorityQueue H)
{
	H->Size = 0;
}

ElementType
FindMin(PriorityQueue H)
{
	if (IsEmpty(H))
	{
		perror("priority queue is empty");
		return -1;
	}
	return H->Elements[1];
}

int
IsEmpty(PriorityQueue H)
{
	if (H == NULL || H->Size == 0 || H->Elements == NULL)
		return 1;
	return 0;
}

int
IsFull(PriorityQueue H)
{
	if (H->Size == H->Capacity)
		return 1;
	return 0;
}

void 
Insert(ElementType X, PriorityQueue H)
{
	/* H->Elements[0] is a sentinel */
	if (IsFull(H))
	{
		perror("Priority queue is full");
		return;
	}
	//Percolate up
	int i;

	for (i = ++H->Size; X < H->Elements[i / 2];
		i /= 2)
		H->Elements[i] = H->Elements[i / 2];
	H->Elements[i] = X;
}

ElementType
DeleteMin(PriorityQueue H)
{
	int i, child;
	ElementType MinElement, LastElement;

	if (IsEmpty(H))
	{
		perror("priority queue is empty");
		return INT_MAX;
	}
	MinElement = FindMin(H);
	LastElement = H->Elements[H->Size--];
	//Percolate down
	for (i = 1; i * 2 <= H->Size; i = child)
	{
		/* Find smaller child */
		child = 2 * i;
		if (child != H->Size && H->Elements[child + 1] < 
			H->Elements[child])
			child++;

		/* percolate one level */
		if (LastElement > H->Elements[child])
			H->Elements[i] = H->Elements[child];
		else
			break;
	}
	H->Elements[i] = LastElement;
	return MinElement;
}

//降低关键字的值
void
DecreaseKey(ElementType Position, ElementType theta, PriorityQueue H)
{
	ElementType decreased = H->Elements[Position] - theta;
	//Percolate up
	int i;
	for (i = Position; decreased < H->Elements[i / 2]; i /= 2)
		H->Elements[i] = H->Elements[i / 2];
	H->Elements[i] = decreased;
}

//增加关键字的值
void 
IncreaseKey(ElementType Position, ElementType theta, PriorityQueue H)
{
	ElementType increased = H->Elements[Position] + theta;
	
	//Percolate down
	int i, child;
	for (i = Position; i <= H->Size; i = child)
	{
		/* Find smaller child */
		child = i * 2;
		if (child != H->Size && H->Elements[child] >
			H->Elements[child + 1])
			child++;

		/* percolate one level */
		if (increased > H->Elements[child])
			H->Elements[i] = H->Elements[child];
		else
			break;
	}
	H->Elements[i] = increased;
}

ElementType
Delete(int Position, PriorityQueue H)
{
	ElementType key = H->Elements[Position];
	DecreaseKey(Position, INT_MAX, H);
	DeleteMin(H);
	return key;
}

void
BuildHeap(PriorityQueue H)
{
	ElementType i, child;

	for (ElementType k = H->Size; k > 0; k--)
	{
		// Percolate down
		for (i = k; i * 2 <= H->Size; i = child)
		{
			/* find smaller child */
			child = 2 * i;
			if (child != H->Size && H->Elements[child] >
				H->Elements[child + 1])
				child++;

			if (H->Elements[k] > H->Elements[child])
				H->Elements[i] = H->Elements[child];
			else
				break;
		}
		H->Elements[i] = H->Elements[k];
	}
}