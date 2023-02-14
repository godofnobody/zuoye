#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
typedef struct huowu {
	int number;//编号
	char name[100];
	int count;//数目
	struct huowu* next;
} a1; //用a1代替结构体名货物
a1* search(int xinghao);
void end(void);
void init(void);
void list(void);
void add(void);
void out(void);
void creatnew(void);