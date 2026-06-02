#include <stdio.h>
#include <malloc.h>
#define MaxSize 5
typedef char ElemType;

typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

// 初始化栈
void InitStack(SqStack *&s) {
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
}

// 判断栈是否为空
bool StackEmpty(SqStack *s) {
    return (s->top == -1);
}

// 进栈
bool Push(SqStack *&s, ElemType e) {
    if (s->top == MaxSize - 1)
        return false; // 栈满
    s->data[++s->top] = e;
    return true;
}
// 出栈
bool Pop(SqStack *&s, ElemType &e) {
    if (s->top == -1)
        return false; // 栈空
    e = s->data[s->top--];
    return true;
}

// 销毁栈
void DestroyStack(SqStack *&s) {
    free(s);
}

// 入队：所有元素压入 S1
void enQueue(SqStack *&S1, SqStack *&S2, ElemType e) {
    Push(S1, e);
}

// 出队：S2 为空时先把 S1 全部倒入 S2，再从 S2 出
bool deQueue(SqStack *&S1, SqStack *&S2, ElemType &e) {
    if (StackEmpty(S1) && StackEmpty(S2))
        return false; // 队空，出队失败
    // 若 S2 为空，先将 S1 所有元素倒入 S2
    if (StackEmpty(S2)) {
        while (!StackEmpty(S1)) {
            ElemType tmp;
            Pop(S1, tmp);
            Push(S2, tmp);
        }
    }
    Pop(S2, e);
    return true;
}
