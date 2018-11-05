#ifndef BINLINK_H
#define BINLINK_H
typedef int TElemType;
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef enum
{
    OK,
    NOT,
    OVERFLOW,
    ERROR
} Status;
BiTree InitNode(TElemType);
BiTree CreateBiTree(BiTree);
Status PreOrderTraverse(BiTree,Status (*)());
Status InOrderTraverse(BiTree,Status(*)());
Status PostOrderTraverse(BiTree,Status(*)());
Status LevelOrderTraverse(BiTree,Status(*)());
Status DataProcess(TElemType);

#endif