#include "poly.h"
#include <stdlib.h>
#include <stdio.h>
void CreatePoly(LinkList *L)
{
    printf("initializing Link...\n");
    L->size = 0;
    L->head = (ElemType *)malloc(sizeof(ElemType));
    ElemType *p, *rear = L->head;
    float coef;
    int expn;
    while (1)
    {
        setbuf(stdin, NULL);
        if (scanf("%f %d", &coef, &expn) != 2)
            break;
        p = (ElemType *)malloc(sizeof(ElemType));
        p->coef = coef, p->expn = expn;
        rear->next = p;
        rear = p;
        L->size++;
    }
    rear = L->head;
    L->head = L->head->next;
    free(rear);
    rear = NULL;
}
void IteraList(LinkList *L)
{
    printf("length of poly:%d...\n", L->size);
    ElemType *p = L->head;
    
    while (p)
    {
        char plus;
        p->next?(plus='+'):(plus=' ');
        printf("%.1f*X^%d%c", p->coef, p->expn,plus);
        p = p->next;
    }
    printf("\n");
}
LinkList *MergeList(LinkList *l1, LinkList *l2)
{
    if (!l1->head || !l2->head)
    {
        return !l1->head ? l2 : l1;
    }
    ElemType *cur = l1->head;
    while (cur->next)
        cur = cur->next;
    cur->next = l2->head;
    l2->head = NULL;
    l1->size += l2->size;
    return l1;
}
void AddPoly(LinkList *L)
{
    ElemType *cur = L->head, *p, *t,*rear;
    while (cur)
    {
        p = cur->next;
        rear=cur;
        while (p)
        {
            if (p->expn == cur->expn)
            {
                cur->coef+=p->coef;
                rear->next=p->next;
                t=p;
                p=p->next;
                rear=rear->next;
                free(t);
            }else p=p->next,rear=rear->next;
        }
        cur=cur->next;
    }
}