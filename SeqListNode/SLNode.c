#pragma once

#include"SLNode.h"


SLNode* AcquireNewnode(SLNodeDatatype x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->pre = NULL;
	return newnode;
}

SLNode* SLNodeFind(SLNode* plist, SLNodeDatatype x)
{
	SLNode* ptr = plist->next ;
	while (ptr != plist)
	{
		if (ptr->data == x)
		{
			return ptr;
		}
		else
		{
			ptr = ptr->next;
		}
	}
	printf("ÕÒ²»µ½\n");
	return NULL;
}

void SLNodeInit(SLNode**pphead)
{
	SLNode* head = (SLNode*)malloc(sizeof(SLNode));
	head->next = head;
	head->pre = head;
	*pphead = head;
}

void SLNodeDestroy(SLNode* plist)
{
	SLNode* ptr = plist->next;
	while (ptr != plist)
	{
		ptr = ptr->next;
		free(ptr->pre);
	}
}

void SLNodePushBack(SLNode* plist, SLNodeDatatype x)
{
	SLNode* newnode = AcquireNewnode(x);
	SLNode* Prenewnode = plist->pre;
	Prenewnode->next = newnode;
	newnode->pre = Prenewnode;
	newnode->next = plist;
	plist->pre = newnode;
}

void SLNodePopBack(SLNode* plist)
{
	assert(plist->next != NULL);
	SLNode* pretail = plist->pre->pre;
	free(pretail->next);
	pretail->next = NULL;
	pretail->next = plist;
	plist->pre = pretail;
}

void SLNodePushFront(SLNode* plist, SLNodeDatatype x)
{
	assert(plist->next != NULL);
	SLNode* newnode = AcquireNewnode(x);
	SLNode* nextnew = plist->next;
	plist->next = newnode;
	newnode->pre = plist;
	newnode->next = nextnew;
	nextnew->pre = newnode;
}

void SLNodePopFront(SLNode* plist)
{
	assert(plist->next != NULL);
	SLNode* nextpop = plist->next->next;
	free(plist->next);
	plist->next = NULL;
	plist->next = nextpop;
	nextpop->pre = plist;
}

void SLNodeInsertBefore(SLNode* plist, SLNodeDatatype x, SLNodeDatatype y)
{
	SLNode* pos = SLNodeFind(plist,x);
	SLNode* Prepos = pos->pre;
	SLNode* newnode = AcquireNewnode(y);
	Prepos->next = newnode;
	newnode->pre = Prepos;
	newnode->next = pos;
	pos->pre = newnode;
}


void SLNodeErase(SLNode* plist, SLNodeDatatype x)
{
	SLNode* pos = SLNodeFind(plist, x);
	SLNode* Prepos = pos->pre;
	SLNode* Nextpos = pos->next;
	Prepos->next=Nextpos;
	Nextpos->pre = Prepos;
	free(pos);
	pos = NULL;
}

void SLNodePrint(SLNode* plist)
{
	SLNode* ptr = plist->next;
	while (ptr!= plist)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}