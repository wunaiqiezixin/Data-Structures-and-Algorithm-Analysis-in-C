#ifndef _HashSep_H

#define MinTableSize (10)
#include<stdlib.h>
#include<stdio.h>/* NULL */
typedef unsigned int Index;
typedef const char* ElementType;
struct ListNode;
typedef struct ListNode* Position;
struct HashTbl;
typedef struct HashTbl* HashTable;

Index Hash(ElementType Key, HashTable H);
HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P);
void Delete(ElementType Key, HashTable H);
void MakeEmpty(HashTable H);

#endif /* _HashSep_H */