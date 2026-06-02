#include "btree.cpp"

BTNode* CreateBTreeRecur(const char *str, int &i)
{
    if (str[i] == '\0' || str[i] == ')' || str[i] == ',')
        return NULL;

    BTNode *b = (BTNode *)malloc(sizeof(BTNode));
    b->data = str[i++];
    b->lchild = b->rchild = NULL;

    if (str[i] == '(')
    {
        i++;
        b->lchild = CreateBTreeRecur(str, i);

        if (str[i] == ',')
        {
            i++;
            b->rchild = CreateBTreeRecur(str, i);
        }

        if (str[i] == ')')
            i++;
    }

    return b;
}

using namespace std;

int main()
{
    BTNode *b;
    int i=0;
    b = CreateBTreeRecur("X(B(E,Z(G,A)),C(D(Y,J(,K))))",i);
    printf("¶þ²æÊ÷b:");
    DispBTree(b);
    DestroyBTree(b);
    return 0;
}
