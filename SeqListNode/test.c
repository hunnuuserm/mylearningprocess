#include"SLNode.h"


int main()
{
	SLNode* plist = NULL;
	SLNodeInit(&plist);
	SLNodePushBack(plist,1);
	SLNodePushBack(plist, 2);
	SLNodePushBack(plist, 3);
	SLNodePushBack(plist, 4);
	SLNodePushBack(plist, 5);
	SLNodePrint(plist);

	SLNodePushFront(plist, 10);
	SLNodePushFront(plist, 20);
	SLNodePushFront(plist, 30);
	SLNodePushFront(plist, 40);
	SLNodePushFront(plist, 50);
	SLNodePrint(plist);

	SLNodePopBack(plist);
	SLNodePopBack(plist);
	SLNodePopBack(plist);
	SLNodePrint(plist);

	SLNodePopFront(plist);
	SLNodePopFront(plist);
	SLNodePopFront(plist);
	SLNodePrint(plist);

	SLNodeInsertBefore(plist, 1, 100);
	SLNodeInsertBefore(plist, 100, 200);
	SLNodeInsertBefore(plist, 200, 300);
	SLNodePrint(plist);

	SLNodeErase(plist, 10);
	SLNodeErase(plist, 1);
	SLNodePrint(plist);

	SLNodeErase(plist, 20);
	SLNodeErase(plist, 2);
	SLNodePrint(plist);

	SLNodeDestroy(plist);
	return 0;
}