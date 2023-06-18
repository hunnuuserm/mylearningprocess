#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

typedef int SLNodeDatatype;

typedef struct SLNode
{
	SLNodeDatatype data;
	struct SLNode* next;
	struct SLNode* pre;
}SLNode;

SLNode* AcquireNewnode(SLNodeDatatype x);

SLNode* SLNodeFind(SLNode* plist, SLNodeDatatype x);

void SLNodeInit(SLNode*plist);

void SLNodeDestroy(SLNode* plist);

void SLNodePushBack(SLNode* plist, SLNodeDatatype x);

void SLNodePopBack(SLNode* plist);

void SLNodePushFront(SLNode* plist, SLNodeDatatype x);

void SLNodePopFront(SLNode* plist);

void SLNodeInsertBefore(SLNode* plist, SLNodeDatatype x, SLNodeDatatype y);

void SLNodeErase(SLNode* plist, SLNodeDatatype x);

void SLNodePrint(SLNode* plist);

