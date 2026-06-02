#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef int Elemtype;

typedef struct LNode{
    Elemtype data;
    struct LNode *next;
}LinkNode;


void InitList(LinkNode *&L){
    L = (LinkNode*)malloc(sizeof(LinkNode));
    L->next = NULL;
}


void CreateList(LinkNode *&L, int a[], int n){
    LinkNode *r = L;
    for(int i = 0; i < n; i++){
        LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
        p->data = a[i];
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

void PrintList(LinkNode *L){
    LinkNode *p = L->next;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

bool DeleteLastX(LinkNode *&L, int x){
    LinkNode *p = L->next;
    LinkNode *pre = L;

    LinkNode *last = NULL;
    LinkNode *last_pre = NULL;

    while(p != NULL){
        if(p->data == x){
            last = p;
            last_pre = pre;
        }
        pre = p;
        p = p->next;
    }

    if(last == NULL){
        return false;
    }


    last_pre->next = last->next;
    free(last);

    return true;
}

int main()
{
    LinkNode *L;
    InitList(L);

    int a[] = {1, 2, 3, 2, 4, 2, 5};
    int n = sizeof(a)/sizeof(a[0]);

    CreateList(L, a, n);

    printf("原链表:\n");
    PrintList(L);

    int x = 2;
    if(DeleteLastX(L, x))
        printf("删除后:\n", x);
    else
        printf("未找到 %d\n", x);

    PrintList(L);

    return 0;
}
