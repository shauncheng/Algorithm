#include"queue.h"
#include<stdio.h>
int main(int argc, char const *argv[])
{
    SqQueue q;
    InitQueue(&q);
    for(int i=0;i<10;i++)
    {
        EnQueue(&q,i+2);
    }
    while(q.size>0)
    {
        int t;
        DeQueue(&q,&t);
        printf("element: %d\n",t);
    }
    return 0;
}
