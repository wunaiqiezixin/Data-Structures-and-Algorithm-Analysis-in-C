#ifndef _HashSep_H

#define MinTableSize (10)
#include<stdlib.h>
#include<stdio.h>/* NULL */

typedef int ElementType;
struct ListNode;
typedef struct ListNode* Position;
struct HashTbl;
typedef struct HashTbl* HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P);
void Dlete(ElementType Key, HashTable H);
void MakeEmpty(HashTable H);

#endif /* _HashSep_H */