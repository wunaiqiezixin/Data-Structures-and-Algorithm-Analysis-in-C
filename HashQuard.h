#ifndef _HashQuard_H
typedef int ElementType;

#include<stdio.h>
#include<stdlib.h>

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl* HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P, HashTable H);
HashTable reHash(HashTable H);
void Delete(ElementType Key, HashTable H);
void MakeEmpty(HashTable H);

#endif /* _HashQuard_H */