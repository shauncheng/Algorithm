#include"st.h"
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    HString *h=(HString*)malloc(sizeof(HString));
    char *c="hello world";
    StrAssign(h,c);
    printf("original:%s chars:%s length:%d...\n",h->ch,c,h->length);
    HString *t=(HString*)malloc(sizeof(HString));
    StrAssign(t,c);
    HString *f=(HString*)malloc(sizeof(HString));
    Concat(f,h,t);
    printf("sub:%s\n",SubString(*f,3,5)->ch) ;
    return 0;
}
