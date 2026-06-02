#include"linklist.cpp"

void delmaxnode(LinkNode *&L)
{
    LinkNode *p = L->next, *pre = L, *maxpre = pre;// *maxp = p,
    while (p != NULL)
    {
        if (maxpre->next->data < p->data)   // 若找到一个更大的结点
        {
            //maxp = p;               // 更改 maxp
            maxpre = pre;           // 更改 maxpre
        }
        pre = p;                    // p、pre 同步后移一个结点
        p = p->next;
    }
    maxpre->next = maxpre->next->next;      // 删除 *maxp 结点
}

int main(){
    LinkNode *h;

    //ElemType e;

    char a[] = {'a','b','c','d'};

    int n = sizeof(a)/sizeof(a[0]);

    InitList(h);

    printf("采用头插法：");

    CreateListF(h,a,n);DispList(h);

    delmaxnode(h);DispList(h);

    return 1;

}
