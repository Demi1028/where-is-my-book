#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
typedef char ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;

void CreateList(SqList *&L, ElemType a[], int n)
{
    //printf("CreateList形参n = %d\n",n);
    //printf("CreateList形参a[0] = %c\n",a[0]);
    L = (SqList *)malloc(sizeof(SqList));
    for (int i = 0; i < n; i++)
        L->data[i] = a[i];
    L->length = n;
}


void InitList(SqList *&L)
{

    L = (SqList *)malloc(sizeof(SqList));
    L->length = 0;
}

void DestroyList(SqList *&L)
{
    free(L);
}


bool ListEmpty(SqList *L)
{
    return (L->length == 0);
}


int ListLength(SqList *L)
{
    return (L->length);
}


void DispList(SqList *L)
{
    for (int i = 0; i < L->length; i++)
        printf("%c ", L->data[i]);
    printf("\n");
}

bool GetElem(SqList *L, int i, ElemType &e)
{
    //printf("GetElem形参i = %d\n",i);
    if (i < 1 || i > L->length)
        return false;
    e = L->data[i - 1];
    return true;
}


int LocateElem(SqList *L, ElemType e)
{
    //printf("ElemType形参e = %c\n",e);
    int i = 0;
    while (i < L->length && L->data[i] != e)
        i++;
    if (i >= L->length)
        return 0;
    else
        return i + 1;
}

bool ListInsert(SqList *&L, int i, ElemType e)
{
    //printf("ListInsert形参i = %d\n",i);
    //printf("ListInsert形参e = %c\n",e);

    if (i < 1 || i > L->length + 1 || L->length == MaxSize)
        return false;
    i--;
    for (int j = L->length; j > i; j--)
        L->data[j] = L->data[j - 1];
    L->data[i] = e;
    L->length++;
    return true;
}

bool ListDelete(SqList *&L, int i, ElemType &e){
    if (i < 1 || i > L->length)
        return false;
    i--;
    e = L->data[i];
    printf("删除了%c\n",e);

    for (int j = i; j < L->length - 1; j++)
        L->data[j] = L->data[j + 1];
    L->length--;
    return true;
}

