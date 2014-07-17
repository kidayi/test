#include <stdio.h>

int main(int argc,char *argv[]){
	int a[]={1,2,3};
	int (*p2)[]=&a;
	int **p1=p2;

	printf("  p2:%x\n",p2);
	printf(" *p2:%x\n",*p2);
	printf("**p2:%x\n\n",**p2);

	printf("  p1:%x\n",p1);
	printf(" *p1:%x\n",*p1);
	printf("**p1:%x\n\n",**p1);
}