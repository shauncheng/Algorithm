#include"hanoi.h"
#include<stdio.h>
void Hano(int n,char s,char m,char d)
{
    if(n==1) Move(1,s,d);
    else{
        Hano(n-1,s,d,m);
        Move(n,s,d);
        Hano(n-1,m,s,d);
    }
}
void Move(int n,char s,char d)
{
    printf("第%d步，将%d号盘子%c---->%c\n",i++,n,s,d);
}