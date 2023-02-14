#include"c.h"
FILE* fp = NULL;
a1* head = NULL; //定义头指针,里面没存东西
a1* tail;
int main() {
	init();//初始化，即读取文件
	while (1) {
		printf("按1列表，按2入库，按3出库，按4退出并保存\n");
		switch (getch()) {
		case '1':
			list();
			break;
		case '2':
			add();
			break;
		case '3':
			out();
			break;
		case '4':
			printf("保存成功");
			end();
			return 0;

		}
	}
}
void add(void) { //入库
	int number;
	int bh;//编号；
	printf("请输入需要入库的编号与数目\n");
	scanf("%d %d", &bh, &number);
	a1* p = search(bh);
	if (p) {
		p->count += number;
	}
	else {
		printf("创建新条目\n");
		printf("请输入名字\n");
		creatnew();
		tail->next = NULL;
		tail->number = bh;
		scanf("%s", tail->name);
		tail->count = number;

	}
}
void out(void) { //出库
	int number;
	int bh;//编号；
	printf("请输入需要出库的编号与数目\n");
	scanf("%d %d", &bh, &number);
	a1* p = search(bh);
	if (p) {
		p->count -= number;
	}
	else {
		printf("没有\n");
	}
}
void list(void) {
	for (a1* p = head->next; p; p = p->next) {
		printf("%d %s %d\n", p->number, p->name, p->count);
	}
}
void init(void) {
	head = (a1*)malloc(sizeof(a1));
	a1* p = NULL;
	p = (a1*)malloc(sizeof(a1));
	head->next = p;
	a1* last = head;
	fp = fopen("cangku.txt", "r");
	while (!feof(fp)) { //feof（）检测一个文件是否结束，即到达文件尾，若结束，则返回非0值，否则返回0
		p = (a1*)malloc(sizeof(a1));
		fscanf(fp, "%d %s %d\n", &p->number, p->name, &p->count);
		p->next = NULL;
		last->next = p;
		last = last->next;
	}
	tail = p;
	fclose(fp);

}
a1* search(int xinghao) {
	a1* p = head->next;
	for (; (p != NULL) && (p->number != xinghao); p = p->next) {

	}

	return p;
}
void end(void) {
	fp = fopen("cangku.txt", "w");
	for (a1* p = head->next; p; p = p->next) {
		fprintf(fp, "%d %s %d\n", p->number, p->name, p->count);
	}
	fclose(fp);
}
void creatnew() {//创建一个新节点 
	a1* p = (a1*)malloc(sizeof(a1));
	p->next = NULL;
	tail->next = p;
	tail = tail->next;
}