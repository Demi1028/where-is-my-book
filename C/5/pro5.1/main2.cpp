#include "DLinkList.cpp"

int main()
{
    DLinkNode *L1, *L2;  // L1头插法链表，L2尾插法链表
    ElemType A[] = {'A', 'a', 'b', 'c', 'a', 'a', 'b', 'b'};
    int n = 8;           // 数组长度

    // 1. 头插法建立链表 L1
    CreateListF(L1, A, n);
    // 2. 尾插法建立链表 L2
    CreateListR(L2, A, n);

    // ===================== 输出4个序列 =====================
    printf("===== 头插法链表 L1 =====\n");
    printf("正序输出：");
    DispList(L1);        // 应输出：b b a a c b a A
    printf("逆序输出：");
    DispListRev(L1);     // 应输出：A a b c a a b b

    printf("\n===== 尾插法链表 L2 =====\n");
    printf("正序输出：");
    DispList(L2);        // 应输出：A a b c a a b b
    printf("逆序输出：");
    DispListRev(L2);     // 应输出：b b a a c b a A

    // 销毁
    DestroyList(L1);
    DestroyList(L2);
    return 0;
}
