#include"sort.h"


void Test()
{
	srand(time(0));
	const int N = 1000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	assert(a1);
	assert(a2);
	assert(a3);
	assert(a4);
	assert(a5);
	assert(a6);
	assert(a7);
	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}

	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	int begin1 = clock();
	ShellSort(a1, N);
	int end1 = clock();
	//printArr(a1, sizeof(a1) / sizeof(a1[0]));
	printf("ShellSort:%d\n", end1-begin1);
	free(a1);


	//int begin2 = clock();
	//InsertSort(a2, N);
	//int end2 = clock();
	////printArr(a2, sizeof(a2) / sizeof(a2[0]));
	//printf("InsertSort:%d\n", end2 - begin2);
	//free(a2);

	int begin3 = clock();
	HeapSort(a3, N);
	int end3 = clock();
	//printArr(a2, sizeof(a2) / sizeof(a2[0]));
	printf("HeapSort:%d\n", end3 - begin3);
	free(a3);

	//int begin4 = clock();
	//BubbleSort(a4, N);
	//int end4 = clock();
	////printArr(a2, sizeof(a2) / sizeof(a2[0]));
	//printf("BubbleSort:%d\n", end4 - begin4);
	//free(a4);
	
	int begin5 = clock();
	QuickSort1(a5, 0, N - 1);
	int end5 = clock();
	//printArr(a2, sizeof(a2) / sizeof(a2[0]));
	printf("QuickSort1:%d\n", end5 - begin5);
	free(a5);

	int begin6 = clock();
	QuickSort2(a6, 0, N - 1);
	int end6 = clock();
	//printArr(a2, sizeof(a2) / sizeof(a2[0]));
	printf("QuickSort2:%d\n", end6 - begin6);
	//free(a6);

	int begin7 = clock();
	QuickSort3(a7, 0, N - 1);
	int end7 = clock();
	//printArr(a2, sizeof(a2) / sizeof(a2[0]));
	printf("QuickSort3:%d\n", end7 - begin7);
	//free(a7);
}

int main()
{

	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	//int begin1 = clock();
	//ShellSort(a1, sizeof(a1) / sizeof(a1[0]));
	//int end1 = clock();
	//printArr(a1, sizeof(a1) / sizeof(a1[0]));
	//printf("ShellSort:%d\n", begin1 - end1);

	//
	//int begin2 = clock();
	//InsertSort(a2, sizeof(a2) / sizeof(a2[0]));
	//int end2 = clock();
	////printArr(a2, sizeof(a2) / sizeof(a2[0]));
	//printf("InsertSort:%d\n", begin2 - end2);
	//Test();
	//int arr[] = { 4,3,6,8,1,1,0,9,3,8 };
	////HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	////InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	////ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
	//for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	int arr[] = { 4,3,6,8,1,1,0,9,3,8 };
	int arr2[] = { 9,8,7,6,5,4,3,2,1 };
	int arr3[] = { 6,1,2,7,9,3,4,5,10,8 };
	int arr4[] = { 6,1,2,7,9,3,4,5,10,8 };
	int arr5[] = { 6,1,2,7,9,3,4,5,10,8 };
	int arr6[] = { 6,1,2,7,9,3,4,5,10,8 };
	int arr7[] = { 6,1,2,7,9,3,4,5,10,8 };
	int arr8[] = { 4,3,6,8,1,1,0,9,3,8 };
	//SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	//SelectSort(arr2, sizeof(arr2) / sizeof(arr2[0]));
	//BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	//BubbleSort(arr2, sizeof(arr2) / sizeof(arr2[0]));
	//Test();
	/*QuickSort1(arr3, 0, sizeof(arr3) / sizeof(arr3[0]) - 1);
	QuickSort2(arr4, 0, sizeof(arr4) / sizeof(arr4[0]) - 1);
	QuickSort3(arr5, 0, sizeof(arr5) / sizeof(arr5[0]) - 1);*/
	/*newQuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	newQuickSort(arr2, 0, sizeof(arr2) / sizeof(arr2[0]) - 1);
	newQuickSort(arr3, 0, sizeof(arr3) / sizeof(arr3[0]) - 1);
	newQuickSortNonRecursive(arr4, 0, sizeof(arr4) / sizeof(arr4[0]) - 1);
	newQuickSortNonRecursive(arr5, 0, sizeof(arr5) / sizeof(arr5[0]) - 1);*/
	//mergeSort(arr6, sizeof(arr6) / sizeof(arr6[0]));
	//mergeSort(arr, sizeof(arr) / sizeof(arr[0]));
	/*mergeSortNonRecursive1(arr7, sizeof(arr7) / sizeof(arr7[0]));
	mergeSortNonRecursive1(arr8, sizeof(arr8) / sizeof(arr8[0]));*/

	mergeSortNonRecursive2(arr7, sizeof(arr7) / sizeof(arr7[0]));
	mergeSortNonRecursive2(arr8, sizeof(arr8) / sizeof(arr8[0]));
	return 0;
}