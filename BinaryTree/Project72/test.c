#include"BinaryTree.h"

//BTNode* CreatBinaryTree()
//{
//	BTNode* node1 = BuyNode(1);
//	BTNode* node2 = BuyNode(2);
//	BTNode* node3 = BuyNode(3);
//	BTNode* node4 = BuyNode(4);
//	BTNode* node5 = BuyNode(5);
//	BTNode* node6 = BuyNode(6);
//
//	node1->left = node2;
//	node1->right = node4;
//	node2->left = node3;
//	node4->left = node5;
//	node4->right = node6;
//	return node1;
//}

int main()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);
	BTNode* node8 = BuyNode(8);
	BTNode* node9 = BuyNode(9);
	/*BTNode* node7 = BuyNode(7);
	BTNode* node8 = BuyNode(8);
	BTNode* node9 = BuyNode(9);
	BTNode* node10 = BuyNode(10);*/

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node3->left  = node7;
	node3->right = node8;
	node2->right = node9;
	//node3->left = node7;
	//node5->right = node8;
	//node6->left = node9;
	//node6->right = node10;

	PreOrder(node1);
	printf("\n");
	InOrder(node1);
	printf("\n");
	PostOrder(node1);
	printf("\n");
	

	printf("BinaryTreeSize:%d\n", BinaryTreeSize(node1));
	printf("BinaryTreeLeafSize:%d\n", BinaryTreeLeafSize(node1));
	printf("BinaryTreeLevelKSize:%d\n", BinaryTreeLevelKSize(node1, 3));
	printf("BinaryFind:%p\n", BinaryFind(node1, 7));

	printf("TreeDepth:%d\n", TreeDepth(node1));

	LevelOrder(node1);

	printf("BinaryTreeComplete:%d\n", BinaryTreeComplete(node1));

	BinaryTreeDestroy(node1);


	return 0;
}