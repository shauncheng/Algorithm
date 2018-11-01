#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
Status InitQueue(LinkQueue *Q)
{
    Q->front  = (QueuePtr)malloc(sizeof(QNode));
    Q->rear=Q->front;
    if (!Q)
        exit(OVERFLOW);
    Q->front->next = NULL;
    Q->size = 0;
    printf("initialize successful...\n");
    printf("%p,%p\n",Q->front,Q->rear);
    return OK;
}
Status DestoryQueue(LinkQueue *Q)
{

    while (Q->front)
    {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    free(Q);
    Q = NULL;
    printf("destory successful...\n");
    return OK;
}
Status CleanQueue(LinkQueue *Q)
{
    while (Q->front!=Q->rear)
    {
        QueuePtr t=Q->front->next;
        free(Q->front);
        Q->front = t;
    }
    Q->size = 0;
    printf("clean successful...\n");
    return OK;
}
Status QueueEmpty(LinkQueue *Q)
{
    return (Q->size > 0) ? NOT : OK;
}
Status GetHead(LinkQueue *Q, ElemType *e)
{
    if (QueueEmpty == OK)
        return ERROR;
    else
    {
        *e = Q->front->data;
        return OK;
    }
}
Status EnQueue(LinkQueue*Q,ElemType e)
{
    
    QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
    p->next=NULL;
    if(!p) return OVERFLOW;
    Q->rear->data=e;
    Q->rear->next=p;
    Q->rear=p;
    p=NULL;
    Q->size++;
    return OK;
}
Status DeQUeue(LinkQueue*Q,ElemType*e)
{
    
    if(QueueEmpty==OK) return ERROR;
    *e=Q->front->data;
    QueuePtr p=Q->front->next;
    *e=Q->front->data;
    free(Q->front);
    Q->front=p;
    Q->size--;
    return OK;
}
