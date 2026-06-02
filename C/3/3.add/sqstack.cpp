#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int top;                    //栈顶指针
} SqStack;                       //声明顺序栈类型
void InitStack(SqStack *&s)      //初始化顺序栈
{
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
}
void DestroyStack(SqStack *&s)   //销毁顺序栈
{
    free(s);
}
bool StackEmpty(SqStack *s)      //判断栈空否
{
    return(s->top == -1);
}

bool Push(SqStack *&s,ElemType e)    //进栈
{
    if (s->top == MaxSize - 1)       //栈满的情况,即栈上溢出
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}
bool Pop(SqStack *&s,ElemType &e)    //出栈
{
    if (s->top == -1)                //栈为空的情况,即栈下溢出
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}
bool GetTop(SqStack *s,ElemType &e)  //取栈顶元素
{
    if (s->top == -1)                //栈为空的情况,即栈下溢出
        return false;
    e = s->data[s->top];
    return true;
}
bool Match(char str[],SqStack *s)
{

    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        switch (ch)
        {
        case '(':
        case '[':
        case '{':
            Push(s, ch);
            break;

        case ')':
        case ']':
        case '}':
        {
            if (StackEmpty(s))
                return false;

            char top;
            GetTop(s, top);

            if ((ch == ')' && top == '(') ||
                (ch == ']' && top == '[') ||
                (ch == '}' && top == '{'))
            {
                Pop(s, top); // 匹配成功 → 出栈
            }
            else
            {
                printf("%c 不匹配\n", ch);
                return false;
            }
            break;
        }

        default:
            break;
        }
    }


    if (StackEmpty(s))
        return true;
    else
        return false;
}
