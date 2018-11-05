#include"binlink.h"
#include<stdio.h>
int main(int argc, char const *argv[])
{
    BiTNode *T;
    T=CreateBiTree(T);

    // printf("data:%d\n",T->data);
    PreOrderTraverse(T,DataProcess);
    // if(PreOrderTraverse(T,DataProcess)==ERROR)
    printf("出错.\n");
    InOrderTraverse(T,DataProcess);
    printf("出错.\n");
    PostOrderTraverse(T,DataProcess);
    return 0;
}
