#include"matrix.h"
#include<stdio.h>
#include<stdlib.h>
Status InitMatrix(TSMatrix*M,int c,int l,int n){
    if(M->data)free(M->data);
    M->data=(Triple*)malloc(n*sizeof(Triple));
    M->mu=c;
    M->nu=l;
}
Status TransposeMatrix(TSMatrix*M,TSMatrix*T)
{

}