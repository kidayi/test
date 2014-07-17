#include <stdio.h>

int main(int argc,char *argv[]){
	double d=18.3;
	unsigned int ui=(unsigned int)d;
	unsigned int ui2=*(unsigned int*)&d;
	printf("%x\r\n",d);
	printf("%x\r\n",ui);
	printf("%x\r\n",ui2);
}