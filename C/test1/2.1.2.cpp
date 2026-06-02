#include <iostream>
#include"sqList.cpp"

using namespace std;


int main()
{
    SqList *L;

    ElemType e;

    ElemType arr[] = {'0','0','2','2','2','4','4','5','5','8','8','8'};

    int len = 12;

    InitList(L);



    CreateList(L,arr,len);

    printf("输出顺序表:");

    DispList(L);

    e = L->data[0];

    int j = 0;
/*复用原链表空间*/

    for(int i = 0;i < L->length;i++){
        if(e == L->data[i+1]);
        else{
            j++;
            L->data[j] = L->data[i+1];
            e =  L->data[i+1];

        }
    }

    L->length = j;
/* 复杂度太高
    for(int i = 0;i < L->length-1;){

        if (e == L->data[i+1]){
            ListDelete(L,i+1,e);

            printf("此时e为%c,i = %d\n",e,i);
            printf("%d",L->length);
        }

        else{
                i++;
            e =  L->data[i];


        }



    }*/
    printf("输出无重复元素顺序表:");

    DispList(L);

    return 1;
}
