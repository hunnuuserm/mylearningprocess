#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>

#define MAX_SIZE 1000000

typedef struct Stack {
    int data[MAX_SIZE];
    int top;
} Stack;

Stack* createStack();

void push(Stack* stack, int value);

int pop(Stack* stack);

int peek(Stack* stack);

bool isEmpty(Stack* stack);

void destroyStack(Stack* stack);



void printArr(int* a, int n);

void InsertSort(int* a,int n);

void ShellSort(int* a, int n);

void Swap(int* a, int* b);

void AdjustDown(int* a, int size, int parent);

void HeapSort(int* arr, int size);

void SelectSort(int* arr, int size);

void BubbleSort(int* arr, int size);

void QuickSort1(int* a, int begin, int end);

void QuickSort2(int* a, int begin, int end);

void QuickSort3(int* a, int begin, int end);

int midKey(int a, int begin, int end);

void newQuickSort(int* a, int begin, int end);

int newQuickSort3(int* a, int begin, int end);

void newQuickSortNonRecursive(int* a, int begin, int end);

void mergeSort(int* a, int size);

void mergeSortNonRecursive1(int* a, int size);

void mergeSortNonRecursive2(int* a, int size);