#include"c.h"
FILE* fp = NULL;
a1* head = NULL; //����ͷָ��,����û�涫��
a1* tail;
int main() {
	init();//��ʼ��������ȡ�ļ�
	while (1) {
		printf("��1�б���2��⣬��3���⣬��4�˳�������\n");
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
			printf("����ɹ�");
			end();
			return 0;

		}
	}
}
void add(void) { //���
	int number;
	int bh;//��ţ�
	printf("��������Ҫ���ı������Ŀ\n");
	scanf("%d %d", &bh, &number);
	a1* p = search(bh);
	if (p) {
		p->count += number;
	}
	else {
		printf("��������Ŀ\n");
		printf("����������\n");
		creatnew();
		tail->next = NULL;
		tail->number = bh;
		scanf("%s", tail->name);
		tail->count = number;

	}
}
void out(void) { //����
	int number;
	int bh;//��ţ�
	printf("��������Ҫ����ı������Ŀ\n");
	scanf("%d %d", &bh, &number);
	a1* p = search(bh);
	if (p) {
		p->count -= number;
	}
	else {
		printf("û��\n");
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
	while (!feof(fp)) { //feof�������һ���ļ��Ƿ�������������ļ�β�����������򷵻ط�0ֵ�����򷵻�0
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
void creatnew() {//����һ���½ڵ� 
	a1* p = (a1*)malloc(sizeof(a1));
	p->next = NULL;
	tail->next = p;
	tail = tail->next;
}