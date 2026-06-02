#include<stdio.h>
#include <malloc.h>

#define Maxsize 100
typedef char ElemType;
typedef struct{
    ElemType data[Maxsize];
    int front,rear;
}Queue;


typedef struct {
    ElemType data[Maxsize];
    int top;
} Stack;


void InitQueue(Queue *q) {
    q->front = q->rear = 0;
}

int QueueEmpty(Queue *q) {
    return q->front == q->rear;
}

void EnQueue(Queue *q, ElemType e) {
    q->data[q->rear++] = e;
}

ElemType DeQueue(Queue *q) {
    return q->data[q->front++];
}


void InitStack(Stack *s) {

    s->top = -1;
}

int StackEmpty(Stack *s) {
    return s->top == -1;
}

void Push(Stack *s, ElemType e) {
    s->data[++s->top] = e;
}

ElemType Pop(Stack *s) {
    return s->data[s->top--];
}

/* ===== 反转队列 ===== */
void ReverseQueue(Queue *q) {
    Stack s;
    InitStack(&s);

    // 1. 队列 → 栈
    while (!QueueEmpty(q)) {
        Push(&s, DeQueue(q));
    }

    // 2. 栈 → 队列
    while (!StackEmpty(&s)) {
        EnQueue(q, Pop(&s));
    }
}
