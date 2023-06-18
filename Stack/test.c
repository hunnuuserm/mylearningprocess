#include"stack.h"

int main()
{
	Stack stack1;
	StackInit(&stack1);
	StackPush(&stack1, 1);
	StackPush(&stack1, 2);
	StackPush(&stack1, 3);
	StackPush(&stack1, 4);
	StackPush(&stack1, 6);
	StackPush(&stack1, 6);
	StackPush(&stack1, 6);
	StackPrint(&stack1);

	StackPop(&stack1);
	StackPop(&stack1);
	StackPrint(&stack1);
	printf("%d\n",StackTop(&stack1));
	printf("%d\n", StackSize(&stack1));

	StackDestroy(&stack1);

	return 0;
}