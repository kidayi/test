#include <stdio.h>
struct Test{
    int a:1;
};
 
int main(int argc,char *argv[]){
    struct Test test;
    test.a=1;
    printf("a:%d\r\n",test.a);
 
    if(test.a==1){
        printf("test.a==1\r\n");
    }else{
        printf("test.a!=1\r\n");
    }
 
    if(test.a){
        printf("test.a true\r\n");
    }else{
        printf("test.a false\r\n");
    }

    if(!test.a){
        printf("!test.a true\r\n");
    }else{
        printf("!test.a false\r\n");
    }
 
    if(-test.a){
        printf("-test.a true\r\n");
    }else{
        printf("-test.a false\r\n");
    }
 
    if(+test.a){ 
        printf("+test.a true\r\n");
    }else{
        printf("+test.a false\r\n");
    }
 
    int b=-1;
    printf("+b:%d\r\n",+b);
}
