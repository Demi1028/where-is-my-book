#include "LinkList.cpp"

int main(){
    LinkNode *h,*p;
    LinkNode *s,*t,*r;


    char a[] = {'0','0','1','2','0','1','2','1'};
    int n = sizeof(a)/sizeof(a[0]);
    InitList(h);
    CreateListR(h,a,n);
    p = h->next;
    InitList(t);
    InitList(r);
    InitList(s);
    LinkNode *ts,*rs,*ss;
    ts = t;
    rs = r;
    ss = s;


    while(p != NULL){
        LinkNode *b;
        b = (LinkNode *)malloc(sizeof(LinkNode));//创建头结点
        b ->data = p->data;
        b->next = NULL;

        if(p->data == '0'){
            ts->next = b;
            ts = b;
        }else if(p ->data == '1'){
            rs->next = b;
            rs = b;
        }else{
            ss->next = b;
            ss = b;
        }
        p = p->next;
    }
    ts->next = r->next;
    rs->next = s->next;
    ss->next = NULL;
    DispList(t);

    return 1;
}
