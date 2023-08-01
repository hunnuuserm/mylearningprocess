#include"BinaryTree.h"



void initQueue(Queue* queue) {
	queue->front = 0;
	queue->rear = 0;
}

bool isEmpty(Queue* queue) {
	return queue->front == queue->rear;
}

bool isFull(Queue* queue) {
	return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void push(Queue* queue, datatype value) {
	if (isFull(queue)) {
		printf("Queue is full. Cannot push element.\n");
		return;
	}

	queue->data[queue->rear] = value;
	queue->rear = (queue->rear + 1) % MAX_SIZE;
}

void pop(Queue* queue) {
	if (isEmpty(queue)) {
		printf("Queue is empty. Cannot pop element.\n");
		return;
	}

	queue->front = (queue->front + 1) % MAX_SIZE;
}

int getSize(Queue* queue) {
	return (queue->rear - queue->front + MAX_SIZE) % MAX_SIZE;
}

datatype front(Queue* queue) {
	if (isEmpty(queue)) {
		printf("Queue is empty.\n");
		return NULL; // Return a default value or handle error case appropriately
	}

	return queue->data[queue->front];
}


void destroyQueue(Queue* queue) {
	free(queue->data);
	queue->front = 0;
	queue->rear = 0;
}


BTNode* BuyNode(BinaryTreeDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	assert(newnode);
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = x;
	return newnode;
}

void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

//void LevelOrder(BTNode* root) {
//	if (root == NULL) {
//		printf("# ");
//		return;
//	}
//
//	BTNode** queue = (BTNode**)malloc(sizeof(BTNode*) * 100); // 创建一个队列，用于层次遍历
//	int front = 0; // 队列头指针
//	int rear = 0; // 队列尾指针
//
//	queue[rear++] = root; // 根节点入队列
//
//	while (front < rear) {
//		BTNode* current = queue[front++]; // 出队列并打印节点值
//		printf("%d ", current->data);
//
//		if (current->left != NULL) {
//			queue[rear++] = current->left; // 左子节点入队列
//		}
//
//		if (current->right != NULL) {
//			queue[rear++] = current->right; // 右子节点入队列
//		}
//	}
//
//	free(queue); // 释放队列内存
//}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}



int BinaryTreeLeafSize(BTNode* root)
{

	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

int BinaryTreeLevelKSize(BTNode* root,int k)
{
	assert(k >= 1);
	if (root == NULL)
	{
		return 0;
	}

	if (k > 1)
	{
		return BinaryTreeLevelKSize(root->left , k - 1) 
			+ BinaryTreeLevelKSize(root->right, k - 1);
	}

	return 1;
}

BTNode* BinaryFind(BTNode* root, BinaryTreeDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}

	BTNode* ret1 = NULL;
	ret1 = BinaryFind(root->left, x);
	if (ret1)
	{
		return ret1;
	}

	BTNode* ret2 = NULL;
	ret2 = BinaryFind(root->right, x);
	if (ret2)
	{
		return ret2;
	}

	return NULL;
}

int TreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int ret1 = TreeDepth(root->left);
	int ret2 = TreeDepth(root->right);
	return 1 + (ret1 > ret2 ? ret1 : ret2);
}

void BinaryTreeDestroy(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	BinaryTreeDestroy(root->left);
	BinaryTreeDestroy(root->right);
	//printf("%p:%d\n", root, root->data);
	free(root);
}

void LevelOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("不是二叉树\n");
		return;
	}

	Queue q;
	initQueue(&q);
	
	push(&q, root);

	while (!isEmpty(&q))
	{
		datatype my_front = front(&q);
		printf("%d ", my_front->data);
		pop(&q);
		if (my_front->left )
		{
			push(&q, my_front->left);
		}

		if (my_front->right)
		{
			push(&q, my_front->right);
		}
	}

	//destroyQueue(&q);
	printf("\n");
}

int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	initQueue(&q);
	if (root)
	{
		push(&q, root);
	}
	while (!isEmpty(&q))
	{
		datatype my_front = front(&q);
		pop(&q);
		if (my_front == NULL)
		{
			break;
		}
		push(&q, my_front->left);
		push(&q, my_front->right);
	}
	while (!isEmpty(&q))
	{
		datatype my_front = front(&q);
		pop(&q);
		if (my_front)
		{
			return 0;
		}
	}

	return 1;
}