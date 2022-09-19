#include<stdio.h>
#include<string.h>
int main(void) {
	char a[100];
	int count=0;
	
	scanf("%s",&a[1]);
	int len=strlen(a);
	for(int i=0;i<len;i++){
		if(a[i]!='*'){
			if(a[i]<'A'||(a[i]>'Z'&&a[i]<'a')||a[i]>'z'){
				printf("error\n");
				return 0;
			}
		}
	}
	
	
	int right =len, left = 0;
	while (a[right-1] == '*') {
		right--;
		count++;
	}
	while (a[left]== '*') {
		left++;
	}
	if(right==0){
		for(int i=1;i<=count;i++){
			printf("*");
		}
		printf("\n");
	}
	else 
	{
	for (; left > 0; left--) {
		printf("%c", '*');
	}
	for (int i = 0; i <len; i++) {
		if (a[i] != '*') {
			printf("%c", a[i]);
		}
	}
	for (int i=0; i<count; i++) {
		printf("%c", '*');
	}
	printf("\n");
	}










}
