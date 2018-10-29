#include"queue.h"
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    /* code */
    LinkQueue q;
    InitQueue(&q);
    for (int i=1;i<10;i++)
    {
        EnQueue(&q,i+2);
    }
    while(QueueEmpty(&q)!=OK)
    {
        int t=0;
        DeQUeue(&q,&t);
        printf("element: %d \n",t);
    }

    // LinkQueue *q;
    // q=(LinkQueue*)malloc(sizeof(LinkQueue));
    // InitQueue(q);
    // for (int i=1;i<10;i++)
    // {
    //     EnQueue(q,i+2);
    // }
    // while(QueueEmpty(q)!=OK)
    // {
    //     int t=0;
    //     DeQUeue(q,&t);
    //     printf("element: %d \n",t);
    // }

    return 0;
}
