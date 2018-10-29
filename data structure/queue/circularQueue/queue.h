//循环队列实现
#ifndef QUEUE_H
#define QUEUE_H

#define MAXQSIZE 100
typedef int ElemType;
typedef struct{
    ElemType *base;
    int front;
    int rear;
    int size;
}SqQueue;
typedef enum
{
    OK,
    NOT,
    OVERFLOW,
    ERROR
} Status;
Status InitQueue(SqQueue *);
int QueueLength(SqQueue);
Status EnQueue(SqQueue*,ElemType );
Status DeQueue(SqQueue *,ElemType*);


#endif