#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int DataType;

typedef struct QueueNode
{
	DataType val;
	struct QueueNode* next;
}QueueNode;

typedef struct QueuePtr
{
	QueueNode* head;
	QueueNode* tail;
}QueuePtr;

void QueueInit(QueuePtr*pq);

void QueueDestroy(QueuePtr* pq);

bool QueueEmpty(QueuePtr* pq);

void QueuePush(QueuePtr* pq, DataType x);

void QueuePop(QueuePtr* pq);

DataType QueueFront(QueuePtr* pq);

size_t QueueSize(QueuePtr* pq);

void QueuePrint(QueuePtr* pq);
