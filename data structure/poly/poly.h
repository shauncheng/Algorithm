#ifndef POLY_H
#define POLY_H

typedef struct ElemType {
    float coef;
    int expn;
    struct ElemType *next;
}term,ElemType;
typedef struct{
    ElemType *head;
    unsigned size;
}LinkList;
void CreatePoly(LinkList *);
void IteraList(LinkList*);
void AddPoly(LinkList*);
LinkList* MergeList(LinkList*,LinkList*);
#endif  