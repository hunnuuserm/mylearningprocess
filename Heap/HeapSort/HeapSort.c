#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void AdjustDown(int* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while(child<size)
	{
		if (child+1<size&&a[child] < a [child + 1] )
		{
			child += 1;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int*a,int size)
{
	int parent = (size - 1 - 1) / 2;
	while (parent>=0)
	{
		AdjustDown(a, size, parent);
		parent -= 1;
	}
	int end = size - 1;
	while (end >= 0)
	{
		Swap(&a[0], &a[end]);
		end -= 1;
		AdjustDown(a, end + 1, 0);
	}
}


int main()
{
	int arr[10] = { 3,1,5,7,2,1,3,0,8,7 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}