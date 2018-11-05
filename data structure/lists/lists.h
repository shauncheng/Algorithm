#ifndef LISTS_H
#define LISTS_H
typedef int AtomType;
typedef enum
{
    ATOM,
    LIST
} ElemTag;
typedef struct GLNode
{
    ElemTag tag;
    union {
        AtomType atom;
        struct
        {
            struct GLNode *hp, *tp;
        } ptr;
    };
}*GList;

GList InitG(GList);
GList InitAtom(GList,AtomType);
void ShowG(GList);
void DestoryNode(GList );

#endif