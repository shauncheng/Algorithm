//单链队列
#ifndef QUEUE_H
#define QUEUE_H
typedef int ElemType;
typedef struct QNode{
    ElemType data;
    struct QNode *next;
}QNode, *QueuePtr;
typedef struct{
    QueuePtr front;
    QueuePtr rear;
    int size;
}LinkQueue;
typedef enum
{
    OK,
    NOT,
    OVERFLOW,
    ERROR
} Status;
Status InitQueue(LinkQueue*);
Status DestoryQueue(LinkQueue*);
Status CleanQueue(LinkQueue*);
Status QueueEmpty(LinkQueue*);
Status GetHead(LinkQueue*,ElemType *);
Status EnQueue(LinkQueue*,ElemType);
Status DeQUeue(LinkQueue*,ElemType*);

#endif