#include "List.h"

struct Node
{
    ElementType Element;
    Position Next;
};


void FatalError(const char* message)
{
    perror(message);
    exit(EXIT_FAILURE);
}

/* Return true if L is empety */
int 
IsEmpty(List L)
{
    return L->Next == NULL;
}

/* Return true if P is the last position in list L */
/* Parameter L is unused in this implementation */
int 
IsLast(Position P, List L)
{
    return P->Next == NULL;
}

/* Return Positon of X in L; NULL if not found */
Position 
Find(ElementType X, List L)
{
    Position P;

    P = L->Next;
    while (P && P->Element != X)
        P = P->Next;

    return P;
}

/* Delete first occurrence of X from a list */
/* Assume use a header node */
void 
Delete(ElementType X, List L)
{
    Position P, TmpCell;

    P = FindPrevious(X, L);

    if (!IsLast(P, L)) /* Assumption of header use */
    {                  /* X is found; delete it */
        TmpCell = P->Next;
        P->Next = TmpCell->Next; /* Bypass deleted cell */
        free(TmpCell);
    }
}

/* If X is not found, then Next field of returned */
/* Position is NULL */
/* Assumes a header */
Position 
FindPrevious(ElementType X, List L)
{
    Position P;

    P = L;
    while (P->Next && P->Next->Element != X)
        P = P->Next;
    
    return P;
}

/* Insert (after legal position p) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */
void 
Insert(ElementType X, List L, Position P)
{
    Position TmpCell;

    TmpCell = (Position)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
        FatalError("Out of space!!!");
    
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void 
DeleteList(List L)
{
    Position P, TmpCell;

    P = L->Next;
    while (P)
    {
        TmpCell = P;
        P = P->Next;
        free(TmpCell);
    }
    free(L);
}

Position 
header(List L)
{
    return L;
}

Position 
First(List L)
{
    return L->Next;
}

Position 
Advance(Position P)
{
    Position Pre;

    while (Pre->Next != P)
        Pre = Pre->Next;
    
    return Pre;
}

ElementType Retrieve(Position P)
{
    return P->Element;
}

List
MakeEmpty(List L)
{
    Position P, TmpCell;

    P = L->Next;
    while (P)
    {
        TmpCell = P;
        P = P->Next;
        free(TmpCell);
    }

    return L;
}

