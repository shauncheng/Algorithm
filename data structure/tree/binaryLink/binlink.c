#include "binlink.h"
#include <stdio.h>
#include <stdlib.h>
BiTree InitNode(TElemType e)
{
    BiTree T;
    if (!(T = (BiTree)malloc(sizeof(BiTNode))))
        exit(1);
    T->data = e;
    T->lchild = NULL;
    T->rchild = NULL;
    return T;
}
BiTree CreateBiTree(BiTree T)
{
    if (!(T = (BiTree)malloc(sizeof(BiTNode))))
        exit;
    T->data = 30;
    BiTree t = T;
    t->lchild = InitNode(20);
    t->rchild = InitNode(3);
    t->lchild->lchild = InitNode(33);
    t->lchild->rchild = InitNode(333);
    t->rchild->rchild = InitNode(33344);
    t = NULL;
    return T;
}

Status PreOrderTraverse(BiTree T, Status (*Visit)(TElemType))
{
    if (T)
    {
        if (Visit(T->data) == OK)
            if (PreOrderTraverse(T->lchild, DataProcess) == OK)
                if (PreOrderTraverse(T->rchild, DataProcess) == OK)
                    return OK;
        return ERROR;
    }
    else
        return OK;
}
Status InOrderTraverse(BiTree T, Status (*Visit)(TElemType))
{
    if (T)
    {
        if (InOrderTraverse(T->lchild, DataProcess) == OK)
            if (Visit(T->data) == OK)
            {
                if (InOrderTraverse(T->rchild, DataProcess) == OK)
                    return OK;
            }
            else
                return ERROR;
    }
    return OK;
}
Status PostOrderTraverse(BiTree T, Status (*Visit)(TElemType))
{
    if (T)
    {
        if (PostOrderTraverse(T->lchild, DataProcess) == OK)
            if (PostOrderTraverse(T->rchild, DataProcess) == OK)
                if (Visit(T->data) == OK)
                    return OK;
                else
                    return ERROR;
    }
    return OK;
}
Status LevelOrderTraverse(BiTree T,Status (*Visit)(TElemType))
{
    //使用队列实现，暂不实现。
}
Status DataProcess(TElemType e)
{
    printf("data:%d\n", e);
    return OK;
}