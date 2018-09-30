#include<stdio.h>
#include"poly.h"

int main(int argc, char const *argv[])
{
    LinkList L;
    CreatePoly(&L);
    LinkList L2;
    CreatePoly(&L2);
    LinkList *final;
    final=MergeList(&L,&L2);
    AddPoly(final);
    IteraList(final);
    return 0;
}
