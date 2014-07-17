#include <stdio.h>

void change(int *a){
	*a=1;
}

int main(int argc,char *argv[]){
	int test=8;
	printf("before change:%d\r\n",test);
	change(&test);
	printf("after change:%d\r\n",test);
}



