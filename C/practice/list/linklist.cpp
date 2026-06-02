#include <stdio.h>
#include <string.h>
#define Max 100
typedef char Elemtype;
typedef struct LNode{
    Elemtype data;
    LNode *next;
}LinkNode;

void InitList(LNode *&L){
    L=(LNode *)malloc sizeof(LNode);
    L ->next = NULL;
}
void DestroyList(LinkNode *&L){
    LinkNode *pre,*p;
    pre = L;
    p = pre->next;
    while(p != NULL){
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}
void ListInsert(LinkNode *&L,int i,Elemtype e){//i指链表的第几个数据，从1开始 这一个错了好多次
    LinkNode *pre,*p,*s;
    pre = L;
    p = pre ->next;
    s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = e;
    for(int j = 1;j<=i;j++){
        pre = p;
        p = pre->next;
    }
    e->next = p;
    pre ->next = e;
}

bool ListDelete(LinkNode *&L, int i, ElemType &e)//这个函数几乎第一次逻辑全部有问题：注意p的判断以及情况分类
{
    if (i < 1) return false;

    LinkNode *pre = L;
    LinkNode *p = pre->next;

    for (int j = 1; j < i; j++)
    {
        if (p == NULL) return false;

        pre = p;
        p = p->next;
    }

    if (p == NULL) return false;

    pre->next = p->next;
    e = p->data;
    free(p);

    return true;
}
