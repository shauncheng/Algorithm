#include "st.h"
#include <stdlib.h>
#include <stdio.h>
Status StrAssign(HString *s, char *c)
{
    char *t = c; //临时指针指向字符串开始的位置
    if (s->ch)
    {
        free(s->ch);
    }
    int i = 0;
    while (*(c++) != '\0')
    {
        i++;
    }
    c = t;
    if (i == 0)
    {
        s->ch = NULL;
        s->length = i;
    }
    else
    {
        if (!(s->ch = (char *)malloc(s->length * (sizeof(char)))))
            return OVERFLOW;
        s->length = i;
        while (i >= 0)
        {
            s->ch[(s->length) - i--] = *(c++);
        }
    }
    t = NULL;
    return OK;
}

int StrLength(HString*S){return S->length;}

int StrCompare(HString*S, HString*T)
{
    if(S->ch==T->ch) return 0;
    else return S->ch>T->ch ? 1:-1;
}

Status ClearString(HString*S)
{
    if(S->ch) {free(S->ch);S->ch=NULL;S->length=0;}
    return OK;
}

Status Concat(HString*F,HString*S1,HString*S2)
{
    if(F->ch) free(F->ch);
    
    if(!(F->ch=(char*)malloc((S1->length+S2->length)*sizeof(char)))) return OVERFLOW;
    char *f=F->ch,*t1=S1->ch,*t2=S2->ch;
    while(*t1!='\0')
    {
        *f++=*t1++;
    }
   
    while(*t2!='\0')
    {
        *f++=*t2++;
    }
    F->length=S1->length+S2->length;
    f=NULL,t1=NULL,t2=NULL;
    return OK;
}
HString* SubString(HString S,int pos,int length)
{
    if(pos<1||pos>S.length||length<0||(length>S.length-pos+1)) exit(0);
    int i=length;
    HString *sub=(HString*)malloc(sizeof(HString));
    sub->ch=(char*)malloc(length*sizeof(char));
    sub->length=length;
    while(i>=0)
    {
        sub->ch[length-i--]=S.ch[pos++-1];
    }
    return sub;
}