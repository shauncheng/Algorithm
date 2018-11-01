#ifndef ST_H
#define ST_H
typedef struct{
    char *ch;
    int length;
}HString;
typedef enum
{
    OK,
    NOT,
    OVERFLOW,
    ERROR
} Status;
Status StrAssign(HString*,char*);
int StrLength(HString*);
int StrCompare(HString*, HString*);
Status ClearString(HString*);
Status Concat(HString*,HString*,HString*);
HString* SubString(HString,int,int);
#endif