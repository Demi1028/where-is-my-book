#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DNode
{
    ElemType data;
    int freq;
    struct DNode *prior;
    struct DNode *next;
} DLinkNode;


void CreateListR(DLinkNode *&L, int n)
{
    L = (DLinkNode *)malloc(sizeof(DLinkNode));
    L->next = L;
    L->prior = L;
    DLinkNode *r = L;

    for (int i = 1; i <= n; i++)
    {
        DLinkNode *s = (DLinkNode *)malloc(sizeof(DLinkNode));
        s->data = i;
        s->freq = 0;


        r->next = s;
        s->prior = r;
        s->next = L;
        L->prior = s;
        r = s;
    }
}
void Locate(DLinkNode *&L, ElemType x)
{
    DLinkNode *p = L->next;
    while (p != L && p->data != x)
        p = p->next;
    if (p == L)
    {
        printf("Î´ÕÒµ½ %d\n", x);
        return;
    }

    p->freq++;

    p->prior->next = p->next;
    p->next->prior = p->prior;

    DLinkNode *q = L->next;
    while (q != L && q->freq > p->freq)
        q = q->next;

    p->next = q;
    p->prior = q->prior;
    q->prior->next = p;
    q->prior = p;
}

void DispList(DLinkNode *L)
{
    DLinkNode *p = L->next;
    while (p != L)
    {
        printf("%d[%d] ", p->data, p->freq);
        p = p->next;
    }
    printf("\n");
}
