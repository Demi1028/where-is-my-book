#include <iostream>
# include "sqstack.cpp"
using namespace std;

int main()
{
    ElemType e;
    SqStack *s;
    InitStack(s);
    char a[] = "a*{b*1/(2-c)+1/(1+d)]-3}";
   if (Match(a, s))
    printf("Æ¥ÅäÕıÈ·\n");
else
    printf("Æ¥Åä´íÎó\n");

    return 0;
}
