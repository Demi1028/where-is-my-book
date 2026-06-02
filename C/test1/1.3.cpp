#include <iostream>
#include"sqList.cpp"

using namespace std;

int main()
{
    SqList *L;

    ElemType e;

    printf("顺序表的基本运算如下：\n");

    printf("（1）初始化顺序表\n");

    InitList(L);

    printf("(2)创建元素顺序表\n");

    char s[] = {'a','b','c','d','e'};

    printf("主函数实参s[0] = %c\n",s[0]);


    CreateList(L,s,5);


    return 1;
}
