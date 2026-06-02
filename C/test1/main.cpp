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

   /* printf("(2)依此插入元素a,b,c,d,e\n");

    ListInsert(L,1,'a');

    ListInsert(L,2,'b');

    ListInsert(L,3,'c');

    ListInsert(L,4,'d');

    ListInsert(L,5,'e');*/

    printf("(3)输出顺序表:");

    DispList(L);

    printf("(4)顺序表L长度：%d\n",ListLength(L));

    printf("(5)顺序表L为%s\n",(ListEmpty(L)?"空":"非空"));

    GetElem(L,3,e);

    printf("（6）顺序表的第三个元素:%c\n",e);

   // printf("实参e = %c\n",e);

    printf("(7)元素a的位置：%d\n",LocateElem(L,'a'));

    printf("(8)在第四个元素的位置上插入元素\n");

    ListInsert(L,4,'f'); DispList(L);

    printf("(9)输出顺序表:");

    printf("(10)删除L的第三个元素\n");

    ListDelete(L,3,e);


    printf("(11)输出顺序表L:");

    DispList(L);

    printf("(12)释放顺序表L\n");

    DestroyList(L);

    return 1;
}
