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
	printf("����������:");
	scanf("%s", pc->person[pc->sz].name);
	printf("\n");
	printf("����������:");
	scanf("%d", &pc->person[pc->sz].age);
	printf("\n");
	printf("�������Ա�:");
	scanf("%s", pc->person[pc->sz].sex);
	printf("\n");
	printf("�������ַ:");
	scanf("%s", pc->person[pc->sz].address);
	printf("\n");
	pc->sz += 1;
}
void delete(Con* pc)
{
	printf("������Ҫɾ�����˵�����:\n");
	char name[20];
	scanf("%s", name);
	int ret=FindByName(pc, name);
	if (ret == -1)
	{
		printf("Ҫɾ�������Ҳ���\n");
	}
	else
	{
		int i = 0;
		for (i = ret; i < pc->sz; i++)
		{
			pc->person[i] = pc->person[i + 1];
		}
		printf("ɾ���ɹ�\n");
	}
	pc->sz -= 1;
}
void display(Con* pc)
{
	int i = 0;
	printf("%20s%20s%20s%20s\n", "����", "����", "�Ա�", "��ַ");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%20s%20d%20s%20s\n",
			pc->person[i].name,
			pc->person[i].age,
			pc->person[i].sex,
			pc->person[i].address);
	}
}
