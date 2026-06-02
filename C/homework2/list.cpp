#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LinkNode;

void InitList(LinkNode *&L){
    L = (LinkNode*)malloc(sizeof(LinkNode));
    L->next = NULL;
}

void CreateListR(LinkNode *&L, int a[], int n){
    LinkNode *r = L;
    for(int i = 0; i < n; i++){
        LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
        p->data = a[i];
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

void DispList(LinkNode *L){
    LinkNode *p = L->next;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
