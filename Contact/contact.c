#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
#include<string.h>
#include<stdio.h>
int FindByName(Con* pc,char name2[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->person[i].name, name2) == 0)
		{
			return i;
		}
	}
	return -1;
}
void add(Con* pc)
{
	printf("请输入姓名:");
	scanf("%s", pc->person[pc->sz].name);
	printf("\n");
	printf("请输入年龄:");
	scanf("%d", &pc->person[pc->sz].age);
	printf("\n");
	printf("请输入性别:");
	scanf("%s", pc->person[pc->sz].sex);
	printf("\n");
	printf("请输入地址:");
	scanf("%s", pc->person[pc->sz].address);
	printf("\n");
	pc->sz += 1;
}
void delete(Con* pc)
{
	printf("请输入要删除的人的姓名:\n");
	char name[20];
	scanf("%s", name);
	int ret=FindByName(pc, name);
	if (ret == -1)
	{
		printf("要删除的人找不到\n");
	}
	else
	{
		int i = 0;
		for (i = ret; i < pc->sz; i++)
		{
			pc->person[i] = pc->person[i + 1];
		}
		printf("删除成功\n");
	}
	pc->sz -= 1;
}
void display(Con* pc)
{
	int i = 0;
	printf("%20s%20s%20s%20s\n", "姓名", "年龄", "性别", "地址");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%20s%20d%20s%20s\n",
			pc->person[i].name,
			pc->person[i].age,
			pc->person[i].sex,
			pc->person[i].address);
	}
}
