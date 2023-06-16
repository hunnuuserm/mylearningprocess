#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define MAX_SIZE 100



typedef int BinaryTreeDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BinaryTreeDataType data;
}BTNode;

typedef BTNode* datatype;

typedef struct {
	datatype data[MAX_SIZE];
	int front;
	int rear;
} Queue;

void initQueue(Queue* queue);

bool isEmpty(Queue* queue);

bool isFull(Queue* queue);

void push(Queue* queue, datatype value);

void pop(Queue* queue);

int getSize(Queue* queue);

datatype front(Queue* queue);

void destroyQueue(Queue* queue);


BTNode* BuyNode(BinaryTreeDataType x);

void PreOrder(BTNode* root);

void InOrder(BTNode* root);

void PostOrder(BTNode* root);

void LevelOrder(BTNode* root);

void LevelOrder(BTNode* root);

int BinaryTreeSize(BTNode* root);

int BinaryTreeLeafSize(BTNode* root);

int BinaryTreeLevelKSize(BTNode* root,int k);

BTNode* BinaryFind(BTNode* root, BinaryTreeDataType x);

int TreeDepth(BTNode* root);

void BinaryTreeDestroy(BTNode* root);

void LevelOrder(BTNode* root);

int BinaryTreeComplete(BTNode* root);