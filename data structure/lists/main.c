#include"lists.h"
#include<stdio.h>
int main(int argc, char const *argv[])
{
    GList G;
    G=InitG(G);

    G->ptr.hp=NULL;
    G->ptr.tp=InitG(G->ptr.tp);
    GList t=G;
    for(int i=0;i<2;i++)
    {
        t->ptr.tp=InitG(t->ptr.tp);
        t=t->ptr.tp;
    }
    t->ptr.tp=NULL;
    t->ptr.hp=InitG(t->ptr.hp);
    t=t->ptr.hp;
    t->ptr.hp=InitAtom(t->ptr.hp,10);
    t->ptr.tp=InitG(t->ptr.tp);
    t=t->ptr.tp;
    return 0;
}
