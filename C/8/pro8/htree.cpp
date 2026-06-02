#include <stdio.h>
#include<string.h>
#define N 50

typedef struct{
    char data[5];
    int weight;
    int parent;
    int rchild;
    int lchild;
}HTNode;

typedef struct{
    char number[N];
    int start;

}HNode;

void CreateHT(HTNode ht[],int n){
    int min1,min2;
    int rnode,lnode,start;
    for(int i = 0;i < 2*n-1;i++){
        ht[i].lchild = ht[i].parent=ht[i].rchild=-1;

    }
    for(int i=0;i < 2*n-1;i++){
        min1 = min2=1000;
        for(int j= 0;j<i;j++){
            if(ht[j].parent == -1){
                if(ht[j].weight<min1){
                    min2 = min1;
                    min1= ht[j].weight;
                    rnode = lnode;
                    lnode = j;
                }else if(ht[j].weight < min2){
                    min2 = ht[j].weight;
                    rnode = j;
                }
            }


        }
        ht[lnode].parent=ht[rnode].parent=i;
        ht[n+i].weight = ht[lnode].weight+ht[rnode].weight;
        ht[n+i].lchild=lnode;ht[n+i].rchild=rnode;
    }
}
