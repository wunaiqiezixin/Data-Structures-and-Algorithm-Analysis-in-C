#include "HashSep.h"

static void
FatalError(const char* message)
{
    perror(message);
    exit(EXIT_FAILURE);
}
static int
NextPrime(int num)
{
    //todo: find next prime 
    return num;
}


struct ListNode 
{
    ElementType Element;
    Position Next;
};

typedef Position List;

/* List *TheList will be an array of lists, allocated later */
/* The lists use header (for simplicity), */
/* though this wastes space */
struct HashTbl
{
    int TableSize;
    List *TheLists;
};

/* Hash function */

Index
Hash(ElementType Key, HashTable H)
{   
    unsigned int HashVal = 0;
    while (*Key)
        HashVal = HashVal << 5 + *Key++;
    
    return HashVal % H->TableSize;
}


/* 分离链接法的初始化例程 */
HashTable
InitializeTable(int TableSize)
{
    HashTable H;
    int i;

    if (TableSize < MinTableSize)
    {
        perror("Table size too small");
        return NULL;
    }

    /* Allocate table */
    H = malloc(sizeof(struct HashTbl));
    if (H == NULL)
        FatalError("Out of space!!!");
    
    H->TableSize = NextPrime(TableSize);/* prime */

    /* Allocate array of lists */
    /* List is a pointer */
    H->TheLists = malloc(sizeof(List) * H->TableSize );
    if (H->TheLists == NULL)
        FatalError("Out of space!!!");
    
    /* Allocate list headers */
    for (i = 0; i < H->TableSize; i++)
    {
        H->TheLists[i] = malloc(sizeof(struct ListNode));
        if (H->TheLists[i] == NULL)
            FatalError("Out of space!!!");
        else
            H->TheLists[i]->Next = NULL;
    }

    return H;
}

Position
Find(ElementType Key, HashTable H)
{
    Position P;
    List L; /* dummy header */

    L = H->TheLists[ Hash(Key, H->TableSize) ];
    P = L->Next;
    while (P != NULL && P->Element != Key)
        P = P->Next;
    return P;
}


void
Insert(ElementType Key, HashTable H)
{
    Position Pos, NewCell;
    List L;

    Pos = Find(Key, H);
    if (Pos == NULL) /* Not found */
    {
        NewCell = malloc(sizeof(struct ListNode));
        if (NewCell == NULL)
            FatalError("Out of space!!!");
        else
        {
            L = H->TheLists[ Hash(Key, H->TableSize) ];
            NewCell->Next = L->Next;
            NewCell->Element = Key;
            L->Next = NewCell;
        }
    }
}

void 
Delete(ElementType Key, HashTable H)
{
    List L = H->TheLists[ Hash(Key, H->TableSize) ];

    Position P = L;

    while (P->Next && P->Next->Element != Key)
        P = P->Next;
    if (P == NULL)
        return;
    Position TmpNode = P->Next;
    P->Next = P->Next->Next;
    free(TmpNode);
    return;
}

void 
DestroyTable(HashTable H)
{
    int i;
    Position P;
    List L;

    MakeEmpty(H);

    free(H->TheLists);/* 释放指针数组 */
    free(H);
}

void
MakeEmpty(HashTable H)
{
    List L;
    Position P;
    int i;

    for (i = 0; i < H->TableSize; i++)
    {
        L = H->TheLists[i];
        P = L->Next;

        while (P)
        {
            Position Tmp = P;
            P = P->Next;
            free(Tmp);
        }
        
        L->Next = NULL;
    }

}

ElementType
Retrieve(Position P)
{
    return P->Element;
}