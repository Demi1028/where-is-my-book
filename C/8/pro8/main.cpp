#include <stdio.h>
#include <string.h>

#define N 50          // 叶子结点数
#define M 2 * N - 1   // 树中结点总数

typedef struct
{
    char data[5];     // 结点值
    int weight;       // 权重
    int parent;       // 双亲结点
    int lchild;       // 左孩子结点
    int rchild;       // 右孩子结点
} HTNode;

typedef struct
{
    char cd[N];       // 存放哈夫曼编码
    int start;        // ch[start..n]存放哈夫曼编码
} HCode;

// 由 ht 的叶子结点构造完整的哈夫曼树
void CreateHT(HTNode ht[], int n)
{
    int i, k, lnode, rnode;
    int min1, min2;

    // 所有结点的相关域置初值 -1
    for (i = 0; i < 2 * n - 1; i++)
    {
        ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
    }

    // 构造哈夫曼树的分支结点
    for (i = n; i < 2 * n - 1; i++)
    {
        min1 = min2 = 32767;  // min1 和 min2 为最小权重的两个结点位置
        lnode = rnode = -1;

        // 查找最小和次小的结点
        for (k = 0; k <= i - 1; k++)
        {
            // 只在尚未构造二叉树的结点中查找
            if (ht[k].parent == -1)
            {
                if (ht[k].weight < min1)
                {
                    min2 = min1;
                    rnode = lnode;
                    min1 = ht[k].weight;
                    lnode = k;
                }
                else if (ht[k].weight < min2)
                {
                    min2 = ht[k].weight;
                    rnode = k;
                }
            }
        }

        // 合并两个最小和次小的结点
        ht[lnode].parent = i;
        ht[rnode].parent = i;
        ht[i].weight = ht[lnode].weight + ht[rnode].weight;
        ht[i].lchild = lnode;
        ht[i].rchild = rnode;
    }
}

// 由哈夫曼树 ht 构造哈夫曼编码 hcd
void CreateHCode(HTNode ht[], HCode hcd[], int n)
{
    int i, f, c;
    HCode hc;

    // 根据哈夫曼树构造所有叶子结点的哈夫曼编码
    for (i = 0; i < n; i++)
    {
        hc.start = n;
        c = i;
        f = ht[i].parent;

        // 循环直到树根结点
        while (f != -1)
        {
            // 处理左孩子结点
            if (ht[f].lchild == c)
            {
                hc.cd[hc.start--] = '0';
            }
            // 处理右孩子结点
            else
            {
                hc.cd[hc.start--] = '1';
            }
            c = f;
            f = ht[f].parent;
        }
        // start 指向哈夫曼编码最开始字符
        hc.start++;
        hcd[i] = hc;
    }
}

// 输出哈夫曼编码
void DispHCode(HTNode ht[], HCode hcd[], int n)
{
    int i, k;
    int sum = 0, m = 0, j;

    printf("输出哈夫曼编码:\n");
    for (i = 0; i < n; i++)
    {
        j = 0;
        printf("   %s:\t", ht[i].data);
        for (k = hcd[i].start; k <= n; k++)
        {
            printf("%c", hcd[i].cd[k]);
            j++;
        }
        printf("\n");
        m += ht[i].weight;
        sum += ht[i].weight * j;
    }
    printf("\n平均长度 = %g\n", 1.0 * sum / m);
}

int main()
{
    int n = 15, i;
    const char *str[] = {"The", "of", "a", "to", "and", "in", "that", "he", "is", "at", "on", "for", "His", "are", "be"};
    int fnum[] = {1192, 677, 541, 518, 462, 450, 242, 195, 190, 181, 174, 157, 138, 124, 123};
    HTNode ht[M];
    HCode hcd[N];

    for (i = 0; i < n; i++)
    {
        strcpy(ht[i].data, str[i]);
        ht[i].weight = fnum[i];
    }

    CreateHT(ht, n);       // 创建哈夫曼树
    CreateHCode(ht, hcd, n); // 构造哈夫曼编码
    DispHCode(ht, hcd, n);  // 输出哈夫曼编码

    return 0;
}
