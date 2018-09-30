#ifndef STACK_H
#define STACK_H
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef float ElemType;
typedef struct SqlStack {
    ElemType *base;
    ElemType *top;
    unsigned size;
} SqlStack;
typedef enum
{
    OK,
    Empty,
    OVERFLOW,
    ERROR
} Status;
Status InitStack(SqlStack *);
Status Pop(SqlStack *, ElemType *);
Status Push(SqlStack *, ElemType *);
Status StackEmpty(SqlStack *);
Status ShowStack(SqlStack *);
#endif