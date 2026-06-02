#include "linklist.cpp"

int main(){
    LinkNode *h;

    //ElemType e;

    char a[] = {'a','b','c','d'};

    int n = sizeof(a);

    InitList(h);

    printf("采用头插法：");

    CreateListF(h,a,n);DispList(h);

    printf("采用尾插法：\n");

    CreateListR(h,a,n);DispList(h);

    DestroyList(h);


}
