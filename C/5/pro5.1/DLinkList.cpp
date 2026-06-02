#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct DNode
{
    ElemType data;
    struct DNode *prior;//前驱节点
    struct DNode *next;
} DLinkNode;


void CreateListF(DLinkNode *&L, ElemType a[], int n)
{

    L = (DLinkNode *)malloc(sizeof(DLinkNode));
    L->next = L;  // 循环：单链表头节点 next=NULL，循环双链表指向自己形成环
    L->prior = L; // 有前驱，指向自己

    DLinkNode *s;
    for (int i = 0; i < n; i++)
    {

        s = (DLinkNode *)malloc(sizeof(DLinkNode));
        s->data = a[i];


         // 对比单链表：单链表只改 next，双链表需要同时修改 prior + next 两个指针
        s->next = L->next;
        L->next->prior = s; // 原后继节点前驱 = 新节点（不同）
        L->next = s;        // 头节点后继 = 新节点
        s->prior = L; //单链表无 prior，不需要设置新节点前驱
    }
}

void CreateListR(DLinkNode *&L, ElemType a[], int n)
{
    L = (DLinkNode *)malloc(sizeof(DLinkNode));
    L->next = L;
    L->prior = L;

    DLinkNode *r = L; // 尾指针，始终指向最后一个节点
    DLinkNode *s;     // 临时节点指针

    for (int i = 0; i < n; i++)
    {

        s = (DLinkNode *)malloc(sizeof(DLinkNode));
        s->data = a[i];

        r->next = s;        // 尾节点后继 = 新节点
        s->prior = r;       // 新节点前驱 = 尾节点
        s->next = L;        // 新节点后继 = 头节点（循环）
        L->prior = s;       // 头节点前驱 = 新节点（循环）
        r = s;              // 尾指针后移
    }
}


void PrintList(DLinkNode *L)
{
    if (L->next == L)//单链表判空是 L->next==NULL，双链表判空是指向自己
    {
        printf("链表为空！\n");
        return;
    }
    DLinkNode *p = L->next;
    while (p != L) // 循环终止条件：回到头节点
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


void DestroyList(DLinkNode *&L)
{
    DLinkNode *p = L->next, *q;
    while (p != L)
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(L);
    L = NULL;
}

void DispList(DLinkNode *L)
{
    if (L->next == L)
    {
        printf("链表为空\n");
        return;
    }
    DLinkNode *p = L->next;
    while (p != L)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}
void DispListRev(DLinkNode *L)
{
    if (L->next == L)
    {
        printf("链表为空\n");
        return;
    }
    DLinkNode *p = L->prior;
    while (p != L)
    {
        printf("%c ", p->data);
        p = p->prior;
    }
    printf("\n");
}
