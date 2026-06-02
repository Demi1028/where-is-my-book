#include "sqstack.cpp"                   //包含顺序栈的基本运算算法
int main()
{
    ElemType e;
    SqStack *s;
    printf("顺序栈 s 的基本运算如下:\n");
    printf("  (1)初始化栈 s\n");
    InitStack(s);
    printf("  (2)栈为 %s\n",(StackEmpty(s)?"空":"非空"));
    printf("  (3)依次进栈元素 11,21,31,41,51\n");

    Push(s,11);
    Push(s,21);
    Push(s,31);
    Push(s,41);
    Push(s,51);
    printf("  (4)栈为 %s\n",(StackEmpty(s)?"空":"非空"));
    printf("  (5)出栈序列:");
    while (!StackEmpty(s))
    {
        GetTop(s,e);
        printf("用gettop查看：%d\n",e);
        Pop(s,e);
        //printf(" %d ",e);
    }
    printf("\n");
    printf("  (6)栈为 %s\n",(StackEmpty(s)?"空":"非空"));
    printf("  (7)释放栈\n");
    DestroyStack(s);
    return 1;
}
