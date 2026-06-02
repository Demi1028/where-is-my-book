#include"stackqueue.cpp"

int main() {
    SqStack *S1, *S2;
    ElemType e;
    InitStack(S1);
    InitStack(S2);
    printf("模拟队列操作\n");
    // 入队 a, b, c
    printf("入队: a b c\n");
    enQueue(S1, S2, 'a');
    enQueue(S1, S2, 'b');
    enQueue(S1, S2, 'c');
    // 出队 a
    printf("出队元素: ");
    if (deQueue(S1, S2, e))
        printf("%c\n", e);
    // 入队 d, e, f, g
    printf("入队: d e f g\n");
    enQueue(S1, S2, 'd');
    enQueue(S1, S2, 'e');
    enQueue(S1, S2, 'f');
    enQueue(S1, S2, 'g');
    // 出队 b, c, d
    printf("出队元素: ");
    if (deQueue(S1, S2, e))
        printf("%c ", e);
    if (deQueue(S1, S2, e))
        printf("%c ", e);
    if (deQueue(S1, S2, e))
        printf("%c ", e);
    // 销毁栈
    DestroyStack(S1);
    DestroyStack(S2);
    return 0;
}
