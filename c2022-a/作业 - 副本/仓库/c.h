#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
typedef struct huowu {
	int number;//���
	char name[100];
	int count;//��Ŀ
	struct huowu* next;
} a1; //��a1����ṹ��������
a1* search(int xinghao);
void end(void);
void init(void);
void list(void);
void add(void);
void out(void);
void creatnew(void);