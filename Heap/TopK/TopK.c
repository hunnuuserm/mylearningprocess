//#include"BinaryTree.h"

//BTNode* CreatBinaryTree()
//{
//	BTNode* node1 = BuyNode(1);
//	BTNode* node2 = BuyNode(2);
//	BTNode* node3 = BuyNode(3);
//	BTNode* node4 = BuyNode(4);
//	BTNode* node5 = BuyNode(5);
//	BTNode* node6 = BuyNode(6);
//
//	node1->left = node2;
//	node1->right = node4;
//	node2->left = node3;
//	node4->left = node5;
//	node4->right = node6;
//	return node1;
//}

//int main()
//{
//	BTNode* node1 = BuyNode(1);
//	BTNode* node2 = BuyNode(2);
//	BTNode* node3 = BuyNode(3);
//	BTNode* node4 = BuyNode(4);
//	BTNode* node5 = BuyNode(5);
//	BTNode* node6 = BuyNode(6);
//
//	node1->left = node2;
//	node1->right = node4;
//	node2->left = node3;
//	node4->left = node5;
//	node4->right = node6;
//
//
//	return 0;
//}

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

void AdjustDown(int*a,int size,int parent)
{
	int child = (parent * 2) + 1;
	while (child<size)
	{
		if (child + 1 < size && a[child] > a[child + 1])
		{
			child += 1;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = (parent * 2) + 1;
		}
		else
		{
			break;
		}
	}
}

void PrintTopK(int* a,int n,int k)
{
	// 1. 建堆--用a中前k个元素建堆
	int parent = (k - 1 - 1) / 2;
	while (parent >= 0)
	{
		AdjustDown(a, k, parent);
		parent -= 1;
	}

	// 2. 将剩余n-k个元素依次与堆顶元素交换，不满则则替换
	int cur = 0;
	for (cur = k; cur < n; cur++)
	{
		if (a[cur] > a[0])
		{
			Swap(&a[cur], &a[0]);
			AdjustDown(a, k, 0);
		}
	}

	int end = k - 1;
	while (end >= 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end -= 1;
	}


	for (int i = 0; i < k; i++)
	{
		printf("%d ", a[i]);
	}
}



void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK(a, n, 10);
}


int main()
{
	TestTopk();
	return 0;
}