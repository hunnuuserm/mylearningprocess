#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"

//void test1()
//{
//	SL SeqListData;
//	SeqListInit(&SeqListData);
//	SeqListPushBack(&SeqListData, 1);
//	SeqListPushBack(&SeqListData, 2);
//	SeqListPushBack(&SeqListData, 3);
//	SeqListPushBack(&SeqListData, 3);
//	SeqListPushBack(&SeqListData, 3);
//	SeqListPushBack(&SeqListData, 3);
//	SeqListPushBack(&SeqListData, 3);
//	SeqListPushBack(&SeqListData, 3);
//	SeqListPushBack(&SeqListData, 3);
//	SeqListPushBack(&SeqListData, 3);
//	SeqListPushBack(&SeqListData, 3);
//
//	SeqListPopBack(&SeqListData);
//
//	SeqListPushFront(&SeqListData, 10);
//	SeqListPushFront(&SeqListData, 20);
//	SeqListPushFront(&SeqListData, 30);
//
//	SeqListPopFront(&SeqListData);
//	SeqListPopFront(&SeqListData);
//
//
//	SeqListPrint(&SeqListData);
//
//	SeqListDestroy(&SeqListData);
//}

void test2()
{
	SL SeqList;
	SeqListInit(&SeqList);
	SeqListPushBack(&SeqList, 1);
	SeqListPushBack(&SeqList, 2);
	SeqListPushBack(&SeqList, 3);
	SeqListPushBack(&SeqList, 4);
	SeqListPushBack(&SeqList, 5);
	SeqListPushBack(&SeqList, 6);
	SeqListPushBack(&SeqList, 7);
	SeqListPushBack(&SeqList, 8);
	SeqListPushBack(&SeqList, 9);
	SeqListPushBack(&SeqList, 10);

	SeqListInert(&SeqList, 1, 10);
	SeqListInert(&SeqList, 6, 60);

	SeqListDele(&SeqList, 7);
	SeqListDele(&SeqList, 10);


	SeqListPrint(&SeqList);

	SeqListDestroy(&SeqList);
}
//void test3()
//{
//	SC person1 = { "1",1,"1","1" };
//	SC person2 = { "2",2,"2","2" };
//	SC person3 = { "3",3,"3","3" };
//	SC person4 = { "4",4,"4","4" };
//	SC person5 = { "5",5,"5","5" };
//	SC person6 = { "6",6,"6","6" };
//	SC person7 = { "7",7,"7","7" };
//	SC person8 = { "8",8,"8","8" };
//	SC person9 = { "9",9,"9","9" };
//	SC person10 = { "10",10,"10","10" };
//
//
//	SL SeqList;
//	SeqListInit(&SeqList);
//
//
//
//	SeqListPushBack(&SeqList, person1);
//	SeqListPushBack(&SeqList, person2);
//	SeqListPrint(&SeqList);
//	SeqListDestroy(&SeqList);
//}
int main()
{
	//test1();
	test2();
	/*test3();*/
	return 0;
}