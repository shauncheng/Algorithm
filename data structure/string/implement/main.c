#include "st.h"
#include "./kmp/kmp.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    HString *h = (HString *)malloc(sizeof(HString));
    char *c = "aabaabaaa";
    StrAssign(h, c);
    printf("original:%s chars:%s length:%d...\n", h->ch, c, h->length);
    HString *t = (HString *)malloc(sizeof(HString));
    StrAssign(t, c);
    HString *f = (HString *)malloc(sizeof(HString));
    Concat(f, h, t);
    StrAssign(f, "abxabcabcaby");
    StrAssign(h, "abcaby");
    printf("h:%s\n", h->ch);
    printf("sub:%s\n", f->ch);
    printf("pos:%d...\n", MatchString(f, h, 1));
    return 0;
}
