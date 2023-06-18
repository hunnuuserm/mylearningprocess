#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//typedef struct Contact
//{
//	char name[20];
//	int age;
//	char tele[20];
//	char address[20];
//}SC;


typedef int SeqlistDatatype;
//typedef SC SeqlistDatatype;



typedef struct Seqlist
{
	SeqlistDatatype* p;
	int sz;
	int capacity;
}SL ;


void SeqListInit(SL* pSL);

void SeqListDestroy(SL* pSL);

void SeqListPrint(SL* pSL);

int SeqListFind(SL* pSL, SeqlistDatatype x);//���ܲ���-1

void SeqListPushBack(SL* pSL, SeqlistDatatype x);

void SeqListPopBack(SL* pSL);

void SeqListPushFront(SL* pSL, SeqlistDatatype x);

void SeqListPopFront(SL* pSL);

void SeqListInert(SL* pSL, int pos, SeqlistDatatype x);

void SeqListDele(SL* pSL,SeqlistDatatype x);//������ͬԪ�أ�ֻ��ɾ����С�±��Ԫ��

void CheckCapacity(SL* pSL);