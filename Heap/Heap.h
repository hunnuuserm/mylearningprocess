#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int HeapDataType;

typedef struct Heap
{
	HeapDataType* a;
	int size;
	int capacity;
}Heap;

void HeapPrint(Heap* hp);

void HeapInit(Heap* hp);

void HeapDestroy(Heap* hp);

void HeapPush(Heap* hp, HeapDataType x);

void AdjustUp(HeapDataType* a, int child);

void Swap(HeapDataType* parent, HeapDataType* child);

void HeapPop(Heap* hp);

//void AdjustDown(HeapDataType* a, int size);
void AdjustDown(HeapDataType* a, int size,int parent);

HeapDataType HeapTop(Heap* hp);

bool HeapEmpty(Heap* hp);

int HeapSize(Heap* hp);
