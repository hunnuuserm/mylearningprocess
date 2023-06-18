#pragma once

# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int StackDataType;
typedef struct Stack
{
	StackDataType* pa;
	int size;
	int capacity;
}Stack;

void StackInit(Stack* pa);

void StackDestroy(Stack* pa);

void StackPush(Stack* pa, StackDataType x);

bool StackEmpty(Stack* pa);

void StackPop(Stack* pa);

StackDataType StackTop(Stack* pa);

int StackSize(Stack* pa);


void StackPrint(Stack* pa);