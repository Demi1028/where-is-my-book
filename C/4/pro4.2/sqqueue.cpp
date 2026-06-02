#include <stdio.h>
#include <malloc.h>
#define MaxSize 5

typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
    int count;                     //队首和队尾指针
} SqQueue;                              //声明环形队列类型

void InitQueue(SqQueue *&q)             //初始化队列 q
{
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = 0;
    q -> count = 0;
}

void DestroyQueue(SqQueue *&q)          //销毁队列 q
{
    free(q);
}

bool QueueEmpty(SqQueue *q)            //判断队列 q 是否空
{
    return(q->front == q->rear);
}

bool enQueue(SqQueue *&q, ElemType e)  //进队
{
    if(q -> count == MaxSize-1){
        return false;
    }
    int rear2 = (q ->front +q ->count)%MaxSize;
    q->data[rear2] = e;
    q ->count ++;
    return true;
}

bool deQueue(SqQueue *&q, ElemType &e) //出队
{
    if (q->count == 0)
        return false;                   //队空,下溢出,返回假
    q->front = (q->front + 1) % MaxSize;
    e = q->data[q->front];
    q ->count--;
    return true;
}
