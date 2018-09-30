#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

void CreateList(LinkList *list)
{
    printf("initialize list...\n");
    list->size = 0;
    list->head = (Node *)malloc(sizeof(Node));
    Node *p, *rear = list->head;
    elemType num;
    while (1)
    {
#ifdef USE_DOUBLE
        setbuf(stdin, NULL);
        if (scanf("%lf", &num) != 1 || num == -1)
            break;
#else
        if (scanf("%d", &num) != 1 || num == -1)
            break;
#endif
        p = (Node *)malloc(sizeof(Node));
        p->data = num;
        rear->next = p;
        rear = p;
        list->size++;
    }
    rear = NULL;
    Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    temp = NULL;
}

Status InsertList(LinkList *list, int i, Node *p)
{
    Node *temp = list->head;
    int j = 0;
    while (temp && j < i - 2)
    {
        temp = temp->next;
        j++;
    }
    if (!temp || j > i - 2)
        return ERROR;
    p->next = temp->next;
    temp->next = p;
    list->size++;
    return OK;
}
LinkList *MergeList(LinkList *l1, LinkList *l2)
{
    if (!l1->head || !l2->head)
    {
        return !l1->head ? l2 : l1;
    }
    Node *cur = l1->head;
    while (cur->next)
        cur = cur->next;
    cur->next = l2->head;
    l2->head = NULL;
    l1->size += l2->size;
    return l1;
}
Status DelNode(LinkList *list, int i)
{
    Node *temp = list->head;
    int j = 0;
    while (temp && j < i - 2)
    {
        temp = temp->next;
        j++;
    }
    if (!temp || j > i - 2)
        return ERROR;
    Node *p = temp->next;
    temp->next = temp->next->next;
    free(p);
    p = NULL;
    return OK;
}

void IteraList(LinkList *list)
{
    Node *p = list->head;
#ifdef USE_DOUBLE
    while (p)
        printf("[%g]\n", p->data), p = p->next;
#else
    while (p)
        printf("[%d]\n", p->data), p = p->next;
#endif
}

int main(int argc, char const *argv[])
{
    /* code */
    LinkList list;
    CreateList(&list);
    printf("Current size: %d\n", list.size);
    LinkList lists;
    CreateList(&lists);
    printf("Current size: %d\n", lists.size);
    LinkList *final=MergeList(&list,&lists);
    IteraList(final);
    return 0;
}
