#include <stdio.h>

int main(int argc,char *argv[]){
	unsigned int i=0;

	if((--i)>=0){
		printf("in if\r\n");
	}else{
		printf("in else\r\n");
	}
}