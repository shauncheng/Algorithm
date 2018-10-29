#include"queue.h"
#include<stdio.h>
#include<stdlib.h>
Status InitQueue(SqQueue*Q){
    Q->base=(ElemType*)malloc(MAXQSIZE*sizeof(ElemType));
    if(!Q->base) return OVERFLOW;
    Q->front=Q->rear=0;
    Q->size=0;
    return OK;
}
int QueueLength(SqQueue Q){
    return Q.size; 
}

Status EnQueue(SqQueue *Q,ElemType e)
{
    if((Q->rear+1)%MAXQSIZE==Q->front) return ERROR;
    Q->base[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXQSIZE;
    Q->size++;
    return OK;
}
Status DeQueue(SqQueue*Q,ElemType *e)
{
    if(Q->rear==Q->front) return ERROR;
    *e=Q->base[Q->front];
    Q->front=(Q->front+1)%MAXQSIZE;
    Q->size--;
    return OK;
}