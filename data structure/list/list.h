#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef enum{
    OK,OVERFLOW,ERROR
}Status;
typedef int elemType;
typedef struct{
    elemType *elem;
    int length;
    int listsize;   
}sqList;
//初始化线性表
Status InitLIst(sqList*);
//线性表插值
Status Insert(sqList*,int,elemType);
//遍历线性表
void IteraList(sqList*);
//删除线性表元素
Status DelItem(sqList*,int);
