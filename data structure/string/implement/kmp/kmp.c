#include "kmp.h"
#include <stdio.h>
#include <stdlib.h>
Status FindPrefix(HString *P, int *next)
{
    int i = 1, j = 0;
    *next = 0;
    while (i < P->length)
    {
        if (P->ch[j] == P->ch[i])
        {
            next[i++] = ++j;
        }
        else if (j == 0)
        {
            next[i++] = j;
        }
        else
        {
            j = next[j - 1];
        }
    }
    return OK;
}
int MatchString(HString *S, HString *P, int pos)
{
    if (pos < 1)
        return ERROR;
    int *next = (int *)malloc(sizeof(P->length));
    int *t=next;
    FindPrefix(P, next);
    int i = pos - 1, j = 0;
    while (i < S->length)
    {
        if (S->ch[i] == P->ch[j])
        {
            if (j == P->length - 1)
            {
                next=t;
                free(next);
                next = NULL;
                return i - j;
            }
            i++;
            j++;
        }
        else if (j == 0)
        {
            i++;
        }
        else
        {
            j = *(next + j - 1);
        }
    }
    next=t;
    free(next);
    next = NULL;
    return -1;
}