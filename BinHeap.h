#pragma once
typedef int ElementType;
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MinPQSize 100


struct HeapStruct;
typedef struct HeapStruct* PriorityQueue;

void error_die(const char* message);
PriorityQueue Initialize(ElementType MaxELements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);
void DecreaseKey(ElementType Position, ElementType theta, PriorityQueue H);
void IncreaseKey(ElementType Position, ElementType theta, PriorityQueue H);
ElementType Delete(int Position, PriorityQueue H);
void BuildHeap(PriorityQueue H);

