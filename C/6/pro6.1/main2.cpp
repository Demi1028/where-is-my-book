#include <stdio.h>
#include "btree.cpp"

#define MaxSize 100
typedef char ElemType;

ElemType CommonAncestor(ElemType bt[], int i, int j)
{
    while (i != j)
    {
        if (i > j){
                i = int(i / 2);
                printf("i:%d,j:%d\n",i,j);
        }

        else{
                j = int(j / 2);
                printf("i:%d,j:%d\n",i,j);
        }

    }

    return bt[i];
}

int main()
{
    // 下标从 1 开始存储
    ElemType bt[MaxSize];


    bt[1] = 'A';
    bt[2] = 'B';
    bt[3] = 'C';
    bt[4] = 'D';
    bt[5] = 'E';
    bt[6] = 'F';
    bt[7] = 'G';

    int i = 4, j = 6;

    printf("编号%d和编号%d的最近公共祖先是: %c\n",i, j, CommonAncestor(bt, i, j));

    return 0;
}
