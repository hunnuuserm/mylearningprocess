#include"queue.h"


void QueueInit(QueuePtr* pq)
{
	pq->head = NULL;
	pq->tail = NULL;
}

void QueueDestroy(QueuePtr* pq)
{
	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
}

void QueuePush(QueuePtr* pq, DataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newnode);
	newnode->next = NULL;
	newnode->val = x;
	if (pq->head == NULL)
	{
		pq->head = newnode;
		pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(QueuePtr* pq)
{
	assert(pq->head);
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
}

bool QueueEmpty(QueuePtr* pq)
{
	return pq->head == NULL;
}

DataType QueueFront(QueuePtr* pq)
{
	assert(!QueueEmpty(pq));
	return pq->head->val;
}

size_t QueueSize(QueuePtr* pq)
{
	QueueNode* cur = pq->head;
	size_t size = 0;
	while (cur)
	{
		size += 1;
		cur = cur->next;
	}
	return size;
}

void QueuePrint(QueuePtr* pq)
{
	QueueNode* cur = pq->head;
	while (cur)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}