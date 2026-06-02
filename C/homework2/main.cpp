#include "list.cpp"

void DutchFlagList(LinkNode *h){
    LinkNode *p = h->next;

    // 三个子链表
    LinkNode *L0, *L1, *L2;
    InitList(L0);
    InitList(L1);
    InitList(L2);

    LinkNode *t0 = L0, *t1 = L1, *t2 = L2;

    while(p != NULL){
        LinkNode *next = p->next;  // 保存下一个

        if(p->data == 0){
            t0->next = p;
            t0 = p;
        }else if(p->data == 1){
            t1->next = p;
            t1 = p;
        }else{
            t2->next = p;
            t2 = p;
        }

        p->next = NULL; // 断开原链
        p = next;
    }

    // 拼接
    t0->next = L1->next;
    t1->next = L2->next;
    t2->next = NULL;

    // 把结果挂回原链表
    h->next = L0->next;

    free(L0);
    free(L1);
    free(L2);
}


int main(){
    LinkNode *h;
    InitList(h);

    int a[] = {0,0,1,2,0,1,2,1};
    int n = sizeof(a)/sizeof(a[0]);

    CreateListR(h,a,n);

    printf("原链表\n");
    DispList(h);

    DutchFlagList(h);

    printf("排序后:\n");
    DispList(h);

    return 0;
}
