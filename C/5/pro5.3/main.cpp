#include "DlinkList.cpp"

int main()
{
    DLinkNode *L;
    CreateListR(L, 5);       // 创建 1,2,3,4,5

    printf("初始化L:    ");DispList(L);
    printf("查找10:   ");Locate(L, 10);
    printf("查找5:    "); Locate(L, 5);  DispList(L);
    printf("查找1:    ");Locate(L, 1);  DispList(L);
    printf("查找4:    ");Locate(L, 4);  DispList(L);
    printf("查找5:    ");Locate(L, 5);  DispList(L);
    printf("查找2:    "); Locate(L, 2);  DispList(L);
    printf("查找4:    ");Locate(L, 4);  DispList(L);
    printf("查找5:    "); Locate(L, 5);  DispList(L);

    return 0;
}
