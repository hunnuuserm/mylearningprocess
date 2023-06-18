#include"stack.h"

void StackInit(Stack* pa)
{
	pa->pa = NULL;
	pa->size = 0;
	pa->capacity = 0;
}

void StackDestroy(Stack* pa)
{
	assert(pa->pa);
	free(pa->pa);
	pa->pa = NULL;
	pa->size = 0;
	pa->capacity = 0;
}

void StackPush(Stack* pa, StackDataType x)
{
	/*StackDataType* tmp=NULL;
	if(pa->size ==pa->capacity )
	{
		 tmp  = (StackDataType*)realloc(pa->pa, 2 * pa->capacity * sizeof(StackDataType));
		 assert(tmp != NULL);
		 pa->pa = tmp;
		 pa->pa[pa->size] = x;
		 pa->size += 1;
		 pa->capacity *= 2;
	}
	else
	{
		pa->pa[pa->size] = x;
		pa->size += 1;
	}*/
	if (pa->size == pa->capacity)
	{
		int newcapacity = pa->capacity == 0 ? 2 : 2 * pa->capacity;
		StackDataType* tmp = (StackDataType*)realloc(pa->pa, newcapacity * sizeof(StackDataType));
		assert(tmp != NULL);
		pa->pa = tmp;
		pa->capacity = newcapacity;
	}
		pa->pa[pa->size] = x;
		pa->size += 1;
}

bool StackEmpty(Stack* pa)
{
	if (pa->size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void StackPop(Stack* pa)
{
	assert(!StackEmpty(pa));
	pa->size -= 1;
}


StackDataType StackTop(Stack* pa)
{
	return pa->pa[pa->size - 1];
}

int StackSize(Stack* pa)
{
	return pa->size;
}


void StackPrint(Stack* pa)
{
	int i = 0;
	for (i = 0; i < pa->size; i++)
	{
		printf("%d ", pa->pa[i]);
	}
	printf("\n");
}


