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

	printf("首元素是:%d\n", QueueFront(&q));

	QueuePop(&q);
	QueuePop(&q);
	QueuePrint(&q);

	QueuePush(&q, 30);
	QueuePop(&q);
	QueuePrint(&q);

	printf("队列的大小是:%d", QueueSize(&q));
	QueueDestroy(&q);
	return 0;
}