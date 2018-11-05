#include"lists.h"
#include<stdio.h>
#include<stdlib.h>
GList InitG(GList G)
{
    if(!G) G=(GList)malloc(sizeof(struct GLNode));
    G->tag=1;
    G->ptr.hp=NULL;
    G->ptr.tp=NULL;
    return G;
}
GList InitAtom(GList G,AtomType atom)
{
    if(!G) G=(GList)malloc(sizeof(struct GLNode));
    G->tag=0;
    G->atom=atom;
    return G;
}
void ShowG(GList G)
{
//comming soon

}
void DestoryNode(GList G)
{
    free(G);
    G=NULL;
}