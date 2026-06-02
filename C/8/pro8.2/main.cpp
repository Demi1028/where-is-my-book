
#include "btree.cpp"


void CountLevel(HTNode ht[], int root, int level, int count[])
{
    if (root == -1)
        return;

    count[level]++;

    CountLevel(ht, ht[root].lchild, level + 1, count);
    CountLevel(ht, ht[root].rchild, level + 1, count);
}
void DispLevelCount(HTNode ht[], int n)
{
    int count[100] = {0};

    int root = 2 * n - 2;

    CountLevel(ht, root, 1, count);

    for (int i = 1; i < 100; i++)
    {
        if (count[i] != 0)
        {
            printf("第%d层结点个数: %d\n", i, count[i]);
        }
    }
}
int main()
{
    int n = 15, i;
    const char *str[] = {"The", "of", "a", "to", "and", "in", "that", "he", "is", "at", "on", "for", "His", "are", "be"};
    int fnum[] = {1192, 677, 541, 518, 462, 450, 242, 195, 190, 181, 174, 157, 138, 124, 123};
    HTNode ht[M];

    for (i = 0; i < n; i++)
    {
        strcpy(ht[i].data, str[i]);
        ht[i].weight = fnum[i];
    }

    CreateHT(ht, n);

    DispLevelCount(ht, n);

    return 0;
}
