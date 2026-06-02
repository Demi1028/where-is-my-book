#include "DLinkList.cpp"

int main()
{
    DLinkNode *L1, *L2;
    ElemType arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    // 测试头插法
    CreateListF(L1, arr, n);
    printf("头插法创建的循环双链表：");
    PrintList(L1);

    // 测试尾插法
    CreateListR(L2, arr, n);
    printf("尾插法创建的循环双链表：");
    PrintList(L2);

    DestroyList(L1);
    DestroyList(L2);
    return 0;
}
