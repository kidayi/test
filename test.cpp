#include <stdio.h>
int func()
{
    printf("in func\n");
    return 1;
}
int val = func();
int main()
{
    printf("in main\n");
    return 0;
}

