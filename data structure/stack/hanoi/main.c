#include"hanoi.h"
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int num=0;
    /* code */
    printf("请输入碟子个数：");
    scanf("%d",&num);
    char s='A',m='Y',d='Z';
    printf("步骤如下：\n");
    Hano(num,s,m,d);
    return 0;
}
