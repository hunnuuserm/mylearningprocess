#include"Heap.h"




//void HeapSort(int* a, int n)
//{
//	//Heap hp;
//	//HeapInit(&hp);
//	//int i = 0;
//	//for (i = 0; i < n; i++)
//	//{
//	//	HeapPush(&hp, a[i]);
//	//}
//	//i = 0;
//	//while (!HeapEmpty(&hp))
//	//{
//	//	a[i++] = HeapTop(&hp);
//	//	HeapPop(&hp);
//	//}
//	//printf("\n");
//
//	//HeapDestroy(&hp);
//}

void HeapSort(int* arr, int size)
{
	
	/*int i = 0;
	for (i = 1; i < size; i++)
	{
		AdjustUp(arr, i);
	}*/
	int child = size - 1;
	int parent= 0;
	for (parent = (child - 1) / 2; parent >= 0; parent--)
	{
		AdjustDown(arr, size, parent);
	}
}

int main()
{
	Heap hp;
	HeapInit(&hp);
	HeapPush(&hp, 27);
	HeapPush(&hp, 15);
	HeapPush(&hp, 19);
	HeapPush(&hp, 18);
	HeapPush(&hp, 28);
	HeapPush(&hp, 34);
	HeapPush(&hp, 65);
	HeapPush(&hp, 49);
	HeapPush(&hp, 25);
	HeapPush(&hp, 37);
	HeapPush(&hp, 10);
	HeapPrint(&hp);
	
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);

	HeapDestroy(&hp);
	printf("---------------\n");

	/*int arr[] = { 27,15,19,18,28,34,65,49,25,37,10 };
	///*HeapSort(arr, sizeof(arr) / sizeof(arr[0]));*/


	//HeapSort(arr, sizeof(arr) / sizeof(arr[0]));*/
	
	return 0;
}