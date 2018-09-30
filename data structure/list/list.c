#include "list.h"
#include <stdio.h>
#include <stdlib.h>

Status InitLIst(sqList *L)
{
    printf("initializing list...\n");
    L->elem = (elemType *)malloc(LIST_INIT_SIZE * sizeof(elemType));
    if (!L->elem)
        exit(OVERFLOW);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    printf("length:%d , size: %d\n", L->length, L->listsize);
    return OK;
}

Status Insert(sqList *L, int i, elemType e)
{
    if (i < 1 || i > L->listsize + 1)
        return ERROR;
    if (L->length >= L->listsize)
    {
        elemType *newbase = (elemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(elemType));
        if (!newbase)
            exit(OVERFLOW);
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }
    elemType *q = &(L->elem[i - 1]);
    for (elemType *p = &(L->elem[L->length - 1]); p >= q; --p)
        *(p + 1) = *p;
    *q = e;
    ++L->length;
    return OK;
}

void IteraList(sqList *L)
{
    if (L->length < 1)
    {
        printf("empty list!\n");
    }
    else
    {

        for (int n = 0; n < L->length; n++)
        {
            printf("index %d value %d\n", n, L->elem[n]);
        }
    }
}
Status DelItem(sqList*L,int i)
{
    if(i<0&&i>=L->length) return OVERFLOW;
    
    for (elemType *q=&(L->elem[i-1]);q<&(L->elem[L->length-1]);q++) *q=*(q+1);
    --L->length;
}

int main()
{
    sqList list;
    InitLIst(&list);
    for (int i = 0; i < 10; i++)
    {
        Insert(&list, i + 1, i + 10);
    }
    DelItem(&list,2);
    IteraList(&list);
    return OK;
};
