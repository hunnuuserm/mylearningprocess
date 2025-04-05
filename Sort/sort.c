#include"sort.h"

Stack* createStack() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	assert(stack);
	stack->top = -1;
	return stack;
}

void push(Stack* stack, int value) {
	if (stack->top == MAX_SIZE - 1) {
		printf("Stack is full. Cannot push element.\n");
		return;
	}
	stack->data[++(stack->top)] = value;
}

int pop(Stack* stack) {
	if (stack->top == -1) {
		printf("Stack is empty. Cannot pop element.\n");
		return -1;
	}
	return stack->data[(stack->top)--];
}

int peek(Stack* stack) {
	if (stack->top == -1) {
		printf("Stack is empty. No top element.\n");
		return -1;
	}
	return stack->data[stack->top];
}

bool isEmpty(Stack* stack) {
	return stack->top == -1;
}

void destroyStack(Stack* stack) {
	free(stack);
}

void printArr(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)
{
	//int end = 0;
	//int start = 1;
	//int cur = end;
	//int cur2 = start;
	//int value = a[start];
	//while (start < n)
	//{
	//	while (a[cur] > a[start] && cur > -1)
	//	{
	//		cur--;
	//	}
	//	while (cur2 > cur && cur2 > 0 && cur != end)
	//	{
	//		a[cur2] = a[cur2 - 1];
	//		cur2--;
	//	}
	//	a[cur + 1] = value;
	//	start++;
	//	end++;
	//	cur = end;
	//	cur2 = start;
	//	value = a[start];
	//}
	int i = 0;
	for(i=0;i<n-1;i++)
	{

		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}


void ShellSort(int* a, int n)
{
	int end;
	int gap = n;
	int tmp;
	int i = 0;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (i = 0; i < n - gap; i++)
		{
			end = i;
			tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void AdjustDown(int* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child] < a[child + 1])
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

void HeapSort(int* a, int size)
{
	int parent = (size - 1 - 1) / 2;
	while (parent >= 0)
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


void SelectSort(int* arr, int size)
{
	int begin = 0;
	int end = size - 1;
	while (begin < end)
	{
		int min = begin;
		int max = begin;
		for (int i = begin; i <=end; i++)
		{
			if (arr[i] < arr[min])
			{
				min = i;
			}

			if (arr[i] > arr[max])
			{
				max = i;
			}
		}
		Swap(&arr[begin], &arr[min]);
		if (max == begin)
		{
			max = min;
		}
		Swap(&arr[end], &arr[max]);
		begin++;
		end--;
	}
}

void BubbleSort(int* arr, int size)
{
	for (int j = 0;j<size; j++)
	{
		int exchange = 0;
		for (int i = 1; i < size-j; i++)
		{
			if (arr[i - 1] > arr[i])
			{
				Swap(&arr[i - 1], &arr[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}
}



void QuickSort1(int* a, int begin, int end)
{
	if (end <= begin)
	{
		return;
	}
	int left = begin;
	int right = end;
	int keyi = left;
	while (left < right)
	{
		while (left<right&&a[right] >= a[keyi])
		{
			right--;
		}

		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}

		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	keyi = left;
	QuickSort1(a, begin, keyi - 1);
	QuickSort1(a, keyi + 1, end);
}

void QuickSort2(int* a, int begin, int end)
{
	if (end <= begin)
	{
		return;
	}
	int left = begin;
	int right = end;
	int key = a[left];
	while (left < right)
	{
		while (left < right&&a[right] >= key)
		{
			right--;
		}
		a[left] = a[right];
		while (left < right&&a[left] <= key)
		{
			left++;
		}
		a[right] = a[left];
	}
	a[left] = key;
	QuickSort2(a, begin, left - 1);
	QuickSort2(a, left + 1, end);
}

void QuickSort3(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int prev = begin;
	int cur = begin + 1;
	int keyi = begin;
	int mid = midKey(a, begin, end);
	Swap(&a[keyi], &a[mid]);
	while (cur <= end)
	{
		if (a[cur] < a[keyi]&&++prev!=cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[keyi], &a[prev]);
	keyi = prev;
	QuickSort3(a, begin, keyi - 1);
	QuickSort3(a, keyi + 1, end);
}

int midKey(a, begin, end)
{
	int mid = (begin + end) / 2;
	if (mid > begin)
	{
		if (begin > end)
		{
			return begin;
		}
		else if (end > begin)
		{
			if (mid > end)
			{
				return end;
			}
			else
			{
				return mid;
			}
		}
	}
	else
	{
		if (begin < end)
		{
			return begin;
		}
		else if (begin > end)
		{
			if (mid < end)
			{
				return end;
			}
			else
			{
				return mid;
			}
		}
	}
}

int newQuickSort3(int* a, int left, int right)
{
	int keyi = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi])
		{
			if (++prev != cur)
			{
				Swap(&a[cur], &a[prev]);
			}
		}
		cur++;
	}
	Swap(&a[keyi], &a[prev]);
	keyi = prev;
	return keyi;
}

void newQuickSort(int* a,int begin,int end)
{
	if (begin >= end)
	{
		return;
	}
	int keyi = newQuickSort3(a,begin, end);
	newQuickSort(a, begin, keyi - 1);
	newQuickSort(a, keyi + 1, end);
}

void newQuickSortNonRecursive(int* a, int begin, int end)
{
	Stack* stack = createStack();
	push(stack, end);
	push(stack, begin);
	while (!isEmpty(stack))
	{
		int left = peek(stack);
		pop(stack);
		int right = peek(stack);
		pop(stack);
		int keyi= newQuickSort3(a, left,right);
		if (keyi+1 < right)
		{
			push(stack, right);
			push(stack, keyi + 1);
		}
		if (keyi-1 > left)
		{
			push(stack, keyi-1);
			push(stack, left);
		}
	}
	destroyStack(stack);
}

void _mergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}
	//����
	int mid = (begin + end) / 2;
	_mergeSort(a, begin, mid, tmp);
	_mergeSort(a, mid + 1, end, tmp);

	//�鲢
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int i = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

void mergeSort(int* a, int size)
{
	int* tmp = (int*)malloc(sizeof(int) * size);
	assert(tmp);
	_mergeSort(a, 0, size - 1, tmp);
	free(tmp);
}

void mergeSortNonRecursive1(int* a, int size)
{
	int* tmp = (int*)malloc(size * sizeof(int));
	assert(tmp);
	int gap = 1;
	int i = 0;
	while (gap < size)
	{
		for (i = 0; i < size; i += gap * 2)
		{
			int begin1 = i;
			int end1 = begin1 + gap - 1;
			int begin2 = begin1 + gap;
			int end2 = begin2 + gap - 1;
			int i_tmp = begin1;
			if (end1 > size - 1 )
			{
				end1 = size - 1;
				begin2 = size - 1;
				end2 = begin2 - 1;
			}
			else if (begin2 > size - 1)
			{
				begin2 = size - 1;
				end2 = begin2 - 1;
			}
			else if (end2 > size - 1)
			{
				end2 = size - 1;
			}

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[i_tmp++] = a[begin1++];
				}
				else
				{
					tmp[i_tmp++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[i_tmp++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[i_tmp++] = a[begin2++];
			}
		}
		memcpy(a, tmp, size * sizeof(int));
		gap *= 2;
	}
	free(tmp);
	tmp = NULL;
}

void mergeSortNonRecursive2(int* a, int size)
{
	int* tmp = (int*)malloc(size * sizeof(int));
	assert(tmp);
	int gap = 1;
	int i = 0;
	while (gap < size)
	{
		for (i = 0; i < size; i += gap * 2)
		{
			int begin1 = i;
			int end1 = begin1 + gap - 1;
			int begin2 = begin1 + gap;
			int end2 = begin2 + gap - 1;
			int i_tmp = begin1;
			if (end1 > size - 1 || begin2 > size - 1)
			{
				break;
			}
			else if (end2 > size - 1)
			{
				end2 = size - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[i_tmp++] = a[begin1++];
				}
				else
				{
					tmp[i_tmp++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[i_tmp++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[i_tmp++] = a[begin2++];
			}
			memcpy(a + i, tmp + i, (end2 - i + 1) * sizeof(int));
		}
		gap *= 2;
	}
	free(tmp);
	tmp = NULL;
}