#include"queue.h"

int main()
{
	QueuePtr q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePrint(&q);

	printf("��Ԫ����:%d\n", QueueFront(&q));

	QueuePop(&q);
	QueuePop(&q);
	QueuePrint(&q);

	QueuePush(&q, 30);
	QueuePop(&q);
	QueuePrint(&q);

	printf("���еĴ�С��:%d", QueueSize(&q));
	QueueDestroy(&q);
	return 0;
}