#include"stack.h"

int main(int argc, char const *argv[])
{
    SqlStack s;
    InitStack(&s);
    float t=10;
    Push(&s,&t);
    Push(&s,&t);
    Push(&s,&t);
    ShowStack(&s);
    return 0;
}
