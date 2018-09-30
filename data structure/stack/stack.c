#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Status InitStack(SqlStack *s)
{
    printf("initlizing stack ...\n");
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
   
    if (!s->base) return ERROR;
    
    s->top = s->base;
    s->size = STACK_INIT_SIZE;
    printf("complete, stack size: %d...\n", s->size);
    return OK;
}
Status StackEmpty(SqlStack*s){
    if(!s->base) return ERROR;
    if(s->base==s->top) return Empty;
    else return OK;
}
Status Push(SqlStack*s,ElemType*e)
{
    if(!s->base) return ERROR;
    if(s->top-s->base>=s->size) 
    {
        s->base=(ElemType*)realloc(s->base,STACKINCREMENT*sizeof(ElemType));
        if(!s->base) return ERROR;
        s->top=s->base+s->size;
        s->size+=STACKINCREMENT;
    }
    *s->top++=*e;
}
Status Pop(SqlStack*s,ElemType*e)
{
    if(!s->base) return ERROR;
    if(s->base==s->top) return Empty;
    *e=*--s->top;
}
Status ShowStack(SqlStack*s)
{
    if(!s->base) return ERROR;
    ElemType *p=s->top;
    while(s->base!=p)
    {
        printf("base:%p top:%p [%.2f]\n",s->base,p,*--p);
    }
    p=NULL;
}