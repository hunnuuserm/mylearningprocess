#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"



void CheckCapacity(SL* pSL)
{
	if (pSL->sz == pSL->capacity)
	{
		SeqlistDatatype* tmp = (SeqlistDatatype*)realloc(pSL->p, 2 * sizeof(SeqlistDatatype) * pSL->sz);
		if (tmp != NULL)
		{
			pSL->p = tmp;
			pSL->capacity *= 2;
		}
		else
		{
			return;
		}
	}
}


void SeqListInit(SL* pSL)
{
	pSL->p = (SeqlistDatatype*)malloc(4 * sizeof(SeqlistDatatype));
	pSL->sz = 0;
	pSL->capacity = 3;
}

void SeqListDestroy(SL* pSL)
{
	free(pSL->p);
	pSL->p = NULL;
}

void SeqListPrint(SL* pSL)
{
	int i = 0;
	for (i = 0; i <= pSL->sz - 1; i++)
	{
		printf("%d ",pSL->p [i]);
	}
}

int SeqListFind(SL* pSL, SeqlistDatatype x)
{
	int i = 0;
	for (i = 0; i < pSL->sz; i++)
	{
		if (pSL->p[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListPushBack(SL* pSL, SeqlistDatatype x)
{
	if (pSL->sz == pSL->capacity)
	{
		SeqlistDatatype* tmp = (SeqlistDatatype*)realloc(pSL->p , 2 * sizeof(SeqlistDatatype) * pSL->sz);
		if (tmp != NULL)
		{
			pSL->p = tmp;
			pSL->capacity *= 2;
		}
		else
		{
			return;
		}
	}
	pSL->p[pSL->sz] = x;
	pSL->sz++;
}

void SeqListPopBack(SL* pSL)
{
	assert(pSL->sz > 0);
	pSL->sz--;
}

void SeqListPushFront(SL* pSL, SeqlistDatatype x)
{
	if (pSL->sz == pSL->capacity)
	{
		SeqlistDatatype* tmp = NULL;
		tmp = (SeqlistDatatype*)realloc(pSL->p , 2 * pSL->capacity *sizeof(SeqlistDatatype));
		if (tmp != NULL)
		{
			pSL->p = tmp;
			pSL->capacity *= 2;
		}
		else
		{
			return;
		}
	}
	int end = pSL->sz - 1;
	while (end >= 0)
	{
		pSL->p[end+1] = pSL->p[end];
		end--;
	}
	pSL->p[0] = x;
	pSL->sz++;
}

void SeqListPopFront(SL* pSL)
{
	int begin = 0;
	for (begin = 0; begin < pSL->sz - 1; begin++)
	{
		pSL->p[begin] = pSL->p[begin + 1];
	}
	pSL->sz--;
}



void SeqListInert(SL* pSL, int pos, SeqlistDatatype x)
{
	CheckCapacity(pSL);
	int end = pSL->sz  - 1;
	int i = 0;
	while (end >= pos)
	{
		pSL->p[end + 1] = pSL->p[end];
		end--;
	}
	pSL->p[pos] = x;
	pSL->sz++;
}


void SeqListDele(SL* pSL, SeqlistDatatype x)
{
	int ret = SeqListFind(pSL, x);
	if (ret != -1)
	{
		int begin = ret;
		while (begin < pSL->sz - 1)
		{
			pSL->p[begin] = pSL->p[begin + 1];
			begin++;
		}
		pSL->sz--;
	}
}