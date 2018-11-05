#ifndef MATRIX_H
#define MATRIX_H
typedef int ElemType;
typedef struct{
    int i,j;
    ElemType e;
}Triple;
typedef struct{
    Triple *data;
    int mu,nu,tu;
}TSMatrix;
typedef enum
{
    OK,
    NOT,
    OVERFLOW,
    ERROR
} Status;
Status InitMatrix(TSMatrix*,int,int,int);
Status TransposeMatrix(TSMatrix*,TSMatrix*);

#endif