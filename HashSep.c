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
    //todo: find an minmum prime 
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