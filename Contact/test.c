#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"contact.h"
void menu()
{
	printf("****************************************\n");
	printf("**********1.���    2.ɾ��**************\n");
	printf("**********3.��ӡ    4.�޸�**************\n");
	printf("**********5.����    0.�˳�**************\n");
	printf("****************************************\n");
	printf("****************************************\n");
}
enum
{
	EXIT,
	ADD,
	DELETE,
	DISPLAY,
	MODIFY,
	SORT
};
Con contact = { 0 };
int main()
{

	do
	{
		menu();
		int input = 0;
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add(&contact);
			break;
		case DELETE:
			delete(&contact);
			break;
		case DISPLAY:
			display(&contact);
			break;
		case MODIFY:
			break;
		case SORT:
			break;
		default:
			break;
		}

	} while (1);
	return 0;
}