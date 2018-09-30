#ifndef LINKLIST_H
#define LINKLIST_H

#define USE_DOUBLE

#ifdef USE_DOUBLE
typedef double elemType;
#else
typedef int elemType;
#endif

typedef enum{
    OK, OVERFLOW, ERROR
} Status;
typedef struct Node{
    elemType data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    unsigned int size;
} LinkList;

void CreateList(LinkList *);
void IteraList(LinkList *);
Status InsertList(LinkList *,int,Node*);
Status DelNode(LinkList*,int);
LinkList* MergeList(LinkList*,LinkList*);
#endif