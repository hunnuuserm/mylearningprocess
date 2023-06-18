#include"Heap.h"

void HeapPrint(Heap* hp)
{
	assert(hp->a);
	int i = 0;
	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}

void HeapInit(Heap* hp)
{
	hp->a = NULL;
	hp->capacity = 0;
	hp->size = 0;
}

void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->size == hp->capacity == 0;
}

void Swap(HeapDataType* parent, HeapDataType* child)
{
	HeapDataType tmp = *parent;
	*parent = *child;
	*child = tmp;
}

void AdjustUp(HeapDataType* a, int child)
{
	HeapDataType parent = (child - 1) / 2;
	while(a[parent] >a[child])
	{
		Swap(&a[parent], &a[child]);
		child = parent;
		if (child == 0)
		{
			break;
		}
		parent = (child - 1) / 2;;
	}
}



void HeapPush(Heap* hp, HeapDataType x)
{
	if (hp->size == hp->capacity)
	{
		int newcapacity = hp->capacity == 0 ? 4 : 2 * hp->capacity;
		HeapDataType* tmp = (HeapDataType*)realloc(hp->a, sizeof(HeapDataType) * newcapacity);
		assert(tmp);
		hp->a = tmp;
		hp->capacity = newcapacity;
	}
	hp->a[hp->size] = x;
	hp->size++;
	AdjustUp(hp->a, hp->size - 1);
}

void HeapPop(Heap* hp)
{
	assert(hp->a);
	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;

	AdjustDown(hp->a, hp->size,0);
}

//void AdjustDown(HeapDataType* a, int size)
//{
//	//Swap(&a[0], &a[size - 1]);
//	int parent = 0;
//	int child = parent * 2 + 1;
//	while (child<size)
//	{
//		if (child+1<size&&a[child] > a[child + 1])
//		{
//			child += 1;
//		}
//		if (a[parent] > a[child])
//		{
//			Swap(&a[parent], &a[child]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}

void AdjustDown(HeapDataType* a, int size£¬int parent)
{
	int child = parent * 2 + 1;
	while (child<size)
	{
		if (a[child] > a[child + 1])
		{
			child += 1;
		}
		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

HeapDataType HeapTop(Heap* hp)
{
	assert(hp->a);
	assert(hp->size != 0);
	
	return hp->a[0];
}

bool HeapEmpty(Heap* hp)
{
	return hp->size == 0;
}

int HeapSize(Heap* hp)
{
	assert(hp->a);
	return hp->size;
}
