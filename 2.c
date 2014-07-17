#include <stdio.h>

int main(int argc,char *argv[]){
	int a[]={1,2,3};
	int **p1=&a;
	int (*p2)[]=&a;
	int b[2][3]={1,2,3,4,5,6};

	printf("  a:%x\n",a);
	printf(" &a:%x\n",&a);
	printf(" *a:%x\n\n",*a);

	printf("       b:%x\n",b);
	printf("    b[0]:%x\n",b[0]);
	printf(" b[0][0]:%x\n",b[0][0]);
	printf("      *b:%x\n",*b);
	printf("     **b:%x\n\n",**b);
	
	
	printf("  p2:%x\n",p2);
	printf(" *p2:%x\n",*p2);
	printf("**p2:%x\n\n",**p2);

	printf("  p1:%x\n",p1);
	printf(" *p1:%x\n",*p1);
	printf("**p1:%x\n\n",**p1);
}
